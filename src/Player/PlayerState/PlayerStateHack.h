#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>
#include <math/seadMatrix.h>
#include <al/Library/Nerve/NerveStateBase.h>


namespace al {
    class LiveActor;
    class HitSensor;
} // namespace al

class PlayerHackKeeper;
class IPlayerModelChanger;
class PlayerAnimator;
class HackCap;

class PlayerStateHack : public al::ActorStateBase {
    PlayerHackKeeper* mHackKeeper;
    IPlayerModelChanger* mModelChanger;
    PlayerAnimator* mAnimator;
    HackCap* mHackCap;
    bool mIsStageStartHack;
    s32 mHackDemoStartLength;
    sead::Vector3f mTrans;
    sead::Vector3f mSensorTrans;
    sead::Vector3f mNewSensorTrans;
    sead::Matrix34f mPossessTraceMtx;
    sead::Matrix34f mDemoModelMtx;

public:
    PlayerStateHack(al::LiveActor* parent, PlayerHackKeeper* hackKeeper, IPlayerModelChanger* modelChanger,
                    PlayerAnimator* animator, HackCap* hackCap);
    ~PlayerStateHack() = default;
    void appear();
    void exeEnd();
    void exeHack();
    void exeHackDemo();
    void exeHackDemoPuppetable();
    bool isEnableCancelHack() const;
    bool isEnableChangeState() const;
    bool isEnableModelSyncShowHide() const;
    bool isIgnoreUpdateCollider() const;
    void prepareEndHack();
    void prepareStageStartHack();
    void prepareStartHack(const al::HitSensor*, const al::HitSensor*);
};
