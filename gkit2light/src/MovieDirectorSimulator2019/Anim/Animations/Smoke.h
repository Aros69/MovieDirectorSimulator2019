#ifndef GKIT2LIGHT_MASTER_CHARANIM_SMOKE_H
#define GKIT2LIGHT_MASTER_CHARANIM_SMOKE_H

#include "NonStopAnim.h"

class Smoke : public NonStopAnim {
public:
    Smoke(CharacterController *characterController)
            : NonStopAnim(characterController) {
        bvh.init("data/bvh/motionGraph_second_life/avatar_smoke_inhale.bvh");
    }

    void update(const float dt) override;

};

class StopSmoke : public NonStopAnim {
public:
    StopSmoke(CharacterController *characterController)
            : NonStopAnim(characterController) {
        bvh.init(
                "data/bvh/motionGraph_second_life/avatar_smoke_throw_down.bvh");
    }
};

#endif //GKIT2LIGHT_MASTER_CHARANIM_SMOKE_H
