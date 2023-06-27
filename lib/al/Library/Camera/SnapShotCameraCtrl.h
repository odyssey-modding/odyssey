#pragma once

#include <al/Library/Nerve/NerveExecutor.h>
#include <al/Library/IUse/IUse.h>
#include <al/Library/Yaml/ByamlIter.h>
#include "gfx/seadCamera.h"

struct CameraParam {
    bool gotMin;
    bool gotMax;
    float mMinFovyDegree;
    float mMaxFovyDegree;
};

namespace al {
class SnapShotCameraSceneInfo;
class ICameraInput;

class SnapShotCameraCtrl : public al::NerveExecutor, public al::IUseAudioKeeper {
    al::SnapShotCameraSceneInfo* mCameraSceneInfo;
    CameraParam* mParam;
    bool mIsValidLookAtOffset;
    sead::Vector3f mLookAtOffset;
    sead::Vector3f vVar1;
    bool mIsValidZoomFovy;
    float mFovyDegree;
    float fVar2;
    float fVar3;
    float mMaxZoomOutFovyDegree;
    bool mIsValidRoll;
    float mRollDegree;
    float mRollTarget;
    unsigned int uVar2;
    bool bVar1;
public:
    SnapShotCameraCtrl(al::SnapShotCameraSceneInfo const*);
    void start(float);
    void load(al::ByamlIter const&);
    void startReset(int);
    void update(sead::LookAtCamera const&,al::IUseCollision const*,al::ICameraInput const*);
    void makeLookAtCameraPost(sead::LookAtCamera *)const;
    void makeLookAtCameraLast(sead::LookAtCamera *)const;
    void exeWait(void);
    void exeReset(void);

    float getFovyDegree() const { return mFovyDegree; };
};
}