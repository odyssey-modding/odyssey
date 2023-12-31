#pragma once

#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/Nerve/NerveSetupUtil.h>

#include "AnagramAlphabet.h"

#include "MapObj/CapTargetParts.h"
#include "Player/CapTargetInfo.h"
#include "Player/PlayerHackStartShaderCtrl.h"

class IUsePlayerHack;
class HackerJudgeNormalFall;
class HackerJudgeStartRun;

class AnagramAlphabetCharacter : public al::LiveActor {
    CapTargetInfo* mCapTargetInfo;
    sead::Matrix34f* unkMtx;
    AnagramAlphabet* mParent;
    IUsePlayerHack* mHackerParent;
    CapTargetParts* mCapTargetParts;
    HackerJudgeNormalFall* mHackerJudgeNormalFall;
    HackerJudgeStartRun* mHackerJudgeStartRun;
    PlayerHackStartShaderCtrl* mPlayerHackStartShaderCtrl;
    int mSwingTimer;

public:
    AnagramAlphabetCharacter(const char*);

    void init(const al::ActorInitInfo&);
    void attackSensor(al::HitSensor*, al::HitSensor*);
    bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*);
    void setComplete(void);
    void killCapTarget(void);

    void exeWait(void);
    void exeWaitHack(void);
    void exeWaitHackStart(void);
    void exeHackStart(void);
    void exeHackWait(void);
    void exeHackMove(void);
    void exeHackFall(void);
    void exeHackEnd(void);
    void exeHackGoal(void);
    void exeSet(void);
    void exeComplete(void);
};
