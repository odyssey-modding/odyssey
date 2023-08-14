#pragma once

#include <al/Library/Nerve/NerveStateBase.h>

class EnemyStateWander : public al::ActorStateBase {
private:
    const char* mStateName;
    s32 mRandNum;
    f32 mWalkSpeed;
    bool mIsHalfProbability;

public:
    EnemyStateWander(al::LiveActor* actor, char const* stateName);
    void appear();

    void exeWait();
    void exeWalk();
    void exeFall();

    bool isWait() const;
    bool isWalk() const;
    bool isFall() const;
    void changeWalkAnim(char const*);
};
