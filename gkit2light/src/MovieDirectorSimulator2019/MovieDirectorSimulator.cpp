#include "MovieDirectorSimulator.h"

MovieDirectorSimulator::MovieDirectorSimulator() : App(1024, 768),
                                                   mb_cullface(true),
                                                   mb_wireframe(false),
                                                   b_draw_grid(true),
                                                   b_draw_axe(true) {}

int MovieDirectorSimulator::init() {
    SDL_SetWindowTitle(m_window, "Movie Director Simulator 2019");

    int major = 0;
    int minor = 0;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    m_world.setParticlesCount(10);
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

    // etat par defaut openGL
    glClearColor(0.5f, 0.5f, 0.9f, 1);
//    glClearDepthf(1);
    //glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
//    glFrontFace(GL_CCW);
//    glCullFace(GL_BACK);
//
//    if (mb_cullface)
//        glEnable(GL_CULL_FACE);
//    else
//        glDisable(GL_CULL_FACE);        // good for debug
//    //glEnable(GL_TEXTURE_2D);
//
//    //glEnable (GL_BLEND);
//    //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    m_camera.lookat(Point(0, 0, 0), 30);
    gl.light(Point(0, 20, 20), White());

    init_axe();
    init_grid();
    init_quad();
    init_cube();
    init_sphere();
    init_cone();
    init_cylinder();

	m_bvh.init("data/bvh/danse.bvh");
    //m_bvh.init(smart_path("data/bvh/motionFSM/avatar_kick_roundhouse_R.bvh"));

    m_frameNumber = 0;
    m_ske.init(m_bvh);
    m_ske.setPose(m_bvh, -1);// met le skeleton a la pose au repos


    characterSkeleton = std::vector<Skeleton>(5);
    characterController = std::vector<CharacterController>(5);

    for(int i = 0; i < 5; i++) {
    	characterSkeleton[i].init(*characterController[i].getAnim());
    	characterSkeleton[i].setPose(*characterController[i].getAnim(), -1);
    	
	}
    return 1;
}


void MovieDirectorSimulator::help() {
    printf("HELP:\n");
    printf("\th: help\n");
    printf("\tc: (des)active GL_CULL_FACE\n");
    printf("\tw: (des)active wireframe\n");
    printf("\ta: (des)active l'affichage de l'axe\n");
    printf("\tg: (des)active l'affichage de la grille\n");
    printf("\tz: (des)active l'affichage de la courbe d'animation\n");
    printf("\tfleches/pageUp/pageDown: bouge la cam�ra\n");
    printf("\tCtrl+fleche/pageUp/pageDown: bouge la source de lumi�re\n");
    printf("\tSouris+bouton gauche: rotation\n");
    printf("\tSouris mouvement vertical+bouton droit: (de)zoom\n");
}

void MovieDirectorSimulator::draw_skeleton(Vector v, const Skeleton &, const Transform offset) {

    for (int i = 1; i < m_ske.numberOfJoint(); ++i) {
        draw_cylinder(v, offset(m_ske.getJointPosition(i)),
                      offset(m_ske.getJointPosition(m_ske.getParentId(i))), 1);
    }
}

void MovieDirectorSimulator::draw_character(Vector v, const Skeleton &) {
	for(int j = 0; j < 5; j++) {
	    for (int i = 1; i < characterSkeleton[j].numberOfJoint(); ++i) {
	        Transform animCorrection = *characterController[j].getAnimCorrection();
	        Point point1 = (characterController[j].getMatChar() * animCorrection)(
	                characterSkeleton[j].getJointPosition(i));
	        Point point2 = (characterController[j].getMatChar() * animCorrection)(
	                characterSkeleton[j].getJointPosition(
	                        characterSkeleton[j].getParentId(i)));
	        draw_cylinder(v, point1/10, point2/10, 0.1);
	    }
	}
}

void MovieDirectorSimulator::draw_cylinder(const Transform &T) {
    gl.model(T);
    gl.draw(m_cylinder);
    Transform Tch = T * Translation(0, 1, 0);
    gl.model(Tch);
    gl.draw(m_cylinder_cover);

    //Transform Tcb = T  * Translation( 0, -1, 0);
    Transform Tcb = T * Translation(0, 0, 0) * Rotation(Vector(1, 0, 0), 180);
    gl.model(Tcb);
    gl.draw(m_cylinder_cover);
}


