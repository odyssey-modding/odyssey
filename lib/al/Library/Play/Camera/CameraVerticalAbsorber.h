#pragma once

#include <al/Library/Camera/CameraPoserFunction.h>
#include <al/Library/Nerve/Nerve.h>
#include <al/Library/Nerve/NerveExecutor.h>
#include <al/Library/Nerve/NerveKeeper.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Nerve/NerveUtil.h>
#include <al/Library/Yaml/ByamlIter.h>
#include <gfx/seadCamera.h>
#include <gfx/seadProjection.h>

namespace al {
class CameraPoser;
class CameraStartInfo;

class CameraVerticalAbsorber : public al::NerveExecutor {
private:
    const al::CameraPoser* mCameraPoser;
    sead::LookAtCamera mLookAtCamera;
    sead::PerspectiveProjection mProjection;
    sead::Vector3f mTargetInterp;
    float mLerp1;
    float mAbsorbScreenPosUp;
    float mAbsorbScreenPosDown;
    bool mAdvanceAbsorbUp;
    float mAdvanceAbsorbScreenPosUp;
    bool mIsExistCollisionUnderTarget;
    sead::Vector3f mUnderTargetCollisionPos;
    sead::Vector3f mUnderTargetCollisionNormal;
    float mLerp2;
    float mKeepInFrameOffsetUp;
    float mKeepInFrameOffsetDown;
    float mHighJumpJudgeSpeedV;
    sead::Vector3f mPrevTargetTrans;
    sead::Vector3f mTargetFront;
    sead::Vector3f mPrevTargetFront;
    bool mIsNoCameraPosAbsorb;
    bool mIsInvalidated;
    bool mUnusedBool;
    bool mIsStopUpdate;
    bool mIsKeepInFrame;

public:
    CameraVerticalAbsorber(const al::CameraPoser* cameraParent, bool isCameraPosAbsorb);
    ~CameraVerticalAbsorber();
    void exeAbsorb();
    void exeFollow();
    void exeFollowAbsolute();
    void exeFollowClimbPole();
    void exeFollowGround();
    void invalidate();
    bool isAbsorbing() const;
    bool isValid() const;
    void liverateAbsorb();
    void load(const al::ByamlIter&);
    void makeLookAtCamera(sead::LookAtCamera*) const;
    void start(const sead::Vector3f&, const al::CameraStartInfo&);
    void tryResetAbsorbVecIfInCollision(const sead::Vector3f&);
    void update();
};
static_assert(sizeof(CameraVerticalAbsorber) == 0x1b0, "blaah!");
};  // namespace al
