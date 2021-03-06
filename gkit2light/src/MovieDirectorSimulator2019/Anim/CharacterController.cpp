#include "CharacterController.h"


CharacterController::CharacterController() : CubeController() {
    animations = new AnimState*[3];
    animations[0] = new Idle(this);
    animations[1] = new Walk(this);
    animations[2] = new Run(this);
    setActualAnimIdle(0);
}

CharacterController::~CharacterController() {
    for(int i=0;i<3;++i){
        delete animations[i];
        animations[i] = nullptr;
    }
    delete []animations;
    animations = nullptr;
}

void CharacterController::setAnim(unsigned int index, unsigned int goodFrame) {
    actualAnimationIndex = index;
    animations[actualAnimationIndex]->setActualframe(goodFrame);
    animations[actualAnimationIndex]->setTimeAnim(0);
}

void CharacterController::update(const float dt) {
    bool moveKeyPressed = false;
    if (!moveKeyPressed) {
        deccelerate(dt);
    }
    //moveKeyPressed= false;
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