#include "DirectorCamera.h"

DirectorCamera::DirectorCamera(Vector position, Vector rotation, Vector scale,
                               int distViewMax) {
    _position = position;
    _rotation = rotation;
    _scale = scale;
    distMax = distViewMax;
    init_quad();
}

void DirectorCamera::init_quad() {
    quadMesh = Mesh(GL_TRIANGLE_STRIP);
    quadMesh.color(Color(1, 1, 1));

    quadMesh.normal(0, 0, 1);

    quadMesh.texcoord(0, 0);
    quadMesh.vertex(-1, -1, 0);

    quadMesh.texcoord(1, 0);
    quadMesh.vertex(1, -1, 0);

    quadMesh.texcoord(0, 1);
    quadMesh.vertex(-1, 1, 0);

    quadMesh.texcoord(1, 1);
    quadMesh.vertex(1, 1, 0);
}

void DirectorCamera::draw() {
    gl->lighting(true);
    gl->texture(0);
    gl->model(Translation(_position) * RotationX(_rotation.x)
             * RotationY(_rotation.y) * RotationZ(_rotation.z)
             * Scale(_scale.x, _scale.y, _scale.z));
    gl->draw(quadMesh);

    Vector posMax(_position.x, _position.y, _position.z + distMax);
    Vector scaleMax(_scale.x * distMax / 2, _scale.y * distMax / 2,
                    _scale.z / 2);
    gl->model(Translation(posMax) * RotationX(_rotation.x)
             * RotationY(_rotation.y) * RotationZ(_rotation.z)
             * Scale(scaleMax.x, scaleMax.y, scaleMax.z));
    gl->draw(quadMesh);
};