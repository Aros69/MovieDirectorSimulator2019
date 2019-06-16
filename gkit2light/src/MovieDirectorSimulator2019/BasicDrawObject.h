#ifndef MOVIEDIRECTORSIMULATOR2019_BASICDRAWOBJECT_H
#define MOVIEDIRECTORSIMULATOR2019_BASICDRAWOBJECT_H


#include <mesh.h>

class BasicDrawObject {
private:
    static BasicDrawObject *_instance;

    Mesh m_axe;
    Mesh m_grid;

    Mesh m_quad;
    Mesh m_cube;
    Mesh m_sphere;
    Mesh m_cone;
    Mesh m_cylinder;
    Mesh m_cylinder_cover;

    BasicDrawObject();

    BasicDrawObject(BasicDrawObject &) = delete;

    BasicDrawObject(BasicDrawObject &&) = delete;

    void init_axe();

    void init_grid();

    void init_quad();

    void init_cube();

    void init_sphere();

    void init_cone();

    void init_cylinder();

public:
    ~BasicDrawObject();

    static BasicDrawObject &getInstance();

    void drawCube(GLuint shaderProgram);

    void drawQuad(GLuint shaderProgram);

};


#endif //MOVIEDIRECTORSIMULATOR2019_BASICDRAWOBJECT_H
