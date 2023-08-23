#include "Player/PlayerState/PlayerStateHack.h"
#include "Player/PlayerHackKeeper.h"
#include "Player/PlayerAnimator.h"
#include "Player/IPlayerModelChanger.h"
#include "Player/HackCap.h"
#include "Player/CapFunction.h"
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Effect/EffectSystemInfo.h>
#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/Nerve/NerveUtil.h>
#include <al/Library/LiveActor/ActorPoseKeeper.h>
#include <al/Library/LiveActor/ActorMovementFunction.h>
#include <al/Library/LiveActor/ActorFlagFunction.h>
#include <al/Library/LiveActor/ActorActionFunction.h>
#include <al/Library/LiveActor/ActorSensorFunction.h>
#include <al/Library/Math/MathUtil.h>
#include <al/Library/Camera/CameraUtil.h>

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
}

PlayerStateHack::PlayerStateHack(al::LiveActor *parent, PlayerHackKeeper *hackKeeper, IPlayerModelChanger *modelChanger,
                                 PlayerAnimator *animator, HackCap *hackCap) : ActorStateBase("ひょうい", parent),
                                 mHackKeeper(hackKeeper), mModelChanger(modelChanger), mAnimator(animator),
                                 mHackCap(hackCap) {
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
    }
    if (mHackKeeper->isPuppetable2()) {
        al::setNerve(this, &nrvPlayerStateHack.HackDemoPuppetable);
        return;
    }
    al::setNerve(this, &nrvPlayerStateHack.HackDemo);
}

void PlayerStateHack::exeEnd() {

}

void PlayerStateHack::exeHack() {
    if (mHackKeeper->isHack())
        return;
    al::copyPose(getActor(), mHackKeeper->getHack());
    al::setVelocity(getActor(), al::getVelocity(mHackKeeper->getHack()));
}

void PlayerStateHack::exeHackDemo() {
    sead::Vector3f frontDir;
    sead::Vector3f upDir;
    sead::Vector3f reverseFront;
    sead::Vector3f downDir;
    sead::Vector3f cameraFront;
    sead::Vector3f reverseCameraFront;

    auto actor = getActor();
    auto hackActor = mHackKeeper->getHack();

    if (al::isFirstStep(this)) {
        mAnimator->startAnim("Wait");
        al::offCollide(actor);
        al::setVelocityZero(actor);
        sead::Matrix34f sideFrontPosMtx = sead::Matrix34f::ident;
        frontDir = {0.0f, 0.0f, 0.0f};
        upDir = {0.0f, 0.0f, 0.0f};
        al::calcFrontDir(&frontDir, actor);
        al::calcUpDir(&upDir, actor);
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
        al::resetPosition(getActor(), lerpedTrans);
        sead::Vector3f beforeLerpSensorTrans = mNewSensorTrans;
        al::lerpVec(&mNewSensorTrans, mSensorTrans, *capTrans, nerveRate);

        sead::Vector3CalcCommon<f32>::multScalarAdd(mNewSensorTrans, sinf(nerveRate * 0.01745329f * 180.0f) * -400.0f,
                                                    al::getGravity(getActor()), mNewSensorTrans);
        sead::Vector3CalcCommon<f32>::sub(frontDir, mNewSensorTrans, beforeLerpSensorTrans);

        if (!al::tryNormalizeOrZero(&frontDir)) {
            sead::Vector3f* actorTrans = &al::getTrans(actor);
            sead::Vector3CalcCommon<f32>::sub(frontDir, *capTrans, *actorTrans);
            if (!al::tryNormalizeOrZero(&frontDir)) {
                al::calcFrontDir(&frontDir, actor);
            }
        }
        upDir = -al::getGravity(actor);
        if (al::isParallelDirection(upDir, frontDir, 0.01)) {
            al::calcFrontDir(&upDir, actor);
            if (al::isParallelDirection(upDir, frontDir, 0.01)) {
                al::calcUpDir(&upDir, actor);
            }
        }
        al::makeMtxFrontUpPos(&mPossessTraceMtx, frontDir, upDir, mNewSensorTrans);
        reverseFront = -frontDir;
        downDir = -upDir;
        cameraFront = {0.0f, 0.0f, 0.0f};

        al::calcCameraFront(&cameraFront, actor, 0);
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
            al::startHitReactionHitEffect(getActor(), "ひょうい先に入る", al::getTrans(mHackCap));
        }
        if (!al::isFirstStep(this)) {
            mHackKeeper->updateHackDemoModel(mDemoModelMtx, nerveEastRate);
        }
    } else {
        mHackKeeper->updateHackDemoModel(mDemoModelMtx, nerveEastRate);
        mHackKeeper->deleteHackDemoModelEffect();
        al::tryDeleteEffect(getActor(), "PossessTrace");
        al::copyPose(getActor(), mHackKeeper->getHack());
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
    auto actor = getActor();
    if (al::isFirstStep(this)) {
        mAnimator->startAnim("Wait");
        mModelChanger->hideModel();
        al::offCollide(actor);
        al::setVelocityZero(actor);
        al::tryKillEmitterAndParticleAll(actor);
    }
    if (!mHackKeeper->getHackSensor() || !mHackKeeper->isHackDemoStarted()) {
        mHackCap->noticeHackDemoPuppetableEnd();
        mHackKeeper->recordHack();
        mHackCap->recordHack();
        al::setNerve(this, &nrvPlayerStateHack.Hack);
    }
}

