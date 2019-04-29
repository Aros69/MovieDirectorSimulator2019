#ifndef GKIT2LIGHT_MASTER_CHARANIM_DANCE1_H
#define GKIT2LIGHT_MASTER_CHARANIM_DANCE1_H

#include "NonStopAnim.h"

class Dance1 : public NonStopAnim {
public:
    Dance1(CharacterController *characterController)
            : NonStopAnim(characterController) {
        bvh.init("data/bvh/motionGraph_second_life/avatar_dance1.bvh");
        animCorrection = RotationY(-90);
    }
};

class Dance2 : public NonStopAnim {
public:
    Dance2(CharacterController *characterController)
            : NonStopAnim(characterController) {
        bvh.init("data/bvh/motionGraph_second_life/avatar_dance2.bvh");
        animCorrection = RotationY(-90);
    }
};

class Dance3 : public NonStopAnim {
public:
    Dance3(CharacterController *characterController)
            : NonStopAnim(characterController) {
        bvh.init("data/bvh/motionGraph_second_life/avatar_dance3.bvh");
        animCorrection = RotationY(-90);
    }
};


#endif //GKIT2LIGHT_MASTER_CHARANIM_DANCE1_H
