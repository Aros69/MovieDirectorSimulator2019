#include "Idle.h"
#include "../CharacterController.h"

void Idle::update(const float dt) {
    handleInput(dt);
    if (character->velocity() != 0) {
        character->setActualAnimWalk(0);
    }
}

void Idle::handleInput(const float dt) {
    bool moveKeyPressed = false;
    //character->setTimeAnim(character->getTimeAnim() + 1);
    // Handling input
    if (key_state('z')) {
        character->setForward(true);
        character->accelerate(dt);
        moveKeyPressed = true;
    }
    if (key_state('q')) {
        character->turnXZ(5.0);
    }
    if (key_state('s')) {
        character->setForward(false);
        character->accelerate(dt);
        moveKeyPressed = true;
    }
    if (key_state('d')) {
        character->turnXZ(-5.0);
    }
    if (!moveKeyPressed) {
        character->deccelerate(dt);
    }
}