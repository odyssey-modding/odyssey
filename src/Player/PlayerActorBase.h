#pragma once

#include <al/Library/LiveActor/LiveActor.h>
#include "PlayerHackKeeper.h"

class PlayerInitInfo;
class IUsePlayerCollision;
class PlayerCollider;
class PlayerActorBase : public al::LiveActor, public IUsePlayerHack {
private:
    PlayerHackKeeper* mPlayerHackKeeper;
    sead::Matrix34f* mViewMtx;
    s32 port;

public:
    void init(const al::ActorInitInfo& info) override;
    virtual void initPlayer(const al::ActorInitInfo&, const PlayerInitInfo&);
    virtual IUsePlayerCollision* getPlayerCollision();
    virtual PlayerHackKeeper* getPlayerHackKeeper() const override;
    virtual void isEnableDemo();
    virtual void startDemo();
    virtual void endDemo();
    virtual void startDemoPuppetable();
    virtual void endDemoPuppetable();
    virtual void startDemoShineGet();
    virtual void endDemoShineGet();
    virtual void startDemoMainShineGet();
    virtual void endDemoMainShineGet();
    virtual void startDemoHack();
    virtual void endDemoHack();
    virtual void startDemoKeepBind();
    virtual void noticeDemoKeepBindExecute();
    virtual void endDemoKeepBind();
    virtual void startDemoKeepCarry();
    virtual void endDemoKeepCarry();
    virtual void getDemoActor();
    virtual void getDemoAnimator();
    virtual void isDamageStopDemo();
    virtual void getPlayerPuppet();
    virtual void getPlayerInfo();
    virtual void getPortNo();
    virtual void getViewMtx();
    virtual void movement() override;
    virtual void checkDeathArea();
    virtual void sendCollisionMsg();
    virtual void receivePushMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*, float);
};

class IUsePlayerCollision {
public:
    virtual PlayerCollider* getPlayerCollision() const = 0;
};