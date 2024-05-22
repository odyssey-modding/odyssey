#pragma once

#include "AnagramAlphabet.h"
#include "MapObj/CapTargetParts.h"
#include "Player/CapTargetInfo.h"
#include "Player/PlayerHackStartShaderCtrl.h"

class IUsePlayerHack;
class HackerJudgeNormalFall;
class HackerJudgeStartRun;

class AnagramAlphabetCharacter : public al::LiveActor {
private:
    CapTargetInfo* mCapTargetInfo;
    sead::Matrix34f* field_110;
    AnagramAlphabet* mParent;
    IUsePlayerHack* mHackerParent;
    CapTargetParts* mCapTargetParts;
    HackerJudgeNormalFall* mHackerJudgeNormalFall;
    HackerJudgeStartRun* mHackerJudgeStartRun;
    PlayerHackStartShaderCtrl* mPlayerHackStartShaderCtrl;
    s32 mSwingTimer;

public:
    AnagramAlphabetCharacter(const char*);

    void init(const al::ActorInitInfo&);
    void attackSensor(al::HitSensor*, al::HitSensor*);
    bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);
    void setComplete();
    void killCapTarget();

    void exeWait();
    void exeWaitHack();
    void exeWaitHackStart();
    void exeHackStart();
    void exeHackWait();
    void exeHackMove();
    void exeHackFall();
    void exeHackEnd();
    void exeHackGoal();
    void exeSet();
    void exeComplete();
};
