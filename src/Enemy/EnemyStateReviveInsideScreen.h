#pragma once

#include <al/Library/Nerve/NerveStateBase.h>
#include <math/seadVector.h>
#include <math/seadQuat.h>

class EnemyStateReviveInsideScreen : public al::ActorStateBase {
private:
    sead::Quatf mReviveQuat = sead::Quatf::unit;
    sead::Vector3f mRevivePos = sead::Vector3f::zero;
    bool mShouldHide = false;
    bool mIsModelHidden = false;
    bool mIsInvalidClipping = false;

public:
    EnemyStateReviveInsideScreen(al::LiveActor*);

    void appear();
    void kill();
    void startRevive();

    bool isDisappear() const;

    void exeHide();
    void exeDelay();
    void exeAppearSign();
};