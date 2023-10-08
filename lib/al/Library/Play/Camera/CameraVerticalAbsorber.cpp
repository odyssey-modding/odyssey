#include "CameraVerticalAbsorber.h"
#include <al/Library/Camera/CameraPoserFunction.h>
#include <al/Library/Camera/CameraStartInfo.h>
#include <al/Library/Math/MathAngleUtil.h>
#include <al/Library/Math/MathLerpUtil.h>
#include <al/Library/Math/MathVectorUtil.h>
#include <al/Library/Nerve/Nerve.h>
#include <al/Library/Nerve/NerveKeeper.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Nerve/NerveUtil.h>
#include <al/Library/Yaml/ByamlUtil.h>
#include <al/Library/Yaml/ByamlIter.h>

namespace {
using namespace al;
NERVE_IMPL(CameraVerticalAbsorber, FollowGround);
NERVE_IMPL(CameraVerticalAbsorber, FollowAbsolute);
NERVE_IMPL_(CameraVerticalAbsorber, FollowClimbPoleNoInterp, Follow);
NERVE_IMPL_(CameraVerticalAbsorber, FollowSlow, Absorb);
NERVE_IMPL(CameraVerticalAbsorber, Absorb);
NERVE_IMPL(CameraVerticalAbsorber, Follow);
NERVE_IMPL(CameraVerticalAbsorber, FollowClimbPole);

struct {
    NERVE_MAKE(CameraVerticalAbsorber, FollowGround);
    NERVE_MAKE(CameraVerticalAbsorber, FollowAbsolute);
    NERVE_MAKE(CameraVerticalAbsorber, FollowClimbPoleNoInterp);
    NERVE_MAKE(CameraVerticalAbsorber, FollowSlow);
    NERVE_MAKE(CameraVerticalAbsorber, Absorb);
    NERVE_MAKE(CameraVerticalAbsorber, Follow);
    NERVE_MAKE(CameraVerticalAbsorber, FollowClimbPole);
} NrvCameraVerticalAbsorber;
}  // namespace

namespace al {

void CameraVerticalAbsorber::exeFollowAbsolute() {
    mTargetInterp *= 0.8f;
}

void CameraVerticalAbsorber::invalidate() {
    mIsInvalidated = true;
    if (!al::isNerve(this, &NrvCameraVerticalAbsorber.FollowAbsolute))
        al::setNerve(this, &NrvCameraVerticalAbsorber.FollowAbsolute);
}

void CameraVerticalAbsorber::start(const sead::Vector3f& pos, const al::CameraStartInfo& info) {
    alCameraPoserFunction::calcTargetFront(&mPrevTargetFront, mCameraPoser);

    mTargetInterp = sead::Vector3f(0, 0, 0);

    mPrevTargetTrans.e = pos.e;

    if (mUnusedBool || mIsInvalidated || alCameraPoserFunction::isPlayerTypeNotTouchGround(mCameraPoser))
        return al::setNerve(this, &NrvCameraVerticalAbsorber.FollowAbsolute);
    if (alCameraPoserFunction::isTargetClimbPole(mCameraPoser))
        return al::setNerve(this, &NrvCameraVerticalAbsorber.FollowClimbPoleNoInterp);
    if (alCameraPoserFunction::isTargetGrabCeil(mCameraPoser))
        return al::setNerve(this, &NrvCameraVerticalAbsorber.FollowSlow);
    if (!info.mIsOnGround || alCameraPoserFunction::isTargetCollideGround(mCameraPoser))
        return al::setNerve(this, &NrvCameraVerticalAbsorber.FollowGround);

    mPrevTargetTrans.e = alCameraPoserFunction::getPreLookAtPos(mCameraPoser).e;

    const al::CameraPoser* poser = mCameraPoser;

    sead::Vector3f target(0, 0, 0);

    alCameraPoserFunction::calcTargetGravity(&target, poser);

    mTargetInterp = pos - mPrevTargetTrans;
    al::parallelizeVec(&mTargetInterp, target, mTargetInterp);
    al::setNerve(this, &NrvCameraVerticalAbsorber.Absorb);
}

void CameraVerticalAbsorber::load(const al::ByamlIter& data) {
    al::ByamlIter it;
    if (!data.tryGetIterByKey(&it, "VerticalAbsorb"))
        return;

    al::tryGetByamlF32(&mAbsorbScreenPosUp, it, "AbsorbScreenPosUp");
    al::tryGetByamlF32(&mAbsorbScreenPosDown, it, "AbsorbScreenPosDown");
    al::tryGetByamlF32(&mHighJumpJudgeSpeedV, it, "HighJumpJudgeSpeedV");
    al::ByamlIter it2;

    if (!it.tryGetIterByKey(&it2, "AdvanceAbsorbUp"))
        return;
    mAdvanceAbsorbUp = true;
    mAdvanceAbsorbScreenPosUp = al::getByamlKeyFloat(it2, "AdvanceAbsorbScreenPosUp");
};

// NON_MATCHING
void CameraVerticalAbsorber::update() {
    if (mIsStopUpdate)
        return;
    sead::Vector3f gravity{};
    alCameraPoserFunction::calcTargetGravity(&gravity, mCameraPoser);
    mTargetInterp = mCameraPoser->getPosition() - mPrevTargetTrans;
    al::parallelizeVec(&mTargetInterp, gravity, mTargetInterp);
    mLookAtCamera.getPos() = mCameraPoser->getPosition();
    mLookAtCamera.getAt() = mCameraPoser->getTargetTrans();
    mLookAtCamera.getUp() = mCameraPoser->getCameraUp();
    if (mLookAtCamera.getUp().length() > 0.0f)
        mLookAtCamera.getUp().normalize();
    if (!mUnusedBool && !mIsInvalidated) {
        mLookAtCamera.getAt() -= mTargetInterp;
        if (!mIsNoCameraPosAbsorb) {
            mLookAtCamera.getPos() -= mTargetInterp;
        }
    }
    mLookAtCamera.doUpdateMatrix(&mLookAtCamera.getMatrix());
    mProjection.set(alCameraPoserFunction::getNear(mCameraPoser), alCameraPoserFunction::getFar(mCameraPoser),
                    sead::Mathf::deg2rad(mCameraPoser->getFovyDegree()), alCameraPoserFunction::getAspect(mCameraPoser));
    alCameraPoserFunction::calcTargetFront(&mTargetFront, mCameraPoser);
    if (!al::isNerve(this, &NrvCameraVerticalAbsorber.FollowGround) && alCameraPoserFunction::isTargetCollideGround(mCameraPoser)) {
        al::setNerve(this, &NrvCameraVerticalAbsorber.FollowGround);
    }
    if (!al::isNerve(this, &NrvCameraVerticalAbsorber.FollowAbsolute) && alCameraPoserFunction::isPlayerTypeNotTouchGround(mCameraPoser)) {
        al::setNerve(this, &NrvCameraVerticalAbsorber.FollowAbsolute);
    }
    updateNerve();
    sead::Vector3f prevTargetTrans = sead::Vector3f::zero;
    if (!mIsKeepInFrame) {
        prevTargetTrans = mTargetInterp;
    } else {
        sead::Vector3f offsetTrans = sead::Vector3f::zero;
        alCameraPoserFunction::calcTargetTransWithOffset(&offsetTrans, mCameraPoser);
        alCameraPoserFunction::calcOffsetCameraKeepInFrameV(&gravity, &mLookAtCamera, offsetTrans, mCameraPoser, mKeepInFrameOffsetUp,
                                                            alCameraPoserFunction::isPlayerTypeHighJump(mCameraPoser) ? 300.0f :
                                                                                                                        mKeepInFrameOffsetDown);
        prevTargetTrans = mTargetInterp - gravity;
    }
    mPrevTargetTrans = mCameraPoser->getTargetTrans() - prevTargetTrans;
    mPrevTargetFront = mTargetFront;
}

void CameraVerticalAbsorber::exeFollowGround(){

};
}  // namespace al
