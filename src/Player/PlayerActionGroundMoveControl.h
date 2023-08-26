#pragma once

#include <math/seadVector.h>

namespace al {
class LiveActor;
}  // namespace al

class PlayerConst;
class PlayerInput;
class IUsePlayerCollision;
class IUsePlayerHack;
class IJudge;
class PlayerActionTurnControl;

class PlayerActionGroundMoveControl {
private:
    al::LiveActor* mParent;
    const PlayerConst* mPlayerConst;
    const PlayerInput* mPlayerInput;
    const IUsePlayerCollision* mCollision;
    const IUsePlayerHack** mHack = nullptr;
    bool mIsSetup = false;
    sead::Vector3f mGroundNormal;
    f32 mMaxSpeed;
    f32 mMinSpeed;
    f32 field_40;
    s32 field_44;
    s32 mRunFrame;
    s32 mStickOnBrakeFrame;
    s32 mBrakeFrame;
    f32 mGravityMove;
    f32 mBrakeSpeed;
    s32 mCounterBorder;
    s32 field_60;
    bool field_64;
    IJudge* mJudge;
    f32 field_70;
    s32 field_74;
    bool field_78;
    f32 field_7c;
    bool mHasStopped;
    sead::Vector3f field_84;
    f32 field_90;
    f32 field_94;
    f32 field_98;
    bool mIsForceRunCtrlActive;
    f32 field_a0;
    bool mAlwaysFalse;
    f32 field_a8;
    f32 field_ac;
    PlayerActionTurnControl* mTurnCtrl;
    bool field_b8;
    bool field_b9;
    bool field_ba;
    bool field_bb;
    bool field_bc;
    bool field_bd;
    f32 field_c0;
    bool field_c4;
    sead::Vector3f field_c8;
    bool field_d4;
    bool field_d5;

public:
    PlayerActionGroundMoveControl(al::LiveActor* parent, const PlayerConst* playerConst, const PlayerInput* input,
                                  const IUsePlayerCollision* collision);
    ~PlayerActionGroundMoveControl() = default;
    void appear();
    float calcAccelRate(float) const;
    void calcInitBrakeOnCounter();
    void setup(float maxSpeed, float minSpeed, int runFrame, int stickOnBrakeFrame, int brakeFrame, float gravityMove, float, int counterBorder);
    void updateNormalAndSnap(sead::Vector3f*);
    void set_field_c4() { field_c4 = true; };
    sead::Vector3f& getGroundNormal() { return mGroundNormal; };
};
