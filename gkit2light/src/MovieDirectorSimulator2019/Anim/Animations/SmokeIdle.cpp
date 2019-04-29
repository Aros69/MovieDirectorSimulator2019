#include "SmokeIdle.h"
#include "CharacterController.h"

void SmokeIdle::update(const float dt) {
    handleInput(dt);
    if (key_state('a')) {
        character->setActualAnimSmoke(0);
    } else if (key_state('e')) {
        character->setActualAnimStopSmoke(0);
    }
}

void SmokeIdle::handleInput(const float dt) {

}