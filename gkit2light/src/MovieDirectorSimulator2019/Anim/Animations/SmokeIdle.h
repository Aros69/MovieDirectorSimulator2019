
#ifndef GKIT2LIGHT_MASTER_CHARANIM_SMOKEIDLE_H
#define GKIT2LIGHT_MASTER_CHARANIM_SMOKEIDLE_H

#include "AnimState.h"

class SmokeIdle : public AnimState {
public:
    SmokeIdle(CharacterController *characterController)
            : AnimState(characterController) {
        bvh.init("data/bvh/motionGraph_second_life/avatar_smoke_idle.bvh");
        animCorrection = RotationY(90);
    }

    void update(const float dt) override;

    void handleInput(const float dt) override;
};


#endif //GKIT2LIGHT_MASTER_CHARANIM_SMOKEIDLE_H
