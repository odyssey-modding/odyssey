#include "CameraVerticalAbsorber.h"
#include <al/Library/Math/MathUtil.h>
#include <al/Library/Yaml/ByamlUtil.h>

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
}    // namespace

namespace al {

    class CameraStartInfo {
    public:
        unsigned char unk[0x25];
        bool onGround;
    };

    void CameraVerticalAbsorber::exeFollowAbsolute() {
        mTargetInterp *= 0.8f;
    }

    void CameraVerticalAbsorber::invalidate() {
        isInvalidated = true;
        if (!al::isNerve(this, &NrvCameraVerticalAbsorber.FollowAbsolute))
            al::setNerve(this, &NrvCameraVerticalAbsorber.FollowAbsolute);
    }

    #ifdef NON_MATCHING
    void CameraVerticalAbsorber::start(const sead::Vector3<float> &pos, const al::CameraStartInfo &info) {
        alCameraPoserFunction::calcTargetFront(&mPrevTargetFront, mCameraPoser);

        mTargetInterp.x = 0.0f;
        mTargetInterp.y = 0.0f;
        mTargetInterp.z = 0.0f;

        mPrevTargetTrans = pos;

        if (unusedBool || isInvalidated || alCameraPoserFunction::isPlayerTypeNotTouchGround(mCameraPoser))
            return al::setNerve(this, &NrvCameraVerticalAbsorber.FollowAbsolute);
        if (alCameraPoserFunction::isTargetClimbPole(mCameraPoser))
            return al::setNerve(this, &NrvCameraVerticalAbsorber.FollowClimbPoleNoInterp);
        if (alCameraPoserFunction::isTargetGrabCeil(mCameraPoser))
            return al::setNerve(this, &NrvCameraVerticalAbsorber.FollowSlow);
        if (!info.onGround || alCameraPoserFunction::isTargetCollideGround(mCameraPoser))
            return al::setNerve(this, &NrvCameraVerticalAbsorber.FollowGround);

        mPrevTargetTrans = alCameraPoserFunction::getPreLookAtPos(mCameraPoser);

        sead::Vector3f target;

        alCameraPoserFunction::calcTargetGravity(&target, mCameraPoser);
        mTargetInterp = pos - mPrevTargetTrans;
        al::parallelizeVec(&mTargetInterp, target, mTargetInterp);
        al::setNerve(this, &NrvCameraVerticalAbsorber.Absorb);
    }
    #endif

    void CameraVerticalAbsorber::load(const al::ByamlIter &data) {
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

    #ifdef NON_MATCHING
    void CameraVerticalAbsorber::update() {
        if (isStopUpdate) return;
        sead::Vector3f gravity{};
        alCameraPoserFunction::calcTargetGravity(&gravity, mCameraPoser);
        mTargetInterp = mCameraPoser->getPosition() - mPrevTargetTrans;
        al::parallelizeVec(&mTargetInterp, gravity, mTargetInterp);
        mLookAtCamera.getPos() = mCameraPoser->getPosition();
        mLookAtCamera.getAt() = mCameraPoser->getTargetTrans();
        mLookAtCamera.getUp() = mCameraPoser->getCameraUp();
        if (mLookAtCamera.getUp().length() > 0.f)
            mLookAtCamera.getUp().normalize();
        if (!unusedBool && !isInvalidated) {
            mLookAtCamera.getAt() -= mTargetInterp;
            if (!isNoCameraPosAbsorb) {
                mLookAtCamera.getPos() -= mTargetInterp;
            }
        }
        mLookAtCamera.doUpdateMatrix(&mLookAtCamera.getMatrix());
        mProjection.set(alCameraPoserFunction::getNear(mCameraPoser),
                        alCameraPoserFunction::getFar(mCameraPoser),
                        sead::Mathf::deg2rad(mCameraPoser->getFovyDegree()),
                        alCameraPoserFunction::getAspect(mCameraPoser));
        alCameraPoserFunction::calcTargetFront(&mTargetFront, mCameraPoser);
        if (!al::isNerve(this, &NrvCameraVerticalAbsorber.FollowGround) && alCameraPoserFunction::isTargetCollideGround(mCameraPoser)) {
            al::setNerve(this, &NrvCameraVerticalAbsorber.FollowGround);
        }
        if (!al::isNerve(this, &NrvCameraVerticalAbsorber.FollowAbsolute) && alCameraPoserFunction::isPlayerTypeNotTouchGround(mCameraPoser)) {
            al::setNerve(this, &NrvCameraVerticalAbsorber.FollowAbsolute);
        }
        updateNerve();
        sead::Vector3f prevTargetTrans = sead::Vector3f::zero;
        if (!isKeepInFrame) {
            prevTargetTrans = mTargetInterp;
        } else {
            sead::Vector3f offsetTrans = sead::Vector3f::zero;
            alCameraPoserFunction::calcTargetTransWithOffset(&offsetTrans, mCameraPoser);
            alCameraPoserFunction::calcOffsetCameraKeepInFrameV(&gravity, &mLookAtCamera,
                                                                offsetTrans, mCameraPoser, mKeepInFrameOffsetUp,
                                                                alCameraPoserFunction::isPlayerTypeHighJump(mCameraPoser) ? 300.f : mKeepInFrameOffsetDown);
            prevTargetTrans = mTargetInterp - gravity;

        }
        mPrevTargetTrans = mCameraPoser->getTargetTrans() - prevTargetTrans;
        mPrevTargetFront = mTargetFront;
    }
    #endif

    void CameraVerticalAbsorber::exeFollowGround(){

    };
}    // namespace al