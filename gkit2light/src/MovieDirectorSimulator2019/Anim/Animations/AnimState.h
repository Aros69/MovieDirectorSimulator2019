#ifndef GKIT2LIGHT_MASTER_CHARANIM_ANIMSTATE_H
#define GKIT2LIGHT_MASTER_CHARANIM_ANIMSTATE_H

#include <BVH.h>
#include <mat.h>
#include <window.h>

class CharacterController;

// TODO Implement Motion Graph
class AnimState {
protected:
    CharacterController *character;
    chara::BVH bvh;
    Transform animCorrection;
    double timeAnim;
    int actualFrame;

public:
    AnimState() = delete;

    AnimState(CharacterController *characterController) {
        character = characterController;
    }

    double getTimeAnim() const {
        return timeAnim;
    }

    void setTimeAnim(double timeAnim) {
        AnimState::timeAnim = timeAnim;
    }

    unsigned int getActualframe() const {
        return actualFrame;
    }

    void setActualframe(unsigned int actualframe) {
        AnimState::actualFrame = actualframe;
    }

    const chara::BVH *getBVH() const { return &bvh; };

    const Transform *getAnimCorrection() const { return &animCorrection; };

    void increaseTimeAnim(const float dt) {
        timeAnim += dt;
        if (timeAnim >= bvh.getFrameTime()) {
            ++actualFrame;
            timeAnim = 0;
        }
    }

    virtual void update(const float dt) = 0;

    virtual void handleInput(const float dt) = 0;
};

#endif //GKIT2LIGHT_MASTER_CHARANIM_ANIMSTATE_H
