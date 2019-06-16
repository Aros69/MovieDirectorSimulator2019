#include "Ground.h"

Ground::Ground(vec3 scale) {
    _scale = scale;
    shaderProgram = read_program("data/shaders/groundShader.glsl");
    program_print_errors(shaderProgram);
}

Ground::~Ground() {
    release_program(shaderProgram);
}

void Ground::draw(Orbiter *camera) {

    glUseProgram(shaderProgram);

    Transform view = camera->view();
    Transform projection = camera->projection(window_width(),
                                              window_height(), 45);
    Transform mvp = projection * view * RotationX(90) *
                    Scale(_scale.x, _scale.y, _scale.z);
    program_uniform(shaderProgram, "mvpMatrix", mvp);
    // Floor part
    BasicDrawObject::getInstance().drawQuad(shaderProgram);
    // Wall part
    mvp = projection * view * Translation(0, _scale.y / 12, _scale.z) *
          Scale(_scale.x, _scale.y / 12, _scale.z);
    program_uniform(shaderProgram, "mvpMatrix", mvp);
    BasicDrawObject::getInstance().drawQuad(shaderProgram);
    mvp = projection * view * Translation(0, _scale.y / 12, -_scale.z) *
          Scale(_scale.x, _scale.y / 12, _scale.z);
    program_uniform(shaderProgram, "mvpMatrix", mvp);
    BasicDrawObject::getInstance().drawQuad(shaderProgram);
    mvp = projection * view * Translation(_scale.x, _scale.y / 12, 0) *
          RotationY(90) * Scale(_scale.x, _scale.y / 12, _scale.z);
    program_uniform(shaderProgram, "mvpMatrix", mvp);
    BasicDrawObject::getInstance().drawQuad(shaderProgram);
    mvp = projection * view * Translation(-_scale.x, _scale.y / 12, 0) *
          RotationY(90) * Scale(_scale.x, _scale.y / 12, _scale.z);
    program_uniform(shaderProgram, "mvpMatrix", mvp);
    BasicDrawObject::getInstance().drawQuad(shaderProgram);
};
