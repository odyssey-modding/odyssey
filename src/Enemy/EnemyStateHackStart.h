#pragma once

#include "Player/PlayerHackKeeper.h"
#include "Player/PlayerHackStartShaderCtrl.h"
#include <al/Library/Nerve/NerveStateBase.h>
#include <al/Library/LiveActor/LiveActor.h>

struct EnemyStateHackStartParam {
    const char* mActionName;
    const char* mVisAnimName;
    const char* mMtpAnimName;
    bool mHasSubActors;
    bool mUpdateSubActorShadowMap;
    EnemyStateHackStartParam(const char*, const char*, const char*, bool, bool);
};

class EnemyStateHackStart : public al::ActorStateBase {
private:
    IUsePlayerHack* mHackActor = nullptr;
    PlayerHackStartShaderCtrl* mPlayerHackStartShaderCtrl = nullptr;
    const EnemyStateHackStartParam* mParam;

public:
    EnemyStateHackStart(al::LiveActor*, const EnemyStateHackStartParam*, PlayerHackStartShaderParam*);
    IUsePlayerHack* tryStart(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);
    void kill();
    bool isHackStart() const;
    float calcHackStartNerveRate() const;
    void exeDiveIn();
    void exeHackStart();
};

namespace EnemyStateHackFunction {
void startHackSwitchShadow(al::LiveActor*, const EnemyStateHackStartParam*);
void endHackSwitchShadow(al::LiveActor*, const EnemyStateHackStartParam*);
}  // namespace EnemyStateHackFunction