#ifndef MOVIEDIRECTORSIMULATOR2019_GAMECHARACTER_H
#define MOVIEDIRECTORSIMULATOR2019_GAMECHARACTER_H


#include <mesh.h>
#include <draw.h>
#include <uniforms.h>
#include <program.h>

#include <Skeleton.h>
#include <CharacterController.h>

class GameCharacter {
public:
    GameCharacter() : GameCharacter(false, vec4(1, 1, 1, 1), "Blanc") {};

    GameCharacter(bool isAI, vec4 color, const char *colorName);

    ~GameCharacter();

    void draw(Orbiter *camera);

    void update(const float dt);

    Point getPosition() const {
        return (controller->getCharacterPosition());
    };

    void setOffset(Transform t) {
        offset = t;
        controller->addTransform(t);
    }

    void setControllerMatrix(Transform t) { controller->setMatrix(t); };

    Transform getControllerMatrix() { return controller->getMatChar(); };

    void rotateLeft(float dt) { controller->rotateLeft(dt); }

    void rotateRight(float dt) { controller->rotateRight(dt); }

    float getRotationY() { return controller->getRotationY(); };

    const char *getColorName() { return _colorName; };

private:
    GLuint shader;
    Transform scaleMatrix;
    Transform offset;
    Skeleton skeleton;
    CharacterController *controller;
    vec4 _color;
    const char *_colorName;
};


#endif //MOVIEDIRECTORSIMULATOR2019_GAMECHARACTER_H