bool PlayerStateHack::isEnableCancelHack() const {
    if (al::isNerve(this, &nrvPlayerStateHack.Hack) && (!mHackKeeper->getHackSensor() || !mHackKeeper->isStartedHacking())) {
        return al::isGreaterEqualStep(this, 13);
    }
    return false;
}

bool PlayerStateHack::isEnableChangeState() const {
    auto hackKeeper = mHackKeeper;
    if (hackKeeper->isHack() || (hackKeeper->getHackSensor() && hackKeeper->isStartedHacking()) || al::isNerve(this, &nrvPlayerStateHack.HackDemo)) {
        return false;
    } else {
        return !al::isNerve(this, &nrvPlayerStateHack.HackDemoPuppetable);
    }
}

bool PlayerStateHack::isEnableModelSyncShowHide() const {
    if (al::isNerve(this, &nrvPlayerStateHack.Hack))
        return mHackKeeper->isHack();
    else
        return true;
}

bool PlayerStateHack::isIgnoreUpdateCollider() const {
    if (isDead())
        return true;
    return !al::isNerve(this, &End);
}

void PlayerStateHack::prepareEndHack() {
    al::startHitReaction(getActor(), "ひょうい終了");
    CapFunction::endHack(mHackCap, mAnimator);
    al::onCollide(getActor());
    mAnimator->startAnim("JumpEndHack");
    mModelChanger->showModel();
    mHackKeeper->killHackDemoModel();
    al::tryDeleteEffect(getActor(), "PossessTrace");
    al::setNerve(this, &End);
}

void PlayerStateHack::prepareStageStartHack() {
    auto actor = getActor();
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
    al::calcUpDir(&upDir, getActor());
    f32 sensorDistance = al::calcDistance(source, target);
    sensorDistance -= 200.0f;
    sensorDistance = (sensorDistance < 0.0f ? 0.0f : sensorDistance)/30.f;
    s32 sensorDistInt = (s32)(sensorDistance >= 0 ? sensorDistance + 0.5f : sensorDistance - 0.5f);

    s32 newSensorDistInt = (sensorDistInt + 15) > 30 ? 30 : sensorDistInt + 15;

    mHackDemoStartLength = sensorDistInt < 0 ? 15 : newSensorDistInt;
    mTrans = al::getTrans(getActor());
    sead::Vector3f sensorTrans = al::getSensorPos(target) + upDir * 0.0f;

    mSensorTrans = sensorTrans;
    mNewSensorTrans = sensorTrans;

    al::startHitReaction(getActor(), "ひょうい開始");

}