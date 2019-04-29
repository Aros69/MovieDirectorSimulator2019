
#ifndef _CHARANIMVIEWER_H
#define _CHARANIMVIEWER_H


#include "quaternion.h"
#include "Viewer.h"
#include "BVH.h"
#include "Skeleton.h"
#include "TransformQ.h"
#include "CubeController.h"
#include "CharacterController.h"

#include "PhysicalWorld.h"

class CharAnimViewer : public Viewer {
public:
    CharAnimViewer();

    int init();

    int render();

    int update(const float time, const float delta);

    static CharAnimViewer &singleton() { return *psingleton; }

protected:

    chara::BVH m_bvh;
    int m_frameNumber;

    Skeleton m_ske;

    PhysicalWorld m_world;

    CubeController cubeController;

    Skeleton characterSkeleton;
    CharacterController characterController;

    // Test for time base update (benchmark independant)
    double secondNumber = 0;
    Transform testTransform;

    bool needHelp = true;

    void draw_skeleton(const Skeleton &, const Transform offset);

    void draw_character(const Skeleton &);

private:
    static CharAnimViewer *psingleton;
};


#endif
