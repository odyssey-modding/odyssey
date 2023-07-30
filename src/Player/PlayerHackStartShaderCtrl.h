#pragma once

#include <al/Library/LiveActor/LiveActor.h>

struct PlayerHackStartShaderParam;

class PlayerHackStartShaderCtrl {
private:
    al::LiveActor* mParent;
    s32 mTime;
    bool mActive;
    sead::Color4f mColor;
    sead::Quatf mQuat;
    PlayerHackStartShaderParam* mParam;

public:
    PlayerHackStartShaderCtrl(al::LiveActor* host, PlayerHackStartShaderParam* param);
    void setHost(al::LiveActor* host);
    void start();
    void update();
    void end();
};
