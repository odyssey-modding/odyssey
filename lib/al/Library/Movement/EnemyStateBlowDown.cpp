#include "EnemyStateBlowDown.h"
#include "al/Library/LiveActor/ActorActionFunction.h"
#include "al/Library/LiveActor/ActorClippingFunction.h"
#include "al/Library/LiveActor/ActorCollisionFunction.h"
#include "al/Library/LiveActor/ActorFlagFunction.h"
#include "al/Library/LiveActor/ActorMovementFunction.h"
#include "al/Library/LiveActor/ActorPoseKeeper.h"
#include "al/Library/LiveActor/ActorSensorFunction.h"
#include "al/Library/Math/MathAngleUtil.h"
#include "al/Library/Math/MathLengthUtil.h"

namespace al {
void EnemyStateBlowDown::start(al::HitSensor const* sensor) {
    sead::Vector3f dir = al::getSensorPos(sensor) - al::getTrans(mActor);

    al::verticalizeVec(&dir, al::getGravity(mActor), dir);

    if (!al::tryNormalizeOrZero(&dir))
        al::calcFrontDir(&dir, mActor);

    start(-dir);
}

void EnemyStateBlowDown::start(sead::Vector3f const& dir) {
    if (mParam->mFaceAwayFromActor) {
        al::faceToDirection(mActor, -dir);
    }

    auto actor = mActor;
    auto direction = dir * mParam->mGravityStrength;
    auto gravity = al::getGravity(actor);
    auto velocity = gravity * mParam->mVelocityStrength;
    al::setVelocity(actor, direction - velocity);
}

void EnemyStateBlowDown::start(al::HitSensor const* sensor1, al::HitSensor const* sensor2) {
    sead::Vector3f dir = al::getSensorPos(sensor1) - al::getSensorPos(sensor2);

    al::verticalizeVec(&dir, al::getGravity(mActor), dir);

    if (!al::tryNormalizeOrZero(&dir))
        al::calcFrontDir(&dir, mActor);

    start(-dir);
}

void EnemyStateBlowDown::start(al::LiveActor const* actor) {
    sead::Vector3f dir;
    al::calcFrontDir(&dir, actor);

    start(-dir);
}

void EnemyStateBlowDown::appear() {
    mIsDead = false;
    if (al::isInvalidClipping(mActor))
        mIsInvalidClipping = true;
    else {
        al::invalidateClipping(mActor);
        mIsInvalidClipping = false;
    }
    mBlowDownTimer = 0;
}

void EnemyStateBlowDown::kill() {
    mIsDead = true;
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
    if (mParam->mBlowDownLength <= mBlowDownTimer)
        return kill();
    if (mParam->mActionName && al::isActionOneTime(mActor, mParam->mActionName) && al::isActionEnd(mActor))
        return kill();
    if (al::isExistActorCollider(mActor) && al::isOnGround(mActor, 0))
        return kill();

    al::addVelocityToGravity(mActor, mParam->mVelocityMultiplier);
    al::scaleVelocity(mActor, mParam->mVelocityScale);
    this->mBlowDownTimer++;
}

EnemyStateBlowDownParam::EnemyStateBlowDownParam() {}

EnemyStateBlowDownParam::EnemyStateBlowDownParam(char const* actionName) {  // tools/check doesn't want to find this function for some reason
    mActionName = actionName;
}

EnemyStateBlowDownParam::EnemyStateBlowDownParam(char const* actionName, f32 gravityStrength, f32 velocityStrength, f32 velocityMultiplier,
                                                 f32 velocityScale, s32 blowDownLength, bool faceAwayFromActor) {
    mActionName = actionName;
    mGravityStrength = gravityStrength;
    mVelocityStrength = velocityStrength;
    mVelocityMultiplier = velocityMultiplier;
    mVelocityScale = velocityScale;
    mBlowDownLength = blowDownLength;
    mFaceAwayFromActor = faceAwayFromActor;
}

}  // namespace al