#include <cstring>
#include "MovieDirectorSimulator.h"


MovieDirectorSimulator::MovieDirectorSimulator() : App(1024, 768),
                                                   mb_cullface(true),
                                                   mb_wireframe(false),
                                                   b_draw_grid(true),
                                                   b_draw_axe(true) {
    directorCamera = new DirectorCamera(Translation(0, 5, 0), -20);
    ground = new Ground();
    if (SDL_IsGameController(0)) {
        std::cout << "Gamepad detected\n";
        gamepads.create();
    } else {
        std::cout << "Warning : No Gamepad detected\n";
    }
    textWidget = create_widgets();

}

MovieDirectorSimulator::~MovieDirectorSimulator() {
    for (auto p:gameCharacters) {
        delete p;
        p = nullptr;
    }
    delete directorCamera;
    directorCamera = nullptr;
    delete ground;
    ground = nullptr;
    release_widgets(textWidget);
}

int MovieDirectorSimulator::init() {
    SDL_SetWindowTitle(m_window, "Movie Director Simulator 2019");
    int major = 0;
    int minor = 0;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    m_world.setParticlesCount(10);
    // Add some software and hardware informations
    /*
    std::cout << "OpenGL version " << major << " " << minor << "\n";
    const GLubyte *txt;

    txt = glGetString(GL_VENDOR);
    if (txt) std::cout << "OpenGl Vendor " << (const char *) txt << "\n";

    txt = glGetString(GL_RENDERER);
    if (txt) std::cout << "OpenGl Renderer " << (const char *) txt << "\n";

    txt = glGetString(GL_VERSION);
    if (txt) std::cout << "OpenGl Version " << (const char *) txt << "\n";

    txt = glGetString(GL_SHADING_LANGUAGE_VERSION);
    if (txt)
        std::cout << "OpenGl Shading Language Version " << (const char *) txt
                  << "\n";
    */

    // etat par defaut openGL
    glClearColor(0.3f, 0.3f, 0.7f, 1);
    //glClearDepthf(1);
    //glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    //glDisable(GL_CULL_FACE);

    //glFrontFace(GL_CCW);
    //glCullFace(GL_BACK);

    /*if (mb_cullface) {
        glEnable(GL_CULL_FACE);
    } else {
        // good for debug
        glDisable(GL_CULL_FACE);
    }
    glEnable(GL_TEXTURE_2D);
    */

    m_frameNumber = 0;

    gameCharacters = std::vector<GameCharacter *>(num);

    initColors();
    for (int i = 0; i < num; ++i) {
        /*if (i == 0) {
            gameCharacters[i] = new GameCharacter(false, "");
        } else {*/
        gameCharacters[i] = new GameCharacter(true, colors[i % num].first,
                                              colors[i % num].second);
        gameCharacters[i]->setOffset(
                Translation(rand() % 400 - 200, 0, rand() % 400 - 200));
        //}
    }

    return 1;
}

int MovieDirectorSimulator::render() {
    // Efface l'ecran
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Deplace la camera, lumiere, etc.
    manageCameraLight();
    // donne notre camera au shader
    gl.camera(m_camera);

    // Affiche le personnage principal

    for (auto character : gameCharacters) {
        character->draw(&m_camera);
    }
    directorCamera->draw(&m_camera);
    ground->draw(&m_camera);

    begin(textWidget);
    label(textWidget, "Bienvenue dans Movie Director Simulator");
    begin_line(textWidget);
    label(textWidget, "Pour jouer il vous faudra une manette.");
    begin_line(textWidget);
    label(textWidget, "Utilisez les joystick pour vous deplacer et tourner.");
    begin_line(textWidget);
    label(textWidget,
          "Le bouton Y permet de passer du mode 3ème personne au mode premiere personne.");
    begin_line(textWidget);
    label(textWidget,
          "Le bouton X permet d'avoir une aide visuelle sur ce que voit la camera");
    begin_line(textWidget);
    label(textWidget, "Vous devez filmer le joueur '%s'",
          gameCharacters[playerCible]->getColorName());
    begin_line(textWidget);
    label(textWidget, "Votre score est de : '%lf'", score);
    end(textWidget);
    draw(textWidget, window_width(), window_height());

    return 1;
}

void MovieDirectorSimulator::manageCameraLight() {
    const float step = m_camera.radius() * 0.005f;

    // (De)Active la grille / les axes
    //if (key_state('h')) help();
    /*
    if (key_state('c')) {
        clear_key_state('c');
        mb_cullface = !mb_cullface;
        if (mb_cullface) glEnable(GL_CULL_FACE); else glDisable(GL_CULL_FACE);
    }
    if (key_state('w')) {
        clear_key_state('w');
        mb_wireframe = !mb_wireframe;
        if (mb_wireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    if (key_state('g')) {
        b_draw_grid = !b_draw_grid;
        clear_key_state('g');
    }
    if (key_state('a')) {
        b_draw_axe = !b_draw_axe;
        clear_key_state('a');
    }

    // AXE et GRILLE
    gl.model(Scale(10. * step, 10.0 * step, 10.0 * step));
    if (b_draw_grid) gl.draw(m_grid);
    if (b_draw_axe) gl.draw(m_axe);*/
}

