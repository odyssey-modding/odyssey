#pragma once

#include <al/Library/Nerve/NerveStateBase.h>

namespace al {
    class ActorInitInfo;
    class HitSensor;
    class LiveActor;
    class SensorMsg;
}

class EnemyCap;

class EnemyStateDamageCap : public al::ActorStateBase {
private:
    EnemyCap* mEnemyCap;

public:
    EnemyStateDamageCap(al::LiveActor* actor);
    void kill();
    void createEnemyCap(const al::ActorInitInfo&, const char*);
    bool tryReceiveMsgCapBlow(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);
    bool isCapOn() const;
    void blowCap(al::HitSensor*);
    void resetCap();
    void makeActorDeadCap();

    void exeWait();
    void exeDamageCap();

    EnemyCap* getEnemyCap() const { return mEnemyCap; };
};