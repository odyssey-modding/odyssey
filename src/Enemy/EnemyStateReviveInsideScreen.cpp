#include "Enemy/EnemyStateReviveInsideScreen.h"
#include <al/Library/Action/ActorActionKeeper.h>
#include <al/Library/LiveActor/ActorActionFunction.h>
#include <al/Library/LiveActor/ActorClippingFunction.h>
#include <al/Library/LiveActor/ActorModelFunction.h>
#include <al/Library/LiveActor/ActorMovementFunction.h>
#include <al/Library/LiveActor/ActorPoseKeeper.h>
#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Nerve/NerveUtil.h>
#include <al/Library/Se/SeFunction.h>

namespace {
NERVE_IMPL(EnemyStateReviveInsideScreen, Hide);
NERVE_IMPL(EnemyStateReviveInsideScreen, Delay);
NERVE_IMPL(EnemyStateReviveInsideScreen, AppearSign);
NERVE_MAKE(EnemyStateReviveInsideScreen, AppearSign);

struct {
    NERVE_MAKE(EnemyStateReviveInsideScreen, Hide);
    NERVE_MAKE(EnemyStateReviveInsideScreen, Delay);
} NrvEnemyStateReviveInsideScreen;
}  // namespace

EnemyStateReviveInsideScreen::EnemyStateReviveInsideScreen(al::LiveActor* actor) : al::ActorStateBase("強制復活状態", actor) {
    initNerve(&NrvEnemyStateReviveInsideScreen.Hide, 0);
    al::calcQuat(&mReviveQuat, actor);
    mRevivePos.e = al::getTrans(actor).e;  // Hacky match, replace when sead::Vector3f's operator= is fixed
}

void EnemyStateReviveInsideScreen::appear() {
    setDead(false);

    if (al::isHideModel(mActor)) {
        mIsModelHidden = true;
    } else {
        al::hideModel(mActor);
        mIsModelHidden = false;
    }

    if (al::isInvalidClipping(mActor)) {
        mIsInvalidClipping = true;
    } else {
        al::invalidateClipping(mActor);
        mIsInvalidClipping = false;
    }

    al::setVelocityZero(mActor);
    mActor->getActorActionKeeper()->tryStartActionNoAnim("ReviveInsideScreen");
    if (mShouldHide)
        al::setNerve(this, &NrvEnemyStateReviveInsideScreen.Hide);
    else
        al::setNerve(this, &NrvEnemyStateReviveInsideScreen.Delay);
}

void EnemyStateReviveInsideScreen::kill() {
    al::stopSe(mActor, "RevivalSign", 0xFFFFFFFF, 0);
    setDead(true);
    if (!mIsModelHidden)
        al::showModel(mActor);
    if (!mIsInvalidClipping)
        al::validateClipping(mActor);
}

void EnemyStateReviveInsideScreen::startRevive() {
    al::setNerve(this, &AppearSign);
}

bool EnemyStateReviveInsideScreen::isDisappear() const {
    return al::isNerve(this, &NrvEnemyStateReviveInsideScreen.Hide) || al::isNerve(this, &NrvEnemyStateReviveInsideScreen.Delay);
}

void EnemyStateReviveInsideScreen::exeHide() {}

void EnemyStateReviveInsideScreen::exeDelay() {
    al::setNerveAtGreaterEqualStep(this, &AppearSign, 150);
}

void EnemyStateReviveInsideScreen::exeAppearSign() {
    if (al::isFirstStep(this)) {
        al::resetQuatPosition(mActor, mReviveQuat, mRevivePos);
        al::startAction(mActor, "AppearSign");
    }
    if (al::isGreaterEqualStep(this, 150)) {
        al::startHitReaction(mActor, "出現");
        kill();
    }
}
