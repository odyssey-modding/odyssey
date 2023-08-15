#pragma once

#include <al/Library/LiveActor/ActorInitFunction.h>
#include <al/Library/Nerve/NerveStateBase.h>
#include "EnemyCap.h"

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