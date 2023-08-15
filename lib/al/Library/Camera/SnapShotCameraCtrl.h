#pragma once

#include <al/Library/Audio/AudioKeeper.h>
#include <al/Library/Nerve/NerveExecutor.h>

namespace sead {
    class LookAtCamera;
}

namespace al {
class SnapShotCameraSceneInfo;
class ICameraInput;
class IUseCollision;
class ByamlIter;

struct SnapShotParam {  // Guessed name
    bool gotMin = false;
    bool gotMax = false;
    f32 mMinFovyDegree = 40.0f;
    f32 mMaxFovyDegree = 85.0f;
};

class SnapShotCameraCtrl : public al::NerveExecutor, public al::IUseAudioKeeper {
private:
    const al::SnapShotCameraSceneInfo* mCameraSceneInfo = nullptr;
    al::SnapShotParam* mParam = nullptr;
    bool mIsValidLookAtOffset = false;
    sead::Vector3f mLookAtOffset = sead::Vector3f(0, 0, 0);
    sead::Vector3f field_38 = sead::Vector3f(0, 0, 0);
    bool mIsValidZoomFovy = false;
    f32 mFovyDegree = 0.0f;
    f32 field_4C = 0.0f;
    f32 field_50 = 0.0f;
    f32 mMaxZoomOutFovyDegree = -1.0f;
    bool mIsValidRoll = false;
    f32 mRollDegree = 0.0f;
    f32 mRollTarget = 0.0f;
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