void MovieDirectorSimulator::draw_cylinder(Vector v, const Point &a, const Point &b, float r) {
    Vector ab = b - a;
    Vector p, y, z;
    Vector abn = normalize(ab);
    float lab = length(ab);
    if (lab < 0.00001f) return;
    if (fabs(ab.x) > 0.25f)
        p = Vector(0, 1, 0);
    else
        p = Vector(1, 0, 0);

    y = cross(abn, p);
    y = normalize(y);
    z = cross(abn, y);
    //Transform T(z, abn, y, Vector(0, 0, 0));
    Transform T(z, abn, y, v);
    /*
    for(int i = 0; i < 5; i++){
    	if(i == 0) {
    		Transform T(z, abn, y,Vector(5, 0, -5));
    	 	draw_cylinder(Translation(Vector(a)) * T * Scale(r, lab, r));
    	}else if (i == 1) {
    		Transform T(z, abn, y,Vector(10, 0, 0));
    	 	draw_cylinder(Translation(Vector(a)) * T * Scale(r, lab, r));
    	}else if (i == 2) {
    		Transform T(z, abn, y,Vector(0, 0, 0));
    	 	draw_cylinder(Translation(Vector(a)) * T * Scale(r, lab, r));
    	}else if (i == 3) {
    		Transform T(z, abn, y,Vector(-7, 0, 3));
    	 	draw_cylinder(Translation(Vector(a)) * T * Scale(r, lab, r));
    	}
    }
	*/

    //cout << T[0] << endl;
    //cout << T[1] << endl;
    //cout << T[2] << endl;
    //cout << T[3] << endl;

    draw_cylinder(Translation(Vector(a)) * T * Scale(r, lab, r));

}

void MovieDirectorSimulator::draw_sphere(const Point &a, float r) {
    draw_sphere(Translation(Vector(a)) * Scale(r, r, r));
}


void MovieDirectorSimulator::draw_sphere(const Transform &T) {
    gl.model(T);
    gl.draw(m_sphere);
}

void MovieDirectorSimulator::draw_cube(const Transform &T) {
    gl.lighting(true);
    gl.texture(0);
    gl.model(T);
    gl.draw(m_cube);
}

int MovieDirectorSimulator::render() {
    // Efface l'ecran
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Deplace la camera, lumiere, etc.
    manageCameraLight();

    // donne notre camera au shader
    gl.camera(m_camera);

    // Affiche le personnage principal
    
    for(int i = 0; i < 5; i++) {
		draw_character(Vector(i*3, 0, i+2), characterSkeleton[i]);
    }
    

/*
    gl.lighting(true);
    gl.texture(0);
    gl.model(Translation(0, 0, 0));
    gl.draw(m_sphere);
    gl.model(Translation(2, 0, 0));
    gl.draw(m_sphere);

    gl.lighting(true);
    gl.texture(0);
    Vector posInit(0,5,0);
    Vector scaleInit(1,1,1);
    gl.model(Translation(posInit)*Scale(scaleInit.x, scaleInit.y, scaleInit.z));
    gl.draw(m_quad);

    int distMax = 7;
    Vector posMax(posInit.x, posInit.y, posInit.z+distMax);
    Vector scaleMax(scaleInit.x*distMax, scaleInit.y*distMax, scaleInit.z);
    gl.model(Translation(posMax)*Scale(scaleMax.x, scaleMax.y, scaleMax.z));
    gl.draw(m_quad);
*/
    return 1;
}

