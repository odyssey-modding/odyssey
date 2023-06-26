#pragma once

#include <al/Library/LiveActor/LiveActor.h>

struct PlayerHackStartShaderParam {

};

class PlayerHackStartShaderCtrl {
    public:
    PlayerHackStartShaderCtrl(al::LiveActor*, PlayerHackStartShaderParam*);
    void setHost(al::LiveActor*);
    void start(void);
    void update(void);
    void end(void);
    al::LiveActor *mParent;
    // TODO: fill this class out
    char unknown[0x30];
};