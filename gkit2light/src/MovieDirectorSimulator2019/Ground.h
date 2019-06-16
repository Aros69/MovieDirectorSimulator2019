#ifndef MOVIEDIRECTORSIMULATOR2019_GROUND_H
#define MOVIEDIRECTORSIMULATOR2019_GROUND_H

#include <mesh.h>
#include <draw.h>
#include <orbiter.h>
#include <program.h>
#include <uniforms.h>
#include "BasicDrawObject.h"

class Ground {
public:
    Ground() : Ground(vec3(30,30,30)) {};

    Ground(vec3 scale);

    ~Ground();

    void draw(Orbiter *camera);

private:
    GLuint shaderProgram;
    vec3 _scale;
};


#endif //MOVIEDIRECTORSIMULATOR2019_GROUND_H
