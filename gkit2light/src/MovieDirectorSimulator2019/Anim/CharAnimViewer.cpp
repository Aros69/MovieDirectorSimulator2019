
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>

#include "CharAnimViewer.h"

using namespace std;
using namespace chara;


CharAnimViewer *CharAnimViewer::psingleton = NULL;


CharAnimViewer::CharAnimViewer() : Viewer(), m_frameNumber(0) {
    psingleton = this;
}


int CharAnimViewer::init() {
    Viewer::init();
    cout << "==>master_CharAnim/CharAnimViewer" << endl;
    m_camera.lookat(Point(0, 100, 10), 1000);
    gl.light(Point(300, 300, 300));

    b_draw_grid = false;

    m_world.setParticlesCount(10);

    init_cylinder();
    init_sphere();


    m_bvh.init("data/bvh/danse.bvh");
    //m_bvh.init(smart_path("data/bvh/motionFSM/avatar_kick_roundhouse_R.bvh"));

    m_frameNumber = 0;

    /*
    cout << endl << "========================" << endl;
    cout << "BVH decription" << endl;
    cout << m_bvh << endl;
    cout << endl << "========================" << endl;
     */

    m_ske.init(m_bvh);
    m_ske.setPose(m_bvh, -1);// met le skeleton a la pose au repos

    characterSkeleton.init(*characterController.getAnim());
    characterSkeleton.setPose(*characterController.getAnim(), -1);

    return 0;
}


void CharAnimViewer::draw_skeleton(const Skeleton &, const Transform offset) {

    for (int i = 1; i < m_ske.numberOfJoint(); ++i) {
        draw_cylinder(offset(m_ske.getJointPosition(i)),
                      offset(m_ske.getJointPosition(m_ske.getParentId(i))), 1);
    }
}

void CharAnimViewer::draw_character(const Skeleton &) {
    for (int i = 1; i < characterSkeleton.numberOfJoint(); ++i) {
        Transform animCorrection = *characterController.getAnimCorrection();
        Point point1 = (characterController.getMatChar() * animCorrection)(
                characterSkeleton.getJointPosition(i));
        Point point2 = (characterController.getMatChar() * animCorrection)(
                characterSkeleton.getJointPosition(
                        characterSkeleton.getParentId(i)));
        draw_cylinder(point1, point2, 1);
    }
}


int CharAnimViewer::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //draw_quad(RotationX(-90) * Scale(500, 500, 1));

    Viewer::manageCameraLight();
    gl.camera(m_camera);

    //m_world.draw();

    // Affiche le skeleton
    const Transform offsetSkeleton = Translation(-100, 0, 0);
    draw_skeleton(m_ske, offsetSkeleton);

    // Affiche le personnage Controlle
    const Transform offsetSphere = Translation(-50, 0, 0);
    draw_sphere(offsetSphere(cubeController.getCharacterPosition()), 11);
    draw_cube(offsetSphere * cubeController.getMatChar() * Scale(10, 10, 10));
    draw_character(characterSkeleton);

    // Display for time base update (benchmark independant)
    /* draw_sphere(testTransform); */

    /*const int MAX = 5;
    float A[] = { -10, -20, -30, -40, -50 };
    float B[] = { -15, -10, 0, 10, 45 };
    float C[] = { -55, -30, 20, -30, -45 };

    static int t = 0;
    t = (t + 1) % MAX;
    float c = 0.5;
    float a = (1-c) * A[t] + c*A[(t+1)%MAX];
    float b = B[t];
    float ac = C[t];

    Transform S = Scale(10, 100, 10);
    Transform A2W = RotationZ(a);
    draw_cylinder( A2W*S );

    Transform B2A = Translation(0, 100, 0) * RotationZ( b);
    Transform B2W = A2W * B2A;
    draw_cylinder(  B2W*S);

    Transform C12B = Translation(0, 100, 0) * RotationZ(ac);
    Transform C12W = B2W * C12B;
    Transform S1 = Scale(6, 30, 6);
    draw_cylinder(C12W*S1);

    Transform C22B = Translation(0, 100, 0) * RotationZ(-ac);
    Transform C22W = B2W * C22B;
    draw_cylinder(C22W*S1);*/


    //draw_cylinder(Point(0, 0, 0), Point(0, 100, 0), 20);
    //draw_cylinder()
    //draw_sphere()

    return 1;
}

void commande() {
    std::cout
            << "Bienvenue dans cette application d'animation de bonhomme en baton!\n"
            << "Voici les commandes :\n"
            << "- 'n' permet de faire avancer le temps du grand squelette a gauche pour visionner son animation\n"
            << "- 'b' permet de faire reculer le temps du squelette (attention à ne pas descendre en dessous de 0 sinon c'est bizarre)\n"
            << "- 'z', 'q', 's' et 'd' permettent de faire bouger le bonhomme au centre ainsi que la sphere/cube derriere lui\n"
            << "- 'x' permet de donner un coup de pied et afficher des informations sur la sphere/cube\n"
            << "- 'left shift' permet de s'accroupir et de se deplacer plus doucement (si combine avec zqsd)\n"
            << "- '1', '2', '3' permettent de danser si vous ne bouger pas\n"
            << "- 'espace' permet de rentrer dans l'état fumeur (si vous ne bougez pas). Ce dernier vous empeche d'avancer."
            << " Appuyez sur 'a' pour fumer (autant de fois que souhaite), appuyez sur 'e' pour arreter et recommencer a bouger.\n";
}

int CharAnimViewer::update(const float time, const float delta) {
    // time est le temps ecoule depuis le demarrage de l'application, en millisecondes,
    // delta est le temps ecoule depuis l'affichage de la derniere image / le dernier appel a draw(), en millisecondes.

    if (needHelp) {
        commande();
        needHelp = false;
    }
    if (key_state('h')) {
        needHelp = true;
    }
    // Update for time update (benchmark independant)
    /*secondNumber += delta;
    if (secondNumber>1000){
        std::cout<<"+1 secondes\n";
        secondNumber=0;
        testTransform = testTransform* Translation(10,0,0);
    }*/

    if (key_state('n')) {
        m_frameNumber++;
        std::cout << m_frameNumber << '\n';
    }
    if (key_state('b')) {
        --m_frameNumber;
        std::cout << m_frameNumber << '\n';
    }
    m_ske.setPose(m_bvh, m_frameNumber);

    cubeController.update(delta / 1000);
    characterController.update(delta / 1000);
    characterSkeleton.setPose(*characterController.getAnim(),
                              characterController.getFrameAnim());

    m_world.update(0.1f);
    return 0;
}



