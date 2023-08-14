#pragma once

#include "Player/PlayerActorBase.h"
#include <al/Library/LiveActor/LiveActor.h>
#include <math/seadVector.h>

class In2DAreaMoveControl;

class ActorDimensionKeeper {
    const al::LiveActor* mLiveActor;
    bool mIsValid = true;
    bool mIs2D = false;
    bool mIsIn2DArea = false;
    bool mIsCurrently2D = false;
    bool mIsCanChange2D = false;
    bool mIsCanChange3D = false;
    In2DAreaMoveControl* mIn2DAreaMoveControl = nullptr;

public:
    ActorDimensionKeeper(const al::LiveActor* actor);
    void validate();
    void invalidate();
    void forceChange2DKeep();
    void forceEndChange2DKeep();
    void update();

    bool getIs2D() const { return mIs2D; }
    bool getIsIn2DArea() const { return mIsIn2DArea; }
    bool getIsCurrently2D() const { return mIsCurrently2D; }
    bool getIsCanChange2D() const { return mIsCanChange2D; }
    bool getIsCanChange3D() const { return mIsCanChange3D; }
};

class IUseDimension {
public:
    virtual ActorDimensionKeeper* getActorDimensionKeeper() const = 0;
};

namespace al {
class MtxConnector;
}

namespace rs {
ActorDimensionKeeper* createDimensionKeeper(al::LiveActor const*);
void updateDimensionKeeper(ActorDimensionKeeper*);
const char* getSpecialPurposeName2DOnly();
void createAndSetFilter2DOnly(al::LiveActor*);
void createCollisionPartsFilter2DOnly();
bool is2D(IUseDimension const*);
bool isIn2DArea(IUseDimension const*);
bool is3D(IUseDimension const*);
bool isChange2D(IUseDimension const*);
bool isChange3D(IUseDimension const*);
bool isNearSnapSurface(IUseDimension const*, f32);
void calcLockDirection(sead::Vector3f*, IUseDimension const*);
void calcDimensionGravity(sead::Vector3f*, IUseDimension const*, sead::Vector3f const&);
void setDimensionGravity(al::LiveActor*, IUseDimension const*);
void syncDimensionPoseGravity(al::LiveActor*, IUseDimension const*);
void calcLockedMoveVec(sead::Vector3f*, IUseDimension const*, f32);
void pushOutFrom2DArea(al::LiveActor*, IUseDimension const*, f32, f32);
void snap2D(al::LiveActor*, IUseDimension const*, f32);
void snap2DGravity(al::LiveActor*, IUseDimension const*, f32);
void snap2DUp(al::LiveActor*, IUseDimension const*, f32);
void snap2DParallelizeFront(al::LiveActor*, IUseDimension const*, f32);
void snap2DGravityPoseWithRotateCenter(al::LiveActor*, IUsePlayerCollision*, IUseDimension const*, f32, f32, sead::Vector3f const&);
void calcSnap2DPosition(sead::Vector3f*, IUseDimension const*, sead::Vector3f const&, f32);
void attachMtxConnectorTo2DCollision(al::MtxConnector*, al::LiveActor const*, sead::Vector3f const&, sead::Vector3f const&);
void attachMtxConnectorTo2DCollision(al::MtxConnector*, al::LiveActor const*, bool);
void attachMtxConnectorTo2DCollision(al::MtxConnector*, al::LiveActor const*, f32, f32);
void syncVisAnimFrame2D(al::LiveActor*, char const*, bool);
}  // namespace rs