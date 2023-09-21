#include "Enemy/EnemyStateWander.h"
#include <al/Library/LiveActor/ActorActionFunction.h>
#include <al/Library/LiveActor/ActorCollisionFunction.h>
#include <al/Library/LiveActor/ActorMovementFunction.h>
#include <al/Library/LiveActor/ActorPoseKeeper.h>
#include <al/Library/Math/MathRandomUtil.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Nerve/NerveUtil.h>

namespace {
NERVE_IMPL(EnemyStateWander, Wait);
NERVE_IMPL(EnemyStateWander, Walk);
NERVE_IMPL(EnemyStateWander, Fall);

struct {
    NERVE_MAKE(EnemyStateWander, Wait);
    NERVE_MAKE(EnemyStateWander, Walk);
    NERVE_MAKE(EnemyStateWander, Fall);
} NrvEnemyStateWander;

}  // namespace

EnemyStateWander::EnemyStateWander(al::LiveActor* actor, const char* stateName) : al::ActorStateBase("さんぽ状態", actor) {
    mRandNum = 0;
    mWalkSpeed = -1.0f;
    mStateName = stateName;
    mIsHalfProbability = false;
    initNerve(&NrvEnemyStateWander.Wait, 0);
};

void EnemyStateWander::appear() {
    mIsDead = false;
    al::setNerve(this, &NrvEnemyStateWander.Walk);
}

void EnemyStateWander::exeWait() {
    if (al::isFirstStep(this)) {
        al::startAction(mActor, "Wait");
        mRandNum = al::getRandom(60);
    }
    if (al::isGreaterEqualStep(this, mRandNum + 120)) {
        return al::setNerve(this, &NrvEnemyStateWander.Walk);
    }
    if (!al::isOnGround(mActor, 0))
        return al::setNerve(this, &NrvEnemyStateWander.Fall);
    if (al::isFallNextMove(mActor, al::getVelocity(mActor), 50.0f, 200.0f)) {
        al::scaleVelocity(mActor, -1.0f);
        al::setVelocityY(mActor, 0.0f);
    }
    al::scaleVelocity(mActor, 0.7f);
    al::addVelocityToGravityFittedGround(mActor, 2.0f, 0);
}

void EnemyStateWander::exeWalk() {
    if (al::isFirstStep(this)) {
        al::startAction(mActor, mStateName);
        mRandNum = al::getRandom(50);
        mIsHalfProbability = al::isHalfProbability();
    }
    if (al::isGreaterEqualStep(this, mRandNum + 100))
        return al::setNerve(this, &NrvEnemyStateWander.Wait);
    if (!al::isOnGround(mActor, 0))
        return al::setNerve(this, &NrvEnemyStateWander.Fall);
    f32 directionDegree = 1.0f;
    if (!mIsHalfProbability)
        directionDegree = -1.0f;
    al::rotateQuatYDirDegree(mActor, directionDegree);

    sead::Vector3f frontDir = sead::Vector3f::zero;
    al::calcFrontDir(&frontDir, mActor);

    if (mWalkSpeed <= 0.0f)
        mWalkSpeed = 1.0f;
    if (al::isFallNextMove(mActor, (mWalkSpeed * frontDir) + al::getVelocity(mActor), 50.0f, 200.0f)) {
        al::scaleVelocity(mActor, -1.0f);
        al::setVelocityY(mActor, 0.0f);
    } else {
        al::addVelocityToDirection(mActor, frontDir, mWalkSpeed);
    }
    al::scaleVelocity(mActor, 0.7f);
    al::addVelocityToGravityFittedGround(mActor, 2.0f, 0);
}

void EnemyStateWander::exeFall() {
    if (al::isFirstStep(this))
        al::startAction(mActor, "Fall");
    if (!al::isOnGround(mActor, 0)) {
        al::scaleVelocity(mActor, 0.98f);
        al::addVelocityToGravity(mActor, 2.0f);
    } else
        al::setNerve(this, &NrvEnemyStateWander.Wait);
}

bool EnemyStateWander::isWait() const {
    return al::isNerve(this, &NrvEnemyStateWander.Wait);
}

bool EnemyStateWander::isWalk() const {
    return al::isNerve(this, &NrvEnemyStateWander.Walk);
}

bool EnemyStateWander::isFall() const {
    return al::isNerve(this, &NrvEnemyStateWander.Fall);
}

void EnemyStateWander::changeWalkAnim(const char* animName) {
    if (al::isActionPlaying(mActor, mStateName))
        al::startAction(mActor, animName);
    mStateName = animName;
}
