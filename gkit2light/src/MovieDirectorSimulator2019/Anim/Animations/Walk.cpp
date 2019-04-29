#include "Walk.h"
#include "CharacterController.h"

void Walk::update(const float dt) {
    handleInput(dt);
    if (key_state('x')) {
        character->setActualAnimKick(0);
    } else if (key_state(SDLK_LSHIFT)) {
        character->setActualAnimCrouchWalk(0);
    } else if (character->velocity() >= character->velocityMax() / 2
               || character->velocity() <= -character->velocityMax() / 2) {
        character->setActualAnimRun(0);
    } else if (character->velocity() == 0) {
        character->setActualAnimIdle(0);
    }
}
