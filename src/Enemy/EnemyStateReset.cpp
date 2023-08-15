#include "Enemy/EnemyStateReset.h"
#include <al/Library/LiveActor/ActorActionFunction.h>
#include <al/Library/LiveActor/ActorAnimFunction.h>
#include <al/Library/LiveActor/ActorModelFunction.h>
#include <al/Library/LiveActor/ActorMovementFunction.h>
#include <al/Library/LiveActor/ActorSensorFunction.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Nerve/NerveUtil.h>
#include <al/Library/Placement/PlacementFunction.h>
#include <al/Library/Player/PlayerHolder.h>
#include "Util/Hack.h"

namespace {
NERVE_IMPL(EnemyStateReset, Wait);

struct {
    NERVE_MAKE(EnemyStateReset, Wait);
} NrvEnemyStateReset;

}  // namespace

EnemyStateReset::EnemyStateReset(al::LiveActor* actor, const al::ActorInitInfo& info, EnemyCap* cap) : al::ActorStateBase("リセット状態", actor) {
    mEnemyCap = cap;

    initNerve(&NrvEnemyStateReset.Wait, 0);
    al::tryGetTrans(&mPos, info);
    al::tryGetRotate(&mRot, info);
    al::tryGetArg(&mIsRevive, info, "IsRevive");
}

void EnemyStateReset::appear() {
    auto actor = mActor;  // getting the actor in each function call below causes mismatch, have to declare a variable up here for it

    mIsDead = false;
    if (!mIsRevive)
        return actor->kill();

    al::setVelocityZero(actor);
    al::invalidateClipping(actor);
    al::hideModelIfShow(actor);
    al::stopAction(actor);
    rs::startReset(actor);

    if (!mInvalidateSensors)
        al::invalidateHitSensors(actor);

    al::setNerve(this, &NrvEnemyStateReset.Wait);
}

void EnemyStateReset::kill() {
    mIsDead = true;
    if (!mIsRevive)
        return;

    auto actor = mActor;

    al::validateClipping(actor);
    al::showModelIfHide(actor);
    rs::endReset(actor);
    al::restartAction(actor);
    if (!mInvalidateSensors)
        al::validateHitSensors(actor);
    if (rs::tryAppearEnemyCap(mEnemyCap))
        al::tryStartVisAnimIfExist(mActor, "CapOn");  // mActor is used here instead of the declared actor variable. Requires for match
}

void EnemyStateReset::exeWait() {
    if (al::isStep(this, 2))
        al::resetRotatePosition(mActor, mRot, mPos);
    if (al::isGreaterEqualStep(this, 2) && al::isResetablePlayerPos(mActor, mValidDistance))
        kill();
}