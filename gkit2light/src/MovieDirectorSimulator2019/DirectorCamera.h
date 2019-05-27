#ifndef MOVIEDIRECTORSIMULATOR2019_DIRECTORCAMERA_H
#define MOVIEDIRECTORSIMULATOR2019_DIRECTORCAMERA_H


#include <mesh.h>
#include <draw.h>

class DirectorCamera {
public:
    DirectorCamera(DrawParam* drawParamGl) : DirectorCamera(Vector(0, 0, 0), Vector(0, 0, 0),
                                      Vector(1, 1, 1), -10) {
        gl = drawParamGl;
    };

    DirectorCamera(Vector position, Vector rotation, Vector scale,
                   int distViewMax);

    void init_quad();

    void draw();

private:

    DrawParam* gl;

    Vector _position;
    Vector _rotation;
    Vector _scale;
    int distMax;

    Mesh quadMesh;

};


#endif //MOVIEDIRECTORSIMULATOR2019_DIRECTORCAMERA_H
