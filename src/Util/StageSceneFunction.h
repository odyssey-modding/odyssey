#pragma once

#include <al/Library/LiveActor/LiveActor.h>

namespace StageSceneFunction {
    void appearPlayerDeadCoin(al::LiveActor *);
}

class IJudge;

namespace rs {
    void resetJudge(IJudge *);
    bool updateJudge(IJudge *);
    bool isJudge(IJudge const*);
    bool updateJudgeAndResult(IJudge *);
    void judgeAndResetReturnTrue(IJudge *);
    void isEnableShowDemoAfterOpenMoonRockFirst(al::LiveActor const*);
    void isFirstDemoOpenMoonRock(al::LiveActor const*);
    void isEnableShowDemoMoonRockMapWorld(al::LiveActor const*);
    void showDemoAfterOpenMoonRockFirst(al::LiveActor const*);
    void showDemoMoonRockMapWorld(al::LiveActor const*);
}