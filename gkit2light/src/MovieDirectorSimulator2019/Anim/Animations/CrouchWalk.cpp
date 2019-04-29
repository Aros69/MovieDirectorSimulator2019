#include "CrouchWalk.h"
#include "CharacterController.h"

void CrouchWalk::update(const float dt) {
    handleInput(dt);
    if (!key_state(SDLK_LSHIFT)) {
        character->setActualAnimWalk(0);
    } else if (character->velocity() == 0) {
        character->setActualAnimCrouch(0);
    }
}