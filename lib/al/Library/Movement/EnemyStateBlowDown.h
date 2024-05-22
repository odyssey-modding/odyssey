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
}  // namespace al