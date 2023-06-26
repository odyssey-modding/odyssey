#pragma once

#include <al/Library/LiveActor/LiveActor.h>

class Player : public al::LiveActor {
    const char* mArchiveName;
    s32 mPort;
    s32 mAirTime;
public:
    Player(const char* actorName, const char* archiveName, s32 port);

    void init(const al::ActorInitInfo& initInfo) override;
    void control() override;

    void exeWait();
    void exeRun();
    void exeJump();
    void exeFall();
    void exeDamage();
};