void MovieDirectorSimulator::manageCameraLight() {
    // recupere les mouvements de la souris pour deplacer la camera, cf tutos/tuto6.cpp
    int mx, my;
    unsigned int mb = SDL_GetRelativeMouseState(&mx, &my);
    // deplace la camera
    if ((mb & SDL_BUTTON(1)) &&
        (mb & SDL_BUTTON(3)))                 // le bouton du milieu est enfonce
        m_camera.translation((float) mx / (float) window_width(), (float) my /
                                                                  (float) window_height());         // deplace le point de rotation
    else if (mb &
             SDL_BUTTON(1))                      // le bouton gauche est enfonce
        m_camera.rotation(mx, my);       // tourne autour de l'objet
    else if (mb & SDL_BUTTON(3))                 // le bouton droit est enfonce
        m_camera.move(my);               // approche / eloigne l'objet
    if (key_state(SDLK_PAGEUP) && (!key_state(SDLK_LCTRL)) &&
        (!key_state(SDLK_LALT))) { m_camera.translation(0, 0.01); }
    if (key_state(SDLK_PAGEDOWN) && (!key_state(SDLK_LCTRL)) &&
        (!key_state(SDLK_LALT))) { m_camera.translation(0, -0.01); }
    if (key_state(SDLK_LEFT) && (!key_state(SDLK_LCTRL)) &&
        (!key_state(SDLK_LALT))) { m_camera.translation(0.01, 0); }
    if (key_state(SDLK_RIGHT) && (!key_state(SDLK_LCTRL)) &&
        (!key_state(SDLK_LALT))) { m_camera.translation(-0.01, 0); }
    if (key_state(SDLK_UP) && (!key_state(SDLK_LCTRL)) &&
        (!key_state(SDLK_LALT))) { m_camera.move(1); }
    if (key_state(SDLK_DOWN) && (!key_state(SDLK_LCTRL)) &&
        (!key_state(SDLK_LALT))) { m_camera.move(-1); }


    // Deplace la lumiere
    const float step = m_camera.radius() * 0.005f;
    if (key_state(SDLK_RIGHT) && key_state(SDLK_LCTRL)) {
        gl.light(gl.light() + Vector(step, 0, 0));
    }
    if (key_state(SDLK_LEFT) && key_state(SDLK_LCTRL)) {
        gl.light(gl.light() + Vector(-step, 0, 0));
    }
    if (key_state(SDLK_UP) && key_state(SDLK_LCTRL)) {
        gl.light(gl.light() + Vector(0, 0, -step));
    }
    if (key_state(SDLK_DOWN) && key_state(SDLK_LCTRL)) {
        gl.light(gl.light() + Vector(0, 0, step));
    }
    if (key_state(SDLK_PAGEUP) && key_state(SDLK_LCTRL)) {
        gl.light(gl.light() + Vector(0, step, 0));
    }
    if (key_state(SDLK_PAGEDOWN) && key_state(SDLK_LCTRL)) {
        gl.light(gl.light() + Vector(0, -step, 0));
    }

    // (De)Active la grille / les axes
    if (key_state('h')) help();
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

    gl.camera(m_camera);
    //draw(m_cube, Translation( Vector( gl.light()))*Scale(0.3, 0.3, 0.3), m_camera);
    //draw_param.texture(quad_texture).camera(camera).model(Translation( 3, 5, 0 )).draw(quad);

    // AXE et GRILLE
    gl.model(Scale(10. * step, 10.0 * step, 10.0 * step));
    if (b_draw_grid) gl.draw(m_grid);
    if (b_draw_axe) gl.draw(m_axe);

    //  LIGHT
    gl.texture(0);
    gl.lighting(false);
    gl.model(Translation(Vector(gl.light())) * Scale(step, step, step));
    gl.draw(m_cube);
    gl.lighting(true);
}

void MovieDirectorSimulator::init_axe() {
    m_axe = Mesh(GL_LINES);
    m_axe.color(Color(1, 0, 0));
    m_axe.vertex(0, 0, 0);
    m_axe.vertex(1, 0, 0);

    m_axe.color(Color(0, 1, 0));
    m_axe.vertex(0, 0, 0);
    m_axe.vertex(0, 1, 0);

    m_axe.color(Color(0, 0, 1));
    m_axe.vertex(0, 0, 0);
    m_axe.vertex(0, 0, 1);
}

void MovieDirectorSimulator::init_grid() {
    m_grid = Mesh(GL_LINES);

    m_grid.color(Color(1, 1, 1));
    int i, j;
    for (i = -5; i <= 5; ++i)
        for (j = -5; j <= 5; ++j) {
            m_grid.vertex(-5, 0, j);
            m_grid.vertex(5, 0, j);

            m_grid.vertex(i, 0, -5);
            m_grid.vertex(i, 0, 5);

        }
}

void MovieDirectorSimulator::init_quad() {
    m_quad = Mesh(GL_TRIANGLE_STRIP);
    m_quad.color(Color(1, 1, 1));

    m_quad.normal(0, 0, 1);

    m_quad.texcoord(0, 0);
    m_quad.vertex(-1, -1, 0);

    m_quad.texcoord(1, 0);
    m_quad.vertex(1, -1, 0);

    m_quad.texcoord(0, 1);
    m_quad.vertex(-1, 1, 0);

    m_quad.texcoord(1, 1);
    m_quad.vertex(1, 1, 0);
}

void MovieDirectorSimulator::init_cube() {
    //                          0           1           2       3           4           5       6           7
    static float pt[8][3] = {{-1, -1, -1},
                             {1,  -1, -1},
                             {1,  -1, 1},
                             {-1, -1, 1},
                             {-1, 1,  -1},
                             {1,  1,  -1},
                             {1,  1,  1},
                             {-1, 1,  1}};
    static int f[6][4] = {{0, 1, 2, 3},
                          {5, 4, 7, 6},
                          {2, 1, 5, 6},
                          {0, 3, 7, 4},
                          {3, 2, 6, 7},
                          {1, 0, 4, 5}};
    static float n[6][3] = {{0,  -1, 0},
                            {0,  1,  0},
                            {1,  0,  0},
                            {-1, 0,  0},
                            {0,  0,  1},
                            {0,  0,  -1}};
    int i;

    m_cube = Mesh(GL_TRIANGLE_STRIP);
    m_cube.color(Color(1, 1, 1));

    for (i = 0; i < 6; i++) {
        m_cube.normal(n[i][0], n[i][1], n[i][2]);

        m_cube.texcoord(0, 0);
        m_cube.vertex(pt[f[i][0]][0], pt[f[i][0]][1], pt[f[i][0]][2]);

        m_cube.texcoord(1, 0);
        m_cube.vertex(pt[f[i][1]][0], pt[f[i][1]][1], pt[f[i][1]][2]);

        m_cube.texcoord(0, 1);
        m_cube.vertex(pt[f[i][3]][0], pt[f[i][3]][1], pt[f[i][3]][2]);

        m_cube.texcoord(1, 1);
        m_cube.vertex(pt[f[i][2]][0], pt[f[i][2]][1], pt[f[i][2]][2]);

        m_cube.restart_strip();
    }
}

