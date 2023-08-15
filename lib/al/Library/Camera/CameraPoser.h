#pragma once

#include <al/Library/Area/AreaObjDirector.h>
#include <al/Library/Audio/AudioKeeper.h>
#include <al/Library/Name/IUseName.h>
#include <al/Library/Nerve/Nerve.h>
#include <al/Library/Placement/PlacementInfo.h>
#include <al/Library/Rail/RailRider.h>
#include <gfx/seadCamera.h>
#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>
#include "SnapShotCameraCtrl.h"

namespace al {

struct CameraStartInfo;
class CameraVerticalAbsorber;
class CameraAngleCtrlInfo;
class CameraAngleSwingInfo;
class CameraArrowCollider;
class CameraOffsetCtrlPreset;
class CameraParamMoveLimit;
class GyroCameraCtrl;
class CameraViewInfo;
class CameraObjectRequestInfo;
class CameraTurnInfo;
class CameraPoserFlag;
class RailKeeper;

class CameraPoser : public al::HioNode,
                    public al::IUseAreaObj,
                    public al::IUseAudioKeeper,
                    public al::IUseCollision,
                    public al::IUseName,
                    public al::IUseNerve,
                    public al::IUseRail {
private:
    const char* mPoserName;
    f32 field_38;
    sead::Vector3f mPosition;
    sead::Vector3f mTargetTrans = sead::Vector3f::ex;
    sead::Vector3f mCameraUp = sead::Vector3f::ey;
    f32 mFovyDegree = 35.0f;
    f32 field_64;
    sead::Matrix34f mViewMtx = sead::Matrix34f::ident;
    bool field_98 = false;
    al::CameraViewInfo* mViewInfo;
    al::AreaObjDirector* mAreaDirector;
    al::CameraPoserFlag* mPoserFlags;
    al::CameraVerticalAbsorber* mVerticalAbsorber;
    al::CameraAngleCtrlInfo* mAngleCtrlInfo;
    al::CameraAngleSwingInfo* mAngleSwingInfo;
    al::CameraArrowCollider* mArrowCollider;
    al::CameraOffsetCtrlPreset* mOffsetCtrlPreset;
    f32* mLocalInterpole;
    f32* mLookAtInterpole;
    al::CameraParamMoveLimit* mParamMoveLimit;
    void* field_f8;
    al::GyroCameraCtrl* mGyroCtrl;
    al::SnapShotCameraCtrl* mSnapshotCtrl;
    al::AudioKeeper* mAudioKeeper;
    al::NerveKeeper* mNerveKeeper;
    al::RailKeeper* mRailKeeper;
    s32* field_128;
    s32* field_130;
    sead::Vector3f* mOrthoProjectionParam;

public:
    CameraPoser(const char* poserName);

    virtual al::AreaObjDirector* getAreaObjDirector() const override;
    virtual void init();
    virtual void initByPlacementObj(const al::PlacementInfo&);
    virtual void endInit();
    virtual void start(const al::CameraStartInfo&);
    virtual void update();
    virtual void end();
    virtual void loadParam(const al::ByamlIter&);
    virtual void makeLookAtCamera(sead::LookAtCamera*) const;
    virtual void receiveRequestFromObject(const al::CameraObjectRequestInfo&);
    virtual bool isZooming() const;
    virtual bool isEnableRotateByPad() const;
    virtual void startSnapShotMode();
    virtual void endSnapShotMode();

    virtual const char* getName() const override;
    virtual al::CollisionDirector* getCollisionDirector() const override;
    virtual al::NerveKeeper* getNerveKeeper() const override;
    virtual al::AudioKeeper* getAudioKeeper() const override;
    virtual al::RailRider* getRailRider() const override;

    virtual void load(const al::ByamlIter&);
    virtual void movement();
    virtual void calcCameraPose(sead::LookAtCamera*) const;
    virtual void requestTurnToDirection(const al::CameraTurnInfo*);

    bool isInterpoleByCameraDistance() const;
    bool isInterpoleEaseOut() const;
    bool isEndInterpoleByStep() const;
    bool isFirstCalc() const;

    void initNerve(const al::Nerve*, s32);
    void initArrowCollider(al::CameraArrowCollider*);
    void initAudioKeeper(const char*);
    void initRail(const al::PlacementInfo&);
    void initLocalInterpole();
    void initLookAtInterpole(f32);
    void initOrthoProjectionParam();
    void tryInitAreaLimitter(const al::PlacementInfo&);

    void makeLookAtCameraPrev(sead::LookAtCamera*) const;
    void makeLookAtCameraPost(sead::LookAtCamera*) const;
    void makeLookAtCameraLast(sead::LookAtCamera*) const;
    void makeLookAtCameraCollide(sead::LookAtCamera*) const;

    void getInterpoleStep();
    void setInterpoleStep(int);
    void resetInterpoleStep();
    void setInterpoleEaseOut();
    void getEndInterpoleStep();

    void appear(const al::CameraStartInfo&);
    void calcCameraPose(sead::LookAtCamera*);
    void receiveRequestFromObjectCore(const al::CameraObjectRequestInfo&);

    void startSnapShotModeCore();
    void endSnapShotModeCore();

    f32 getFovyDegree() const;

    sead::Vector3f getPosition() const { return mPosition; };
    sead::Vector3f getTargetTrans() const { return mTargetTrans; };
    sead::Vector3f getCameraUp() const { return mCameraUp; };
};
};  // namespace al
