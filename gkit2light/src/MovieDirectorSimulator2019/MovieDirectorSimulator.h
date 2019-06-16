#ifndef MOVIEDIRECTORSIMULATOR2019_MOVIEDIRECTORSIMULATOR_H
#define MOVIEDIRECTORSIMULATOR2019_MOVIEDIRECTORSIMULATOR_H


#include <app.h>
#include <mesh.h>
#include <draw.h>
#include <gamepads.h>
#include "Anim/CharacterController.h"
#include "Anim/Skeleton.h"
#include "Anim/CubeController.h"
#include "Anim/BVH.h"
#include "Anim/Viewer.h"
#include "Anim/PhysicalWorld.h"
#include "DirectorCamera.h"
#include "BasicDrawObject.h"
#include "Ground.h"

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
	chara::BVH m_bvh;
    int m_frameNumber;

    Skeleton m_ske;

    PhysicalWorld m_world;

    CubeController cubeController;

    Skeleton characterSkeleton;
    CharacterController characterController;

    Orbiter m_camera;
    DrawParam gl;
    bool mb_cullface;
    bool mb_wireframe;

    Mesh m_axe;
    Mesh m_grid;

    Mesh m_quad;
    Mesh m_cube;
    Mesh m_sphere;
    Mesh m_cone;
    Mesh m_cylinder;
    Mesh m_cylinder_cover;
    DirectorCamera *directorCamera;
    Ground * ground;
    bool FPSView = false;

    Gamepads gamepads;

    bool b_draw_grid;
    bool b_draw_axe;

    void init_axe();
    void init_grid();
    void init_quad();
    void init_cube();
    void init_sphere();
    void init_cone();
    void init_cylinder();

    void draw_cylinder(const Transform& T);
    void draw_cylinder(const Point& a, const Point& b, float r = 1.f);

    void manageCameraLight();

    void draw_skeleton(const Skeleton &, const Transform offset);

    void draw_character(const Skeleton &);

   	void draw_sphere(const Transform& T);

   	void draw_sphere(const Point& a, float r = 1.f);

   	void draw_cube(const Transform& T);

	void draw_quad(const Transform &T);

   	void gamepadInput();

};


#endif //MOVIEDIRECTORSIMULATOR2019_MOVIEDIRECTORSIMULATOR_H
