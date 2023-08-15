#pragma once

#include <al/Library/Nerve/NerveStateBase.h>
#include <basis/seadTypes.h>

namespace al {
struct EnemyStateBlowDownParam;
class HitSensor;
class LiveActor;

class EnemyStateBlowDown : public al::ActorStateBase {
private:
    const al::EnemyStateBlowDownParam* mParam;
    s32 mBlowDownTimer;
    bool mIsInvalidClipping;

public:
    EnemyStateBlowDown(al::LiveActor*, const al::EnemyStateBlowDownParam*, const char*);
    void start(const al::HitSensor*);
    void start(const sead::Vector3f&);
    void start(const al::HitSensor*, const al::HitSensor*);
    void start(const al::LiveActor*);
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
    EnemyStateBlowDownParam(const char* actionName);
    EnemyStateBlowDownParam(const char* actionName, float gravityStrength, float velocityStrength, float velocityMultiplier, float velocityScale,
                            int blowDownLength, bool faceAwayFromActor);
};
}  // namespace al