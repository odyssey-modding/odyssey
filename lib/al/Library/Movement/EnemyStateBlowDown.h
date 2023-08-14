#pragma once

#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/Nerve/NerveStateBase.h>
#include "basis/seadTypes.h"

namespace al {
struct EnemyStateBlowDownParam;  // has to be defined here due to order of functions, this Param class could be its own file though

class EnemyStateBlowDown : public al::ActorStateBase {
private:
    const al::EnemyStateBlowDownParam* mParam;
    s32 mBlowDownTimer;
    bool mIsInvalidClipping;

public:
    EnemyStateBlowDown(al::LiveActor*, al::EnemyStateBlowDownParam const*, char const*);
    void start(al::HitSensor const*);
    void start(sead::Vector3f const&);
    void start(al::HitSensor const*, al::HitSensor const*);
    void start(al::LiveActor const*);
    void appear();
    void kill();
    void control();

    void setParam(const al::EnemyStateBlowDownParam* param) { mParam = param; };
};

struct EnemyStateBlowDownParam {
    const char* mActionName = "BlowDown";
    f32 mGravityStrength = 10.3f;
    f32 mVelocityStrength = 28.2f;
    f32 mVelocityMultiplier = 1.1f;
    f32 mVelocityScale = 0.995f;
    s32 mBlowDownLength = 120;
    bool mFaceAwayFromActor = true;

    EnemyStateBlowDownParam();
    EnemyStateBlowDownParam(char const* actionName);
    EnemyStateBlowDownParam(char const* actionName, float gravityStrength, float velocityStrength, float velocityMultiplier, float velocityScale,
                            int blowDownLength, bool faceAwayFromActor);
};
}  // namespace al