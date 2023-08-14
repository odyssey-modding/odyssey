#pragma once

#include <al/Library/Audio/AudioKeeper.h>
#include <al/Library/Collision/CollisionDirector.h>
#include <al/Library/Nerve/NerveExecutor.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Yaml/ByamlIter.h>
#include <al/Library/Yaml/ByamlUtil.h>
#include <gfx/seadCamera.h>

namespace al {
class SnapShotCameraSceneInfo;
class ICameraInput;

struct SnapShotCameraCtrlParam {  // Guessed name
    bool gotMin = false;
    bool gotMax = false;
    f32 mMinFovyDegree = 40.f;
    f32 mMaxFovyDegree = 85.f;
};

class SnapShotCameraCtrl : public al::NerveExecutor, public al::IUseAudioKeeper {
private:
    const al::SnapShotCameraSceneInfo* mCameraSceneInfo = nullptr;
    al::SnapShotCameraCtrlParam* mParam = nullptr;
    bool mIsValidLookAtOffset = false;
    sead::Vector3f mLookAtOffset = sead::Vector3f(0, 0, 0);
    sead::Vector3f field_38 = sead::Vector3f(0, 0, 0);
    bool mIsValidZoomFovy = false;
    f32 mFovyDegree = 0.f;
    f32 field_4C = 0.f;
    f32 field_50 = 0.f;
    f32 mMaxZoomOutFovyDegree = -1.0f;
    bool mIsValidRoll = false;
    f32 mRollDegree = 0.f;
    f32 mRollTarget = 0.f;
    u32 field_64 = -1;
    bool field_6C = false;

public:
    SnapShotCameraCtrl(const al::SnapShotCameraSceneInfo*);
    void start(f32);
    void load(const al::ByamlIter&);
    void startReset(s32);
    void update(const sead::LookAtCamera&, const al::IUseCollision*, const al::ICameraInput*);
    void makeLookAtCameraPost(sead::LookAtCamera*) const;
    void makeLookAtCameraLast(sead::LookAtCamera*) const;
    void exeWait();
    void exeReset();

    f32 getFovyDegree() const { return mFovyDegree; };
};
}  // namespace al
