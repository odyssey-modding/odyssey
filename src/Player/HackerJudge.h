#pragma once

#include "IUse/IJudge.h"
#include "IUse/IUsePlayerHack.h"

class HackerJudge : public al::HioNode, public IJudge {
    IUsePlayerHack** mHacker;

public:
    HackerJudge(IUsePlayerHack** parent) { mHacker = parent; };
    virtual void reset();
    virtual void update();
    virtual void judge();

    IUsePlayerHack** getHacker() const { return mHacker; };
};

class HackerJudgeNormalFall : public HackerJudge {
public:
    HackerJudgeNormalFall(al::LiveActor const* parent, int unk);
    void reset();
    void update();
    void judge();
    int field_10;
    int field_14;
    al::LiveActor* mParent;
};

class HackerJudgeStartJump : public HackerJudge {
public:
    HackerJudgeStartJump(IUsePlayerHack**);
    void judge();
    void reset();
    void update();
};

class HackerJudgeStartRun : public HackerJudge {
public:
    HackerJudgeStartRun(al::LiveActor const*, IUsePlayerHack**);
    void judge();
    void reset();
    void update();
    al::LiveActor* mParent;
    int field_18;
    al::LiveActor* field_20;
    float field_28;
};