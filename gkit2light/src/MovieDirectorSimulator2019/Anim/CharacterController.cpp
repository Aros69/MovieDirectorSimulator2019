#include "CharacterController.h"


CharacterController::CharacterController() : CubeController() {
    animations = new AnimState*[12];
    animations[0] = new Idle(this);
    animations[1] = new Walk(this);
    animations[2] = new Run(this);
    animations[3] = new Kick(this);
    animations[4] = new Crouch(this);
    animations[5] = new CrouchWalk(this);
    animations[6] = new Dance1(this);
    animations[7] = new Dance2(this);
    animations[8] = new Dance3(this);
    animations[9] = new SmokeIdle(this);
    animations[10] = new Smoke(this);
    animations[11] = new StopSmoke(this);
    setActualAnimIdle(0);
}

CharacterController::~CharacterController() {
    delete []animations;
    animations = nullptr;
}

void CharacterController::setAnim(unsigned int index, unsigned int goodFrame) {
    actualAnimationIndex = index;
    animations[actualAnimationIndex]->setActualframe(goodFrame);
    animations[actualAnimationIndex]->setTimeAnim(0);
}

void CharacterController::update(const float dt) {
    animations[actualAnimationIndex]->increaseTimeAnim(dt);
    animations[actualAnimationIndex]->update(dt);
    m_ch2w = m_ch2w * Translation(m_v*dt, 0, 0);
}