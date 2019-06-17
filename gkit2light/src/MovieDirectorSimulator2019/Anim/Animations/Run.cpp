#include "Run.h"
#include "../CharacterController.h"

void Run::update(const float dt) {
    handleInput(dt);
    if (character->velocity() < character->velocityMax() / 2
               && character->velocity() > -character->velocityMax() / 2) {
        character->setActualAnimWalk(0);
    }
}