int MovieDirectorSimulator::update(const float time, const float delta) {

    gamepadInput(delta);

    if (playerCible == -1 || timer > 5000) {
        timer = 0;
        playerCible = rand() % num;
    }
    timer += delta;
    for (int i = 0; i < num; ++i) {
        gameCharacters[i]->update(delta / 1000);
        if (i == playerCible) {
            if (isInTheCameraView(i)) {
                if(!directorCamera->getIsInCameraView()){
                    directorCamera->changeIsInCameraView();
                }
                score++;
            } else {
                if (static_cast<int>(floor(score)) - 1 % 100 > 0) {
                    if(directorCamera->getIsInCameraView()){
                        directorCamera->changeIsInCameraView();
                    }
                    score -= 0.1;
                }
            }
        }
    }
    directorCamera->update(delta);

    m_world.update(0.1f);
    return 0;
}


void MovieDirectorSimulator::gamepadInput(const float dt) {
    if (gamepads.pads() > 0) {
        gamepads.update();
        if (gamepads.button(0, SDL_CONTROLLER_BUTTON_A) == 1) {
            //std::cout << "bouton A\n";
        }
        if (gamepads.button(0, SDL_CONTROLLER_BUTTON_B) == 1) {
            //std::cout << "bouton B\n";
        }
        if (gamepads.button(0, SDL_CONTROLLER_BUTTON_X) == 1) {
            directorCamera->changeHelp();
        }
        if (gamepads.button(0, SDL_CONTROLLER_BUTTON_Y) == 1) {
            FPSView = !FPSView;
        }
        if (gamepads.axis(0, SDL_CONTROLLER_AXIS_LEFTX) <= -0.5) {
            directorCamera->moveLeft();
        }
        if (gamepads.axis(0, SDL_CONTROLLER_AXIS_LEFTX) >= 0.5) {
            directorCamera->moveRight();
        }
        if (gamepads.axis(0, SDL_CONTROLLER_AXIS_LEFTY) <= -0.5) {

            directorCamera->moveForward();
        }
        if (gamepads.axis(0, SDL_CONTROLLER_AXIS_LEFTY) >= 0.5) {
            directorCamera->moveBackward();
        }
        if (gamepads.axis(0, SDL_CONTROLLER_AXIS_RIGHTX) >= 0.5) {
            directorCamera->rotateRight();
            //gameCharacters[0]->setControllerMatrix(directorCamera->getMatrix());
        }
        if (gamepads.axis(0, SDL_CONTROLLER_AXIS_RIGHTX) <= -0.5) {
            directorCamera->rotateLeft();
            //gameCharacters[0]->setControllerMatrix(directorCamera->getMatrix());
        }
        if (gamepads.axis(0, SDL_CONTROLLER_AXIS_RIGHTY) <= -0.5) {
            directorCamera->rotateUp();
        }
        if (gamepads.axis(0, SDL_CONTROLLER_AXIS_RIGHTY) >= 0.5) {
            directorCamera->rotateDown();
        }
    } else {
        if (key_state('q')) {
            directorCamera->moveLeft();
        }
        if (key_state('d')) {
            directorCamera->moveRight();
        }
        if (key_state('z')) {
            directorCamera->moveForward();
        }
        if (key_state('s')) {
            directorCamera->moveBackward();
        }
        if (key_state('l')) {
            directorCamera->rotateRight();
        }
        if (key_state('j')) {
            directorCamera->rotateLeft();
        }
        if (key_state('i')) {
            directorCamera->rotateUp();
        }
        if (key_state('k')) {
            directorCamera->rotateDown();
        }
        if (key_state('v')) {
            FPSView = !FPSView;
        }
        if (key_state('c')) {
            directorCamera->changeHelp();
        }
    }
    //std::cout << directorCamera->getPosition() << "\n";
    Point newCameraPosition = directorCamera->getPosition();
    if (!FPSView) {
        newCameraPosition.x -= 5;
        newCameraPosition.y += 3;
        newCameraPosition.z -= 5;
        m_camera.lookat(newCameraPosition, 100);
        m_camera.rotation(directorCamera->getYRotation(),
                          directorCamera->getXRotation());
        m_camera.move(50);
    } else {
        m_camera.lookat(newCameraPosition, 50);
        m_camera.rotation(directorCamera->getYRotation(),
                          directorCamera->getXRotation());
        // Value by testing
        m_camera.move(100);
    }
    newCameraPosition.y += 20;
    newCameraPosition.z += 10;
    gl.light(newCameraPosition);
}

bool MovieDirectorSimulator::isInTheCameraView(unsigned int characterIndex) {
    Point characterPosition =
            gameCharacters[characterIndex]->getPosition() / 10;
    // Point par rapport au centre du petit carré de la caméra
    Point characterPositionInCamera = (directorCamera->getAllTransform().inverse())(
            characterPosition);
    //std::cout << gameCharacters[characterIndex]->getColorName() << " "
    //          << characterPositionInCamera << " : ";
    if (characterPositionInCamera.z > 0 || characterPositionInCamera.z < -20) {
        //std::cout << "prof pas ok\n";
        // Hors du champ de profondeur de la camera
        return false;
    } else if (abs(characterPositionInCamera.x) <
               (abs(characterPositionInCamera.z) / 2) &&
               abs(characterPositionInCamera.x) >= 0) {
        //std::cout << "large ok\n";
        // Dans du champ de largeur de la camera
        return true;
    } else {
        //std::cout << "large pas ok\n";
        return false;
    }

}