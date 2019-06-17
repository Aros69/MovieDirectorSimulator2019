#ifndef MOVIEDIRECTORSIMULATOR2019_MOVIEDIRECTORSIMULATOR_H
#define MOVIEDIRECTORSIMULATOR2019_MOVIEDIRECTORSIMULATOR_H


#include <app.h>
#include <mesh.h>
#include <draw.h>
#include <gamepads.h>
#include <vector>
#include <GL/glut.h>
#include <widgets.h>
#include "Anim/CharacterController.h"
#include "Anim/AIController.h"
#include "Anim/Skeleton.h"
#include "Anim/CubeController.h"
#include "Anim/BVH.h"
#include "Anim/Viewer.h"
#include "Anim/PhysicalWorld.h"
#include "DirectorCamera.h"
#include "BasicDrawObject.h"
#include "Ground.h"
#include "GameCharacter.h"

class MovieDirectorSimulator : public App {
public:
    MovieDirectorSimulator();

    ~MovieDirectorSimulator();

    //! Initialise tout :
    //! compile les shaders et construit :
    //! le programme + les buffers + le vertex array. renvoie -1 en cas d'erreur.
    int init();

    //! La fonction d'affichage
    int render();

    void help();

    int update(const float time, const float delta);

    int quit() { return 1; }

protected:
    int m_frameNumber;

    PhysicalWorld m_world;

    std::vector<GameCharacter *> gameCharacters;
    const int num = 10;

    Orbiter m_camera;
    DrawParam gl;
    bool mb_cullface;
    bool mb_wireframe;

    Mesh m_axe;
    Mesh m_grid;

    DirectorCamera *directorCamera;
    Ground *ground;
    bool FPSView = false;

    double score = 0;
    unsigned int playerCible = -1;

    Gamepads gamepads;

    Widgets textWidget;

    bool b_draw_grid;
    bool b_draw_axe;

    void init_axe();

    void init_grid();

    void manageCameraLight();

    void gamepadInput(const float dt);

    bool isInTheCameraView(unsigned int characterIndex);

    std::vector<std::pair<vec4, const char *>> colors;

private:
    void initColors() {
        colors = std::vector<std::pair<vec4, const char *>>(0);
        colors.push_back(
                std::pair<vec4, const char *>(vec4(1, 0, 0, 1), "Rouge"));
        colors.push_back(
                std::pair<vec4, const char *>(vec4(0, 1, 0, 1), "Vert"));
        colors.push_back(
                std::pair<vec4, const char *>(vec4(0, 0, 1, 1), "Bleu"));
        colors.push_back(
                std::pair<vec4, const char *>(vec4(0.35, 0.23, 0.06, 1),
                                              "Marron"));
        colors.push_back(
                std::pair<vec4, const char *>(vec4(1, 1, 0, 1), "Jaune"));
        colors.push_back(
                std::pair<vec4, const char *>(vec4(1, 0, 1, 1), "Rose"));
        colors.push_back(
                std::pair<vec4, const char *>(vec4(0, 1, 1, 1), "Bleu clair"));
        colors.push_back(
                std::pair<vec4, const char *>(vec4(0.87, 0.42, 0.08, 1),
                                              "Orange"));
        colors.push_back(
                std::pair<vec4, const char *>(vec4(1, 1, 1, 1), "Blanc"));
        colors.push_back(
                std::pair<vec4, const char *>(vec4(0, 0, 0, 1), "Noir"));
    }
};


#endif //MOVIEDIRECTORSIMULATOR2019_MOVIEDIRECTORSIMULATOR_H
