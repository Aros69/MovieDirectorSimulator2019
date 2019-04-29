#ifndef GKIT2LIGHT_MASTER_CHARANIM_CHARACTERCONTROLLER_H
#define GKIT2LIGHT_MASTER_CHARANIM_CHARACTERCONTROLLER_H

#include "Animations/AnimState.h"
#include "Animations/Idle.h"
#include "Animations/Walk.h"
#include "Animations/Run.h"
#include "Animations/Kick.h"
#include "Animations/Crouch.h"
#include "Animations/CrouchWalk.h"
#include "Animations/Dance.h"
#include "Animations/Smoke.h"
#include "Animations/SmokeIdle.h"
#include "CubeController.h"

class CharacterController : public CubeController {

public:
    CharacterController();

    ~CharacterController();

    void update(const float dt) override;

    void setAnim(unsigned int index, unsigned int goodFrame);

    const chara::BVH *getAnim() const {
        return animations[actualAnimationIndex]->getBVH();
    };

    const Transform *getAnimCorrection() const {
        return animations[actualAnimationIndex]->getAnimCorrection();
    };

    unsigned int getFrameAnim() const {
        return animations[actualAnimationIndex]->getActualframe();
    };

    void setActualAnimIdle(unsigned int goodFrame) { setAnim(0, goodFrame); }

    void setActualAnimWalk(unsigned int goodFrame) { setAnim(1, goodFrame); }

    void setActualAnimRun(unsigned int goodFrame) { setAnim(2, goodFrame); }

    void setActualAnimKick(unsigned int goodFrame) { setAnim(3, goodFrame); }

    void setActualAnimCrouch(unsigned int goodFrame) { setAnim(4, goodFrame); }

    void setActualAnimCrouchWalk(unsigned int goodFrame) {
        setAnim(5, goodFrame);
    }

    void setActualAnimDance1(unsigned int goodFrame) { setAnim(6, goodFrame); }

    void setActualAnimDance2(unsigned int goodFrame) { setAnim(7, goodFrame); }

    void setActualAnimDance3(unsigned int goodFrame) { setAnim(8, goodFrame); }

    void setActualAnimSmokeIdle(unsigned int goodFrame) {
        setAnim(9, goodFrame);
    }

    void setActualAnimSmoke(unsigned int goodFrame) { setAnim(10, goodFrame); }

    void setActualAnimStopSmoke(unsigned int goodFrame) {
        setAnim(11, goodFrame);
    }

protected:
    AnimState **animations;
    unsigned int actualAnimationIndex;
};

#endif //GKIT2LIGHT_MASTER_CHARANIM_CHARACTERCONTROLLER_H
