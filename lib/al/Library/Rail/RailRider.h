#pragma once

#include <math/seadVector.h>

namespace al {
class Rail;
class RailRider {
private:
    const al::Rail* mRail;
    sead::Vector3f mPosition;
    sead::Vector3f mDirection;
    f32 mCoord;
    f32 mRate;
    bool mIsMoveForwards;

public:
    RailRider(const al::Rail* rail);
    void moveToRailStart();
    void move();
    void syncPosDir();
    void setCoord(f32 coord);
    void moveToRailPoint(s32 point);
    void moveToRailEnd();
    void moveToBegin();
    void moveToGoal();
    void moveToNearestRail(const sead::Vector3f& position);
    void reverse();
    void setMoveGoingStart();
    void setMoveGoingEnd();
    void setSpeed(f32 speed);
    void addSpeed(f32 speed);
    void scaleSpeed(f32 speed);
    bool isReachedGoal();
    bool isReachedRailEnd();
    bool isReachedRailStart();
    bool isReachedEdge();
};
class IUseRail {
public:
    virtual RailRider* getRailRider() const = 0;
};
}  // namespace al
