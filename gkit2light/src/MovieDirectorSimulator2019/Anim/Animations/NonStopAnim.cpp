#include "NonStopAnim.h"
#include "CharacterController.h"

void NonStopAnim::update(const float dt) {
    handleInput(dt);
    if (actualFrame > bvh.getNumberOfFrame()) {
        character->setActualAnimIdle(0);
    }
}