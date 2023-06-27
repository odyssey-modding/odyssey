#pragma once

#include <al/Library/Camera/CameraPoserFunction.h>
#include <al/Library/Nerve/Nerve.h>
#include <al/Library/Nerve/NerveExecutor.h>
#include <al/Library/Nerve/NerveKeeper.h>
#include <al/Library/Nerve/NerveUtil.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Yaml/ByamlIter.h>
#include <al/Library/Nerve/NerveExecutor.h>
#include <gfx/seadCamera.h>
#include <gfx/seadProjection.h>

namespace al {
    class CameraPoser;
    class CameraStartInfo;

    class CameraVerticalAbsorber : public al::NerveExecutor {
    public:
        CameraVerticalAbsorber(const al::CameraPoser *cameraParent, bool isCameraPosAbsorb);
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
        void load(const al::ByamlIter &);
        void makeLookAtCamera(sead::LookAtCamera *) const;
        void start(const sead::Vector3f &, const al::CameraStartInfo &);
        void tryResetAbsorbVecIfInCollision(const sead::Vector3f &);
        void update();

        const al::CameraPoser *mCameraPoser;           // 0x10
        sead::LookAtCamera mLookAtCamera;              // 0x18
        sead::PerspectiveProjection mProjection;       // 0x78
        sead::Vector3f mTargetInterp;                  // 0x138
        float mLerp1;                                  // 0x144
        float mAbsorbScreenPosUp;                      // 0x148
        float mAbsorbScreenPosDown;                    // 0x14c
        bool mAdvanceAbsorbUp;                         // 0x150
        float mAdvanceAbsorbScreenPosUp;               // 0x154
        bool isExistCollisionUnderTarget;              // 0x158
        sead::Vector3f mUnderTargetCollisionPos;       // 0x15c
        sead::Vector3f mUnderTargetCollisionNormal;    // 0x168
        float mLerp2;                                  // 0x174
        float mKeepInFrameOffsetUp;                    // 0x178
        float mKeepInFrameOffsetDown;                  // 0x17c
        float mHighJumpJudgeSpeedV;                    // 0x180
        sead::Vector3f mPrevTargetTrans;               // 0x184
        sead::Vector3f mTargetFront;                   // 0x190
        sead::Vector3f mPrevTargetFront;               // 0x19c
        bool isNoCameraPosAbsorb;                      // 0x1a8
        bool isInvalidated;                            // 0x1a9
        bool unusedBool;                               // 0x1aa
        bool isStopUpdate;                             // 0x1ab
        bool isKeepInFrame;                            // 0x1ac
    };
    static_assert(sizeof(CameraVerticalAbsorber) == 0x1B0, "blaah!");
};    // namespace al