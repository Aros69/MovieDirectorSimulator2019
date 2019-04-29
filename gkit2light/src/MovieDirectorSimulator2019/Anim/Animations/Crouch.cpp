#include "Crouch.h"
#include "CharacterController.h"

void Crouch::update(const float dt) {
    handleInput(dt);
    if (!key_state(SDLK_LSHIFT)) {
        character->setActualAnimIdle(0);
    } else if (character->velocity() != 0) {
        character->setActualAnimCrouchWalk(0);
    }
}

void Crouch::handleInput(const float dt) {
    bool moveKeyPressed = false;
    // Handling input
    if (key_state('z')) {
        character->setForward(true);
        if(character->velocity()<=character->velocityMax()) {
            character->accelerate(dt / 2);
        }
        moveKeyPressed = true;
    }
    if (key_state('q')) {
        character->turnXZ(5.0/2);
    }
    if (key_state('s')) {
        character->setForward(false);
        if(character->velocity()<=character->velocityMax()) {
            character->accelerate(dt / 2);
        }
        moveKeyPressed = true;
    }
    if (key_state('d')) {
        character->turnXZ(-5.0/2);
    }
    if (key_state('x')) {
        character->setVelocity(0);
    }
    if (!moveKeyPressed) {
        character->deccelerate(dt*2);
    }
}