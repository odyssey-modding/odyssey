#include "Player/PlayerState/PlayerStateHack.h"
#include <al/Library/Camera/CameraUtil.h>
#include <al/Library/Effect/EffectSystemInfo.h>
#include <al/Library/LiveActor/ActorActionFunction.h>
#include <al/Library/LiveActor/ActorFlagFunction.h>
#include <al/Library/LiveActor/ActorMovementFunction.h>
#include <al/Library/LiveActor/ActorPoseKeeper.h>
#include <al/Library/LiveActor/ActorSensorFunction.h>
#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/Math/MathUtil.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Nerve/NerveUtil.h>
#include "Player/CapFunction.h"
#include "Player/HackCap.h"
#include "Player/IPlayerModelChanger.h"
#include "Player/PlayerAnimator.h"
#include "Player/PlayerHackKeeper.h"

namespace {
NERVE_IMPL(PlayerStateHack, End);
NERVE_IMPL(PlayerStateHack, Hack);
NERVE_IMPL(PlayerStateHack, HackDemo);
NERVE_IMPL(PlayerStateHack, HackDemoPuppetable);
NERVE_MAKE(PlayerStateHack, End);
struct {
    NERVE_MAKE(PlayerStateHack, Hack);
    NERVE_MAKE(PlayerStateHack, HackDemoPuppetable);
    NERVE_MAKE(PlayerStateHack, HackDemo);
} nrvPlayerStateHack;
}  // namespace

PlayerStateHack::PlayerStateHack(al::LiveActor* parent, PlayerHackKeeper* hackKeeper, IPlayerModelChanger* modelChanger, PlayerAnimator* animator,
                                 HackCap* hackCap)
    : ActorStateBase("ひょうい", parent), mHackKeeper(hackKeeper), mModelChanger(modelChanger), mAnimator(animator), mHackCap(hackCap) {
    mIsStageStartHack = false;
    mNewSensorTrans = {0.0f, 0.0f, 0.0f};
    mSensorTrans = {0.0f, 0.0f, 0.0f};
    mTrans = {0.0f, 0.0f, 0.0f};
    mHackDemoStartLength = 0;
    mPossessTraceMtx = sead::Matrix34f::ident;
    mDemoModelMtx = sead::Matrix34f::ident;
    initNerve(&End, 0);
    al::setEffectFollowMtxPtr(parent, "PossessTrace", &mPossessTraceMtx);
}

void PlayerStateHack::appear() {
    setDead(false);
    if (mIsStageStartHack) {
        mIsStageStartHack = false;
        al::setNerve(this, &nrvPlayerStateHack.Hack);
        return;
    } else if (mHackKeeper->isPuppetable2()) {
        al::setNerve(this, &nrvPlayerStateHack.HackDemoPuppetable);
        return;
    } else {
        al::setNerve(this, &nrvPlayerStateHack.HackDemo);
    }
}

void PlayerStateHack::exeEnd() {}

void PlayerStateHack::exeHack() {
    if (mHackKeeper->isHack())
        return;
    al::copyPose(getParent(), mHackKeeper->getHack());
    al::setVelocity(getParent(), al::getVelocity(mHackKeeper->getHack()));
}

