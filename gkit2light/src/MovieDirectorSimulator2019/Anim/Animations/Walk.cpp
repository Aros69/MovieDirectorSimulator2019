#include "Walk.h"
#include "../CharacterController.h"

void Walk::update(const float dt) {
    handleInput(dt);
    if (character->velocity() >= character->velocityMax() / 2
               || character->velocity() <= -character->velocityMax() / 2) {
        character->setActualAnimRun(0);
    } else if (character->velocity() == 0) {
        character->setActualAnimIdle(0);
    }
}
