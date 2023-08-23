#pragma once

#include <math/seadMatrix.h>
#include <container/seadPtrArray.h>

namespace al {
    class LiveActor;
    class HitSensor;
    class CollisionPartsFilterBase;
} // namespace al

class PlayerRecoverySafetyPoint;
class HackCap;
class PlayerInput;
class PlayerDamageKeeper;
class IPlayerModelChanger;
class IUsePlayerHeightCheck;
class HackObjInfo;
class CapTargetInfo;
class PlayerHackStartTexKeeper;

class PlayerHackKeeper {
    al::LiveActor* mParent;
    HackCap* mHackCap;
    PlayerRecoverySafetyPoint* mRecoverySafePoint;
    void* field_18;
    void* field_20;
    PlayerInput* mInput;
    sead::Matrix34f* field_30;
    PlayerDamageKeeper* mDamageKeeper;
    IPlayerModelChanger* mModelChanger;
    IUsePlayerHeightCheck* mHeightCheck;
    al::HitSensor* mParentBodySensor;
    bool mIsPuppetable;
    bool mIsCancellingHack;
    bool mIsHackDemoStarted;
    bool mIsPuppetable2;
    bool mIsStartedHacking;
    bool mIsHack;
    bool mIsTookDamage;
    al::CollisionPartsFilterBase* mCollisionFilter;
    al::LiveActor* mHackActor;
    al::HitSensor* mHackHitSensor;
    HackObjInfo* mHackObjectInfo;
    al::HitSensor* mStageStartActorSensor;
    al::LiveActor* mStageStartActor;
    CapTargetInfo* mStageStartCapTargetInfo;
    PlayerHackStartTexKeeper* mHackStartTexKeeper;
    al::LiveActor* mHackModel;
    sead::PtrArray<void> mHackModelSlices;
    sead::Matrix34f* field_b8;
    sead::Vector3i mLastPosition; // unsure

public:
    PlayerHackKeeper(al::LiveActor* player, HackCap* cap, PlayerRecoverySafetyPoint* safetyPoint, const PlayerInput* input, const sead::Matrix34f* mtx, PlayerDamageKeeper* damageKeeper, const IPlayerModelChanger* modelChanger, const IUsePlayerHeightCheck* heightCheck);
    void recordHack();
    void killHackDemoModel();
    void appearHackDemoModel(const sead::Matrix34f&, float);
    void updateHackDemoModel(const sead::Matrix34f&, float);
    void deleteHackDemoModelEffect();

    void setPuppetable(bool isPuppetable) { mIsPuppetable = isPuppetable; };
    bool isPuppetable2() const { return mIsPuppetable2; };
    bool isHack() const { return mIsHack; };
    bool isHackDemoStarted() const { return mIsHackDemoStarted; };
    bool isStartedHacking() const { return mIsStartedHacking; };
    al::LiveActor* getHack() const { return mHackActor; };
    al::HitSensor* getHackSensor() const { return mHackHitSensor; };
};

class IUsePlayerHack {
public:
    virtual PlayerHackKeeper* getPlayerHackKeeper() const = 0;
};