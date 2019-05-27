#ifndef MOVIEDIRECTORSIMULATOR2019_MOVIEDIRECTORSIMULATOR_H
#define MOVIEDIRECTORSIMULATOR2019_MOVIEDIRECTORSIMULATOR_H


#include <app.h>
#include <mesh.h>
#include <draw.h>

class MovieDirectorSimulator : public App {
public:
    MovieDirectorSimulator();

    //! Initialise tout :
    //! compile les shaders et construit :
    //! le programme + les buffers + le vertex array. renvoie -1 en cas d'erreur.
    int init();

    //! La fonction d'affichage
    int render();

    void help();

    int quit() { return 1; }

protected:
    Orbiter m_camera;
    DrawParam gl;
    bool mb_cullface;
    bool mb_wireframe;

    Mesh m_axe;
    Mesh m_grid;
    Mesh m_cube;

    bool b_draw_grid;
    bool b_draw_axe;

    void init_axe();

    void init_grid();

    void init_cube();

    void manageCameraLight();


};


#endif //MOVIEDIRECTORSIMULATOR2019_MOVIEDIRECTORSIMULATOR_H
