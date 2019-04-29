#include "Smoke.h"
#include "CharacterController.h"

void Smoke::update(const float dt) {
    if (actualFrame > bvh.getNumberOfFrame()) {
        character->setActualAnimSmokeIdle(0);
    }
}

