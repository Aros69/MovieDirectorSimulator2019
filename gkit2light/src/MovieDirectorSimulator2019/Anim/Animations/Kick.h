#ifndef GKIT2LIGHT_MASTER_CHARANIM_KICK_H
#define GKIT2LIGHT_MASTER_CHARANIM_KICK_H

#include "NonStopAnim.h"

class Kick : public NonStopAnim{
public:
    Kick(CharacterController *characterController)
    : NonStopAnim(characterController) {
            bvh.init("data/bvh/motionGraph_second_life/avatar_kick_roundhouse_R.bvh");
    };
};


#endif //GKIT2LIGHT_MASTER_CHARANIM_KICK_H