void MovieDirectorSimulator::init_sphere() {
    const int divBeta = 26;
    const int divAlpha = divBeta / 2;
    int i, j;
    float beta, alpha, alpha2;

    m_sphere = Mesh(GL_TRIANGLE_STRIP);

    m_sphere.color(Color(1, 1, 1));

    for (i = 0; i < divAlpha; ++i) {
        alpha = -0.5f * M_PI + float(i) * M_PI / divAlpha;
        alpha2 = -0.5f * M_PI + float(i + 1) * M_PI / divAlpha;

        for (j = 0; j < divBeta; ++j) {
            beta = float(j) * 2.f * M_PI / (divBeta - 1);

            m_sphere.texcoord(beta / (2.0f * M_PI), 0.5f + alpha / M_PI);
            m_sphere.normal(Vector(cos(alpha) * cos(beta), sin(alpha),
                                   cos(alpha) * sin(beta)));
            m_sphere.vertex(Point(cos(alpha) * cos(beta), sin(alpha),
                                  cos(alpha) * sin(beta)));

            m_sphere.texcoord(beta / (2.0f * M_PI), 0.5f + alpha2 / M_PI);
            m_sphere.normal(Vector(cos(alpha2) * cos(beta), sin(alpha2),
                                   cos(alpha2) * sin(beta)));
            m_sphere.vertex(Point(cos(alpha2) * cos(beta), sin(alpha2),
                                  cos(alpha2) * sin(beta)));

        }

        m_sphere.restart_strip();
    }
}

void MovieDirectorSimulator::init_cone() {
    int i;
    const int div = 25;
    float alpha;
    float step = 2.0 * M_PI / (div);

    m_cone.color(Color(1, 1, 1));

    m_cone = Mesh(GL_TRIANGLE_STRIP);

    for (i = 0; i <= div; ++i) {
        alpha = i * step;

        m_cone.normal(Vector(cos(alpha) / sqrtf(2.f), 1.f / sqrtf(2.f),
                             sin(alpha) / sqrtf(2.f)));

        m_cone.texcoord(float(i) / div, 0.f);
        m_cone.vertex(Point(cos(alpha), 0, sin(alpha)));

        m_cone.texcoord(float(i) / div, 1.f);
        m_cone.vertex(Point(0, 1, 0));

    }
}

void MovieDirectorSimulator::init_cylinder() {
    int i;
    const int div = 25;
    float alpha;
    float step = 2.0 * M_PI / (div);

    m_cylinder = Mesh(GL_TRIANGLE_STRIP);

    for (i = 0; i <= div; ++i) {
        alpha = i * step;
        m_cylinder.normal(Vector(cos(alpha), 0, sin(alpha)));
        m_cylinder.texcoord(float(i) / div, 0.f);
        m_cylinder.vertex(Point(cos(alpha), 0, sin(alpha)));

        m_cylinder.normal(Vector(cos(alpha), 0, sin(alpha)));
        m_cylinder.texcoord(float(i) / div, 1.f);
        m_cylinder.vertex(Point(cos(alpha), 1, sin(alpha)));
    }

    m_cylinder_cover = Mesh(GL_TRIANGLE_FAN);

    m_cylinder_cover.normal(Vector(0, 1, 0));

    m_cylinder_cover.vertex(Point(0, 0, 0));
    for (i = 0; i <= div; ++i) {
        alpha = -i * step;
        m_cylinder_cover.vertex(Point(cos(alpha), 0, sin(alpha)));
    }
}

int MovieDirectorSimulator::update(const float time, const float delta) {
	if (key_state('n')) {
        m_frameNumber++;
        std::cout << m_frameNumber << '\n';
    }
    if (key_state('b')) {
        --m_frameNumber;
        std::cout << m_frameNumber << '\n';
    }
    m_ske.setPose(m_bvh, m_frameNumber);

    for(int i = 0; i < 5; i++) {
    	cubeController.update(delta / 1000);
    	characterController[i].update(delta / 1000);
    	characterSkeleton[i].setPose(*characterController[i].getAnim(),
                              characterController[i].getFrameAnim());

    }

    m_world.update(0.1f);
    return 0;
}