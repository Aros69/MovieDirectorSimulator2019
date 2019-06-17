#include "BasicDrawObject.h"
#include <math.h>
#include <uniforms.h>

BasicDrawObject *BasicDrawObject::_instance;

BasicDrawObject::BasicDrawObject() {
    init_quad();
    init_cylinder();
    init_cone();
    init_sphere();
    init_axe();
    init_cube();
    init_grid();
}

BasicDrawObject &BasicDrawObject::getInstance() {
    if (_instance == nullptr) {
        _instance = new BasicDrawObject();
    }
    return *_instance;
}

void BasicDrawObject::init_axe() {
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

void BasicDrawObject::init_grid() {
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

void BasicDrawObject::init_quad() {
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

void BasicDrawObject::init_cube() {
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

void BasicDrawObject::init_sphere() {
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

void BasicDrawObject::init_cone() {
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

void BasicDrawObject::init_cylinder() {
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

void BasicDrawObject::drawCube(GLuint shaderProgram) {
    m_cube.draw(shaderProgram, true, true, true, true);
}

void BasicDrawObject::drawQuad(GLuint shaderProgram) {
    m_quad.draw(shaderProgram, true, true, true, true);
};

void BasicDrawObject::drawCylinder(GLuint shader, Transform matrix) {

    program_uniform(shader, "mvpMatrix", matrix);
    m_cylinder.draw(shader, true, true, true, true);
    Transform Tch = matrix * Translation(0, 1, 0);
    program_uniform(shader, "mvpMatrix", Tch);
    m_cylinder_cover.draw(shader, true, true, true, true);

    Transform Tcb =
            matrix * Translation(0, 0, 0) * Rotation(Vector(1, 0, 0), 180);
    program_uniform(shader, "mvpMatrix", Tcb);
    m_cylinder_cover.draw(shader, true, true, true, true);
}