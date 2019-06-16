#include "DirectorCamera.h"

DirectorCamera::DirectorCamera(Transform matrix, int distViewMax) {
    baseMatrix = matrix;
    XRotation = RotationY(0);
    distMax = distViewMax;
    shaderProgram = read_program("data/shaders/shaderCamera.glsl");
    program_print_errors(shaderProgram);
    init_cameraView();
}

DirectorCamera::~DirectorCamera() {
    release_program(shaderProgram);
}

void DirectorCamera::init_cameraView() {
    /*Point *pMin = new Point(-100, -100, -100);
    Point *pMax = new Point(100, 100, 100);
    cameraViewMesh.bounds(*pMin, *pMax);*/
    cameraViewMesh = Mesh(GL_TRIANGLE_STRIP);
    cameraViewMesh.color(Color(1, 1, 1));
    cameraViewMesh.normal(0, 0, 1);
    // Init first square of the view (small one)
    cameraViewMesh.vertex(-1, -1, 0);
    cameraViewMesh.vertex(1, -1, 0);
    cameraViewMesh.vertex(-1, 1, 0);
    cameraViewMesh.vertex(1, 1, 0);

    // Init all links between the two square
    cameraViewMesh.vertex(-distMax / 2, -distMax / 2, distMax);
    cameraViewMesh.vertex(1, -1, 0);
    cameraViewMesh.vertex(-distMax / 2, distMax / 2, distMax);
    cameraViewMesh.vertex(-1, -1, 0);
    cameraViewMesh.vertex(distMax / 2, distMax / 2, distMax);
    cameraViewMesh.vertex(-1, 1, 0);
    cameraViewMesh.vertex(distMax / 2, -distMax / 2, distMax);
    cameraViewMesh.vertex(-distMax / 2, -distMax / 2, distMax);

    //Init second square (big one)
    cameraViewMesh.vertex(distMax / 2, distMax / 2, distMax);
    cameraViewMesh.vertex(-distMax / 2, distMax / 2, distMax);
}

void DirectorCamera::draw(Orbiter *camera) {
    glUseProgram(shaderProgram);

    Transform view = camera->view();
    Transform projection = camera->projection(window_width(),
                                              window_height(), 45);
    Transform mvp = projection * view * baseMatrix * XRotation;
    program_uniform(shaderProgram, "mvpMatrix", mvp);
    program_uniform(shaderProgram, "distanceMax", distMax);
    program_uniform(shaderProgram, "helpNeeded", needHelp);
    cameraViewMesh.draw(shaderProgram, true, true, true, true);
};