#include <al/Library/Movement/EnemyStateBlowDown.h>
#include <al/Library/LiveActor/ActorActionFunction.h>
#include <al/Library/LiveActor/ActorClippingFunction.h>
#include <al/Library/LiveActor/ActorCollisionFunction.h>
#include <al/Library/LiveActor/ActorFlagFunction.h>
#include <al/Library/LiveActor/ActorMovementFunction.h>
#include <al/Library/LiveActor/ActorPoseKeeper.h>
#include <al/Library/LiveActor/ActorSensorFunction.h>
#include <al/Library/Math/MathAngleUtil.h>
#include <al/Library/Math/MathLengthUtil.h>
#include <al/Library/Movement/EnemyStateBlowDownParam.h>

namespace al {
void EnemyStateBlowDown::start(const al::HitSensor* sensor) {
    sead::Vector3f dir = al::getSensorPos(sensor) - al::getTrans(mActor);

    al::verticalizeVec(&dir, al::getGravity(mActor), dir);

    if (!al::tryNormalizeOrZero(&dir))
        al::calcFrontDir(&dir, mActor);

    start(-dir);
}

void EnemyStateBlowDown::start(const sead::Vector3f& dir) {
    if (mParam->mFaceAwayFromActor) {
        al::faceToDirection(mActor, -dir);
    }

    auto* actor = mActor;
    sead::Vector3f direction = dir * mParam->mGravityStrength;
    sead::Vector3f gravity = al::getGravity(actor);
    sead::Vector3f velocity = gravity * mParam->mVelocityStrength;
    al::setVelocity(actor, direction - velocity);
}

void EnemyStateBlowDown::start(const al::HitSensor* sensor1, const al::HitSensor* sensor2) {
    sead::Vector3f dir = al::getSensorPos(sensor1) - al::getSensorPos(sensor2);

    al::verticalizeVec(&dir, al::getGravity(mActor), dir);

    if (!al::tryNormalizeOrZero(&dir))
        al::calcFrontDir(&dir, mActor);

    start(-dir);
}

void EnemyStateBlowDown::start(const al::LiveActor* actor) {
    sead::Vector3f dir;
    al::calcFrontDir(&dir, actor);

    start(-dir);
}

void EnemyStateBlowDown::appear() {
    setDead(false);
    if (al::isInvalidClipping(mActor))
        mIsInvalidClipping = true;
    else {
        al::invalidateClipping(mActor);
        mIsInvalidClipping = false;
    }
    mBlowDownTimer = 0;
}

void EnemyStateBlowDown::kill() {
    setDead(true);
    if (!mIsInvalidClipping)
        al::validateClipping(mActor);
}

void EnemyStateBlowDown::control() {
    if (mBlowDownTimer == 0) {
        if (mParam->mActionName)
            al::startAction(mActor, mParam->mActionName);
        if (al::isExistActorCollider(mActor))
            al::onCollide(mActor);
    }
    if ((mParam->mBlowDownLength <= mBlowDownTimer) ||
        (mParam->mActionName && al::isActionOneTime(mActor, mParam->mActionName) && al::isActionEnd(mActor)) ||
        (al::isExistActorCollider(mActor) && al::isOnGround(mActor, 0))) {
        kill();
        return;
    }
    al::addVelocityToGravity(mActor, mParam->mVelocityMultiplier);
    al::scaleVelocity(mActor, mParam->mVelocityScale);
    mBlowDownTimer++;
}
}  // namespace al