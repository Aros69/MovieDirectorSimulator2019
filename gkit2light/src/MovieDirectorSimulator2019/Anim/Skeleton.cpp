
#include "Skeleton.h"

using namespace chara;

void Skeleton::init(const BVH &bvh) {
    m_joints.resize(bvh.getNumberOfJoint());
    for (int i = 0; i < bvh.getNumberOfJoint(); ++i) {
        m_joints[i].m_parentId = bvh.getJoint(i).getParentId();
        m_joints[i].m_l2w = Identity();
    }
}


Point Skeleton::getJointPosition(int i) const {
    //return Point(0, 0, 0);
    return m_joints[i].m_l2w(Point(0, 0, 0));
}


int Skeleton::getParentId(const int i) const {
    return m_joints[i].m_parentId;
}


void Skeleton::setPose(const BVH &bvh, int frameNumber) {
    int realFrame = frameNumber % bvh.getNumberOfFrame();
    float xOffset, yOffset, zOffset;
    Transform newPose, tempRotationPose, tempTranslationPosition;
    Vector tempTranslationVector;
    for (int i = 0; i < m_joints.size(); ++i) {
        bvh.getJoint(i).getOffset(xOffset, yOffset, zOffset);
        if (bvh.getJoint(i).getParentId() == -1) {
            newPose = Translation(Vector(xOffset, yOffset, zOffset));
        } else {
            newPose = m_joints[getParentId(i)].m_l2w *
                      Translation(Vector(xOffset, yOffset, zOffset));
        }
        if (frameNumber != -1) {
            for (int j = 0; j < bvh.getJoint(i).getNumberOfChannel(); ++j) {
                tempTranslationVector = Vector(0, 0, 0);
                tempRotationPose = Identity();
                if (bvh.getJoint(i).getChannel(j).isRotation()) {
                    if (bvh.getJoint(i).getChannel(j).getAxis() == AXIS_X) {
                        tempRotationPose = RotationX(
                                bvh.getJoint(i).getChannel(j).getData(
                                        realFrame));
                    } else if (bvh.getJoint(i).getChannel(j).getAxis() ==
                               AXIS_Y) {
                        tempRotationPose = RotationY(
                                bvh.getJoint(i).getChannel(j).getData(
                                        realFrame));
                    } else {
                        tempRotationPose = RotationZ(
                                bvh.getJoint(i).getChannel(j).getData(
                                        realFrame));
                    }
                } else {
                    if (bvh.getJoint(i).getChannel(j).getAxis() == AXIS_X) {
                        tempTranslationVector.x = bvh.getJoint(i).getChannel(
                                j).getData(realFrame);
                    } else if (bvh.getJoint(i).getChannel(j).getAxis() ==
                               AXIS_Y) {
                        tempTranslationVector.y = bvh.getJoint(i).getChannel(
                                j).getData(realFrame);
                    } else {
                        tempTranslationVector.z = bvh.getJoint(i).getChannel(
                                j).getData(realFrame);
                    }
                }
                tempTranslationPosition = Translation(tempTranslationVector);
                newPose = newPose * tempTranslationPosition * tempRotationPose;
            }
        }
        m_joints[i].m_l2w = newPose;
    }
    /*
    for (int i = 0; i < m_joints.size(); ++i) {
        //std::cout << bvh.getJoint(i).getNumberOfChannel() << "\n";


    }*/
}
