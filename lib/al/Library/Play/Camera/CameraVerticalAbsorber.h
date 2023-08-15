#pragma once

#include <al/Library/Nerve/NerveExecutor.h>
#include <gfx/seadCamera.h>
#include <gfx/seadProjection.h>

namespace al {
class ByamlIter;
class CameraPoser;
struct CameraStartInfo;

class CameraVerticalAbsorber : public al::NerveExecutor {
private:
    const al::CameraPoser* mCameraPoser;
    sead::LookAtCamera mLookAtCamera;
    sead::PerspectiveProjection mProjection;
    sead::Vector3f mTargetInterp;
    f32 mLerp1;
    f32 mAbsorbScreenPosUp;
    f32 mAbsorbScreenPosDown;
    bool mAdvanceAbsorbUp;
    f32 mAdvanceAbsorbScreenPosUp;
    bool mIsExistCollisionUnderTarget;
    sead::Vector3f mUnderTargetCollisionPos;
    sead::Vector3f mUnderTargetCollisionNormal;
    f32 mLerp2;
    f32 mKeepInFrameOffsetUp;
    f32 mKeepInFrameOffsetDown;
    f32 mHighJumpJudgeSpeedV;
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
};  // namespace al
