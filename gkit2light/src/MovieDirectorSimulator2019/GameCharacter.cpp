
#include <AIController.h>
#include <cstring>
#include "GameCharacter.h"
#include "BasicDrawObject.h"


GameCharacter::GameCharacter(bool isAI, vec4 color, const char *colorName) {
    if (isAI) {
        controller = new AIController();
    } else {
        controller = new CharacterController();
    }
    skeleton.init(*controller->getAnim());
    skeleton.setPose(*controller->getAnim(), -1);

    shader = read_program("data/shaders/charaShader.glsl");
    program_print_errors(shader);
    _color = color;
    _colorName = colorName;

    scaleMatrix = Scale(0.1, 0.1, 0.1);
}

GameCharacter::~GameCharacter() {
    release_program(shader);
    delete controller;
    controller = nullptr;
}

void GameCharacter::draw(Orbiter *camera) {
    glUseProgram(shader);

    Transform view = camera->view();
    Transform projection = camera->projection(window_width(),
                                              window_height(), 45);
    program_uniform(shader, "color", _color);

    for (int i = 1; i < skeleton.numberOfJoint(); ++i) {
        Transform animCorrection = *controller->getAnimCorrection();
        Point point1 = (controller->getMatChar() * animCorrection)(
                skeleton.getJointPosition(i));
        Point point2 = (controller->getMatChar() * animCorrection)(
                skeleton.getJointPosition(skeleton.getParentId(i)));
        Vector ab = point2 - point1;
        Vector p, y, z;
        Vector abn = normalize(ab);
        float lab = length(ab);
        if (fabs(ab.x) > 0.25f)
            p = Vector(0, 1, 0);
        else
            p = Vector(1, 0, 0);

        y = cross(abn, p);
        y = normalize(y);
        z = cross(abn, y);
        Transform T(z, abn, y, Vector(0, 0, 0));
        T = Translation(Vector(point1)) * T * Scale(1, lab, 1);

        Transform mvp = projection * view * scaleMatrix * T;
        BasicDrawObject::getInstance().drawCylinder(shader, mvp);
    }
}

void GameCharacter::update(const float dt) {
    skeleton.setPose(*controller->getAnim(), controller->getFrameAnim());
    controller->update(dt);
}