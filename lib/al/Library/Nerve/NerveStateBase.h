#pragma once

#include <al/Library/Nerve/NerveExecutor.h>

namespace al {
class LiveActor;

class NerveStateBase : public al::NerveExecutor {
private:
    bool mIsDead = true;

public:
    NerveStateBase(const char* stateName);
    ~NerveStateBase();
    virtual void init();
    virtual void appear();
    virtual void kill();
    virtual bool update();
    virtual void control();

    bool isDead() const { return mIsDead; }
};

class ActorStateBase : public al::NerveStateBase {
private:
    al::LiveActor* mActor;

public:
    ActorStateBase(const char* stateName, al::LiveActor* actor);
};

}  // namespace al
