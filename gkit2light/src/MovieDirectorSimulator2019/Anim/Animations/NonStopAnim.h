#ifndef GKIT2LIGHT_MASTER_CHARANIM_NONSTAOPANIM_H
#define GKIT2LIGHT_MASTER_CHARANIM_NONSTAOPANIM_H

#include "AnimState.h"

class NonStopAnim : public AnimState {
public:
    NonStopAnim(CharacterController *characterController)
            : AnimState(characterController) {
        animCorrection = RotationY(90);
    }

    void update(const float dt) override;

    void handleInput(const float dt) override {};
};


#endif //GKIT2LIGHT_MASTER_CHARANIM_NONSTAOPANIM_H
