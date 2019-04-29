#ifndef GKIT2LIGHT_MASTER_CHARANIM_CROUCH_H
#define GKIT2LIGHT_MASTER_CHARANIM_CROUCH_H

#include "AnimState.h"

class Crouch : public AnimState {
public:
    Crouch() : AnimState(nullptr) {};

    Crouch(CharacterController *characterController) : AnimState(
            characterController) {
        bvh.init("data/bvh/motionGraph_second_life/avatar_crouch.bvh");
        animCorrection = RotationY(90);
    }

    virtual void update(const float dt) override;

    virtual void handleInput(const float dt) override;
};


#endif //GKIT2LIGHT_MASTER_CHARANIM_CROUCH_H
