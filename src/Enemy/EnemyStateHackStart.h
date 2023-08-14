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
    EnemyStateHackStartParam(char const*, char const*, char const*, bool, bool);
};

class EnemyStateHackStart : public al::ActorStateBase {
private:
    IUsePlayerHack* mHackActor = nullptr;
    PlayerHackStartShaderCtrl* mPlayerHackStartShaderCtrl = nullptr;
    const EnemyStateHackStartParam* mParam;

public:
    EnemyStateHackStart(al::LiveActor*, EnemyStateHackStartParam const*, PlayerHackStartShaderParam*);
    IUsePlayerHack* tryStart(al::SensorMsg const*, al::HitSensor*, al::HitSensor*);
    void kill();
    bool isHackStart() const;
    float calcHackStartNerveRate() const;
    void exeDiveIn();
    void exeHackStart();
};

namespace EnemyStateHackFunction {
void startHackSwitchShadow(al::LiveActor*, EnemyStateHackStartParam const*);
void endHackSwitchShadow(al::LiveActor*, EnemyStateHackStartParam const*);
}  // namespace EnemyStateHackFunction