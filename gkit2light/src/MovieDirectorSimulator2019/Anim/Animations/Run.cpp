#include "Run.h"
#include "CharacterController.h"

void Run::update(const float dt) {
    handleInput(dt);
    if (key_state('x')) {
        character->setActualAnimKick(0);
    } else if (character->velocity() < character->velocityMax() / 2
               && character->velocity() > -character->velocityMax() / 2) {
        character->setActualAnimWalk(0);
    }
}