void PlayerStateHack::exeHackDemo() {
    sead::Vector3f frontDir;
    sead::Vector3f upDir;
    sead::Vector3f reverseFront;
    sead::Vector3f downDir;
    sead::Vector3f cameraFront;
    sead::Vector3f reverseCameraFront;

    auto parent = getParent();
    auto hackActor = mHackKeeper->getHack();

    if (al::isFirstStep(this)) {
        mAnimator->startAnim("Wait");
        al::offCollide(parent);
        al::setVelocityZero(parent);
        sead::Matrix34f sideFrontPosMtx = sead::Matrix34f::ident;
        frontDir = {0.0f, 0.0f, 0.0f};
        upDir = {0.0f, 0.0f, 0.0f};
        al::calcFrontDir(&frontDir, parent);
        al::calcUpDir(&upDir, parent);
        al::makeMtxSideFrontPos(&sideFrontPosMtx, -upDir, frontDir, mSensorTrans);
        mHackKeeper->appearHackDemoModel(sideFrontPosMtx, 0.02);
    } else if (al::isStep(this, 1)) {
        mModelChanger->hideModel();
    }
    s32 tmp = mHackDemoStartLength - 4;
    s32 nerveStep = tmp < 0 ? 0 : tmp;
    f32 nerveEastRate;
    if (!al::isFirstStep(this)) {
        if (!al::isLessStep(this, nerveStep)) {
            nerveEastRate = al::calcNerveEaseInValue(this, nerveStep, nerveStep + 5, 1.0, 0.02);
        } else {
            nerveEastRate = al::calcNerveEaseOutValue(this, 0, 5, 0.02, 1.0);
        }

    } else {
        nerveEastRate = 1.0f;
    }
    if (al::isStep(this, mHackDemoStartLength + 9)) {
        mHackCap->noticeHackMarioEnter();
    }
    tmp = mHackDemoStartLength - 15;
    nerveStep = tmp < 0 ? 0 : tmp;
    if (al::isStep(this, nerveStep)) {
        mHackCap->emitHackStartEffect();
    }
    if (al::isLessStep(this, mHackDemoStartLength)) {
        f32 nerveRate = al::calcNerveRate(this, mHackDemoStartLength);
        sead::Vector3f* capTrans = &al::getTrans(mHackCap);
        sead::Vector3f lerpedTrans = {0.0f, 0.0f, 0.0f};
        al::lerpVec(&lerpedTrans, mTrans, al::getTrans(hackActor), nerveRate);
        al::resetPosition(getParent(), lerpedTrans);
        sead::Vector3f beforeLerpSensorTrans = mNewSensorTrans;
        al::lerpVec(&mNewSensorTrans, mSensorTrans, *capTrans, nerveRate);

        sead::Vector3CalcCommon<f32>::multScalarAdd(mNewSensorTrans, sinf(nerveRate * 0.01745329f * 180.0f) * -400.0f, al::getGravity(getParent()),
                                                    mNewSensorTrans);
        sead::Vector3CalcCommon<f32>::sub(frontDir, mNewSensorTrans, beforeLerpSensorTrans);

        if (!al::tryNormalizeOrZero(&frontDir)) {
            sead::Vector3f* actorTrans = &al::getTrans(parent);
            sead::Vector3CalcCommon<f32>::sub(frontDir, *capTrans, *actorTrans);
            if (!al::tryNormalizeOrZero(&frontDir)) {
                al::calcFrontDir(&frontDir, parent);
            }
        }
        upDir = -al::getGravity(parent);
        if (al::isParallelDirection(upDir, frontDir, 0.01)) {
            al::calcFrontDir(&upDir, parent);
            if (al::isParallelDirection(upDir, frontDir, 0.01)) {
                al::calcUpDir(&upDir, parent);
            }
        }
        al::makeMtxFrontUpPos(&mPossessTraceMtx, frontDir, upDir, mNewSensorTrans);
        reverseFront = -frontDir;
        downDir = -upDir;
        cameraFront = {0.0f, 0.0f, 0.0f};

        al::calcCameraFront(&cameraFront, parent, 0);
        if (al::isParallelDirection(downDir, cameraFront, 0.01)) {
            if (al::isReverseDirection(downDir, cameraFront, 0.01)) {
                downDir *= -1;
            }
        } else if (!al::isParallelDirection(cameraFront, reverseFront, 0.01)) {
            sead::Quatf quat = sead::Quatf::unit;
            reverseCameraFront = -cameraFront;

            al::makeQuatAxisRotation(&quat, downDir, reverseCameraFront, reverseFront, 1.0);
            sead::Vector3CalcCommon<f32>::rotate(downDir, quat, downDir);
        }
        al::makeMtxSideFrontPos(&mDemoModelMtx, reverseFront, downDir, mNewSensorTrans);
        if (al::isStep(this, mHackDemoStartLength - 1)) {
            mHackKeeper->setPuppetable(true);
            al::startHitReactionHitEffect(getParent(), "ひょうい先に入る", al::getTrans(mHackCap));
        }
        if (!al::isFirstStep(this)) {
            mHackKeeper->updateHackDemoModel(mDemoModelMtx, nerveEastRate);
        }
    } else {
        mHackKeeper->updateHackDemoModel(mDemoModelMtx, nerveEastRate);
        mHackKeeper->deleteHackDemoModelEffect();
        al::tryDeleteEffect(getParent(), "PossessTrace");
        al::copyPose(getParent(), mHackKeeper->getHack());
        if (!mHackKeeper->getHackSensor() || !mHackKeeper->isHackDemoStarted()) {
            mHackKeeper->killHackDemoModel();
            mHackKeeper->recordHack();
            mHackCap->recordHack();
            al::startHitReaction(mHackCap, "ひょうい完了");
            al::setNerve(this, &nrvPlayerStateHack.Hack);
        }
    }
}

void PlayerStateHack::exeHackDemoPuppetable() {
    auto parent = getParent();
    if (al::isFirstStep(this)) {
        mAnimator->startAnim("Wait");
        mModelChanger->hideModel();
        al::offCollide(parent);
        al::setVelocityZero(parent);
        al::tryKillEmitterAndParticleAll(parent);
    }
    if (!mHackKeeper->getHackSensor() || !mHackKeeper->isHackDemoStarted()) {
        mHackCap->noticeHackDemoPuppetableEnd();
        mHackKeeper->recordHack();
        mHackCap->recordHack();
        al::setNerve(this, &nrvPlayerStateHack.Hack);
    }
}

bool PlayerStateHack::isEnableCancelHack() const {
    if (!al::isNerve(this, &nrvPlayerStateHack.Hack))
        return false;
    if (mHackKeeper->getHackSensor() && mHackKeeper->isStartedHacking())
        return false;
    if (!al::isGreaterEqualStep(this, 13))
        return false;
    return true;
}

bool PlayerStateHack::isEnableChangeState() const {
    if (mHackKeeper->isHack())
        return false;
    if (mHackKeeper->getHackSensor() && mHackKeeper->isStartedHacking())
        return false;
    if (al::isNerve(this, &nrvPlayerStateHack.HackDemo))
        return false;
    if (al::isNerve(this, &nrvPlayerStateHack.HackDemoPuppetable))
        return false;
    return true;
}

bool PlayerStateHack::isEnableModelSyncShowHide() const {
    return !al::isNerve(this, &nrvPlayerStateHack.Hack) || mHackKeeper->isHack();
}

bool PlayerStateHack::isIgnoreUpdateCollider() const {
    return isDead() || !al::isNerve(this, &End);
}

void PlayerStateHack::prepareEndHack() {
    al::startHitReaction(getParent(), "ひょうい終了");
    CapFunction::endHack(mHackCap, mAnimator);
    al::onCollide(getParent());
    mAnimator->startAnim("JumpEndHack");
    mModelChanger->showModel();
    mHackKeeper->killHackDemoModel();
    al::tryDeleteEffect(getParent(), "PossessTrace");
    al::setNerve(this, &End);
}

void PlayerStateHack::prepareStageStartHack() {
    auto actor = getParent();
    mIsStageStartHack = true;
    al::offCollide(actor);
    al::setVelocityZero(actor);
    al::tryKillEmitterAndParticleAll(actor);
    mModelChanger->hideModel();
    mHackKeeper->recordHack();
    mHackCap->recordHack();
}

void PlayerStateHack::prepareStartHack(const al::HitSensor* source, const al::HitSensor* target) {
    mHackCap->startHack();
    
    sead::Vector3f upDir;
    al::calcUpDir(&upDir, getParent());

    f32 sensorDistance = sead::Mathf::clampMin(al::calcDistance(source, target) - 200.0f, 0.0f) / 30.0f;
    s32 sensorDistInt = (s32)(sensorDistance >= 0 ? sensorDistance + 0.5f : sensorDistance - 0.5f);  // potential sead::Mathf func
    mHackDemoStartLength = sead::Mathi::clamp(sensorDistInt + 15, 15, 30);

    mTrans = al::getTrans(getParent());
    mNewSensorTrans = mSensorTrans = al::getSensorPos(target) + upDir * 0.0f;
    al::startHitReaction(getParent(), "ひょうい開始");
}