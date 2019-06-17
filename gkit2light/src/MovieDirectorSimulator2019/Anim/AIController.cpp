#include <Animations/Run.h>
#include <Animations/Walk.h>
#include "AIController.h"

AIController::AIController() : CharacterController() {}

AIController::~AIController() {
    for (int i = 0; i < 3; ++i) {
        delete animations[i];
        animations[i] = nullptr;
    }
    delete[]animations;
    animations = nullptr;
}

void AIController::update(const float dt) {
    bool moveKeyPressed = false;
    //character->setTimeAnim(character->getTimeAnim() + 1);
    // Handling input
    if (timeSinceLastChange == 0 || timeSinceLastChange > 2) {
        lastInput = rand() % 5;
        timeSinceLastChange = 0;
    }
    if (lastInput == 0) {
        setForward(true);
        accelerate(dt);
        moveKeyPressed = true;
    }
    if (lastInput == 1) {
        turnXZ(5.0);
    }
    if (lastInput == 2) {
        setForward(false);
        accelerate(dt);
        moveKeyPressed = true;
    }
    if (lastInput == 3) {
        turnXZ(-5.0);
    }
    if (!moveKeyPressed) {
        deccelerate(dt);
    }
    timeSinceLastChange += dt;
    if (actualAnimationIndex != 1 && velocity() < velocityMax() / 2
        && velocity() > -velocityMax() / 2) {
        setActualAnimWalk(0);
    }
    if (actualAnimationIndex != 2 && (velocity() >= velocityMax() / 2
                                      || velocity() <= -velocityMax() / 2)) {
        setActualAnimRun(0);
    } else if (actualAnimationIndex != 0 && velocity() == 0) {
        setActualAnimIdle(0);
    }
    animations[actualAnimationIndex]->increaseTimeAnim(dt);
    m_ch2w = m_ch2w * Translation(m_v * dt, 0, 0);
    // check if player is out of bound
    Point p = getCharacterPosition()/10;
    int bound = 28;
    if (p.x <= -bound || p.x >= bound || p.z <= -bound || p.z >= bound) {
        m_ch2w = m_ch2w * Translation(-m_v * dt, 0, 0);
    }
}