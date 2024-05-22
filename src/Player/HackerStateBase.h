#pragma once

class IUsePlayerHack;

#include <al/Library/Nerve/NerveStateBase.h>

class HackerStateBase : public al::NerveStateBase {
private:
    al::LiveActor* mActor;
    IUsePlayerHack* mPlayer;

public:
    HackerStateBase(const char* name, al::LiveActor* actor, IUsePlayerHack** player);
};
