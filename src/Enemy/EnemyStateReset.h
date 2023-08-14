#pragma once

#include "Enemy/EnemyCap.h"
#include <al/Library/LiveActor/LiveActor.h>

class EnemyStateReset : public al::ActorStateBase {
private:
    sead::Vector3f mPos;
    sead::Vector3f mRot;
    f32 mValidDistance;
    bool mIsRevive;
    bool mInvalidateSensors;
    EnemyCap* mEnemyCap;

public:
    EnemyStateReset(al::LiveActor*, al::ActorInitInfo const&, EnemyCap*);
    void appear();
    void kill();
    void exeWait();
};