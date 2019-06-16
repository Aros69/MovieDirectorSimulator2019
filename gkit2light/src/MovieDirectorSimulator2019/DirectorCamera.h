#ifndef MOVIEDIRECTORSIMULATOR2019_DIRECTORCAMERA_H
#define MOVIEDIRECTORSIMULATOR2019_DIRECTORCAMERA_H


#include <mesh.h>
#include <draw.h>
#include <uniforms.h>
#include <program.h>

class DirectorCamera {
public:
    DirectorCamera() : DirectorCamera(Transform(), -20) {};

    DirectorCamera(Transform matrix,
                   int distViewMax);

    ~DirectorCamera();

    void init_cameraView();

    void draw(Orbiter *camera);

    Transform getMatrix() { return baseMatrix; };

    void setMatrix(Transform matrix) { baseMatrix = matrix; };

    void addTransform(Transform matrix) { baseMatrix = baseMatrix * matrix; };

    void moveForward() { addTransform(Translation(0, 0, -0.5)); };

    void moveBackward() { addTransform(Translation(0, 0, 0.5)); };

    void moveLeft() { addTransform(Translation(-0.5, 0, 0)); };

    void moveRight() { addTransform(Translation(0.5, 0, 0)); };

    void rotateLeft() {
        addTransform(RotationY(0.5));
        yRotAngle -= 0.5;
    };

    void rotateRight() {
        addTransform(RotationY(-0.5));
        yRotAngle += 0.5;
    };

    void rotateUp() {
        XRotation = XRotation * RotationX(0.5);
        xRotAngle -= 0.5;
    };

    void rotateDown() {
        XRotation = XRotation * RotationX(-0.5);
        xRotAngle += 0.5;
    };

    Point getPosition() const {
        return (baseMatrix * XRotation)(Point(0, 0, 0));
    };

    float getYRotation() const { return yRotAngle; };

    float getXRotation() const { return xRotAngle; };

    void changeHelp() { needHelp = !needHelp; };

private:
    GLuint shaderProgram;
    Transform baseMatrix;
    Transform XRotation;
    float yRotAngle = 0;
    float xRotAngle = 0;
    int distMax;
    bool needHelp = false;

    Mesh cameraViewMesh;
};


#endif //MOVIEDIRECTORSIMULATOR2019_DIRECTORCAMERA_H
