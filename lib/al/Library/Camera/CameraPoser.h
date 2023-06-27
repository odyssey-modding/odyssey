#pragma once

#include <al/Library/IUse/IUse.h>

#include "SnapShotCameraCtrl.h"
#include <al/Library/Nerve/Nerve.h>
#include <al/Library/Placement/PlacementInfo.h>

#include <gfx/seadCamera.h>
#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {

class CameraVerticalAbsorber;
class CameraAngleCtrlInfo;
class CameraAngleSwingInfo;
class CameraArrowCollider;
class CameraOffsetCtrlPreset;
class CameraParamMoveLimit;
class GyroCameraCtrl;
class CameraViewInfo;
class CameraStartInfo;
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
    const char* mPoserName;                             // 0x30
    float field_38;                                     // 0x38
    sead::Vector3f mPosition;                           // 0x3C
    sead::Vector3f mTargetTrans = sead::Vector3f::ex;   // 0x48
    sead::Vector3f mCameraUp = sead::Vector3f::ey;      // 0x54
    float mFovyDegree = 35.0f;                          // 0x60
    float field_64;                                     // 0x64
    sead::Matrix34f mViewMtx = sead::Matrix34f::ident;  // 0x68
    bool field_98 = false;                              // 0x98
    CameraViewInfo* mViewInfo;                          // 0xA0
    al::AreaObjDirector* mAreaDirector;                 // 0xA8
    CameraPoserFlag* mPoserFlags;                       // 0xB0
    CameraVerticalAbsorber* mVerticalAbsorber;          // 0xB8
    CameraAngleCtrlInfo* mAngleCtrlInfo;                // 0xC0
    CameraAngleSwingInfo* mAngleSwingInfo;              // 0xC8
    CameraArrowCollider* mArrowCollider;                // 0xD0
    CameraOffsetCtrlPreset* mOffsetCtrlPreset;          // 0xD8
    float* mLocalInterpole;                             // 0xE0 (size = 0x20)
    float* mLookAtInterpole;                            // 0xE8 (size = 0x10)
    CameraParamMoveLimit* mParamMoveLimit;              // 0xF0
    void* field_f8;                                     // 0xF8
    GyroCameraCtrl* mGyroCtrl;                          // 0x100
    SnapShotCameraCtrl* mSnapshotCtrl;                  // 0x108
    AudioKeeper* mAudioKeeper;                          // 0x110
    NerveKeeper* mNerveKeeper;                          // 0x118
    RailKeeper* mRailKeeper;                            // 0x120
    int* field_128;                                     // 0x128 (size = 0xC) interpolesteptype?
    int* field_130;                                     // 0x130 (size - 0x8)
    sead::Vector3f* mOrthoProjectionParam;              // 0x138 (gets init'd with new of size 0xC)

public:
    CameraPoser(const char* poserName);

    virtual AreaObjDirector* getAreaObjDirector() const override;
    virtual void init();
    virtual void initByPlacementObj(const al::PlacementInfo&);
    virtual void endInit();
    virtual void start(const CameraStartInfo&);
    virtual void update();
    virtual void end();
    virtual void loadParam(const ByamlIter&);
    virtual void makeLookAtCamera(sead::LookAtCamera*) const;
    virtual void receiveRequestFromObject(const CameraObjectRequestInfo&);
    virtual bool isZooming(void) const;
    virtual bool isEnableRotateByPad(void) const;
    virtual void startSnapShotMode(void);
    virtual void endSnapShotMode(void);

    virtual const char* getName(void) const override;
    virtual CollisionDirector* getCollisionDirector(void) const override;
    virtual NerveKeeper* getNerveKeeper(void) const override;
    virtual AudioKeeper* getAudioKeeper(void) const override;
    virtual RailRider* getRailRider(void) const override;

    virtual void load(const ByamlIter&);
    virtual void movement(void);
    virtual void calcCameraPose(sead::LookAtCamera*) const;
    virtual void requestTurnToDirection(const al::CameraTurnInfo*);

    bool isInterpoleByCameraDistance(void) const;
    bool isInterpoleEaseOut(void) const;
    bool isEndInterpoleByStep(void) const;
    bool isFirstCalc(void) const;

    void initNerve(const al::Nerve*, int);
    void initArrowCollider(al::CameraArrowCollider*);
    void initAudioKeeper(const char*);
    void initRail(const al::PlacementInfo&);
    void initLocalInterpole(void);
    void initLookAtInterpole(float);
    void initOrthoProjectionParam(void);
    void tryInitAreaLimitter(const al::PlacementInfo&);

    void makeLookAtCameraPrev(sead::LookAtCamera*) const;
    void makeLookAtCameraPost(sead::LookAtCamera*) const;
    void makeLookAtCameraLast(sead::LookAtCamera*) const;
    void makeLookAtCameraCollide(sead::LookAtCamera*) const;

    void getInterpoleStep(void);
    void setInterpoleStep(int);
    void resetInterpoleStep(void);
    void setInterpoleEaseOut(void);
    void getEndInterpoleStep(void);

    void appear(const al::CameraStartInfo&);
    void calcCameraPose(sead::LookAtCamera*);
    void receiveRequestFromObjectCore(const al::CameraObjectRequestInfo&);

    void startSnapShotModeCore(void);
    void endSnapShotModeCore(void);

    float getFovyDegree(void) const;

    sead::Vector3f getPosition() const { return mPosition; };
    sead::Vector3f getTargetTrans() const { return mTargetTrans; };
    sead::Vector3f getCameraUp() const { return mCameraUp; };
};
};  // namespace al