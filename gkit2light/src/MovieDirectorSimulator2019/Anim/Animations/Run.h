#ifndef GKIT2LIGHT_MASTER_CHARANIM_RUN_H
#define GKIT2LIGHT_MASTER_CHARANIM_RUN_H


#include "Idle.h"

class Run : public Idle {
public:
    explicit Run(CharacterController *characterController) {
        character = characterController;
        bvh.init("data/bvh/motionGraph_second_life/avatar_run.bvh");
        animCorrection = RotationY(90);
    };

    virtual void update(const float dt) override;
};


#endif //GKIT2LIGHT_MASTER_CHARANIM_RUN_H
