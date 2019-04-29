#ifndef GKIT2LIGHT_MASTER_CHARANIM_CROUCHWALK_H
#define GKIT2LIGHT_MASTER_CHARANIM_CROUCHWALK_H

#include "Crouch.h"

class CrouchWalk : public Crouch {
public:
    CrouchWalk(CharacterController *characterController){
        character = characterController;
        bvh.init("data/bvh/motionGraph_second_life/avatar_crouchwalk.bvh");
        animCorrection = RotationY(90);
    }

    virtual void update (const float dt) override;

};


#endif //GKIT2LIGHT_MASTER_CHARANIM_CROUCHWALK_H
