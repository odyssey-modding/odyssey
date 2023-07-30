#pragma once

#include <al/Library/Execute/IUseExecutor.h>
#include <basis/seadTypes.h>
#include <math/seadMatrix.h>

namespace al {
class SceneCameraInfo;
class SceneCameraCtrl;
class CameraPoseUpdater;
class CameraPoserFactory;
class CameraPoserSceneInfo;
class SpecialCameraHolder;
class CameraTargetCollideInfoHolder;
class CameraTargetHolder;
class CameraInputHolder;
class CameraAngleVerticalRequester;
class CameraStartParamCtrl;
class CameraStopJudge;
class CameraParamTransfer;
class CameraResourceHolder;
class CameraFlagCtrl;
class CameraInSwitchOnAreaDirector;
class CameraTicket;
class PlacementId;
class CameraPoser;
class AreaObjDirector;
class ICameraInput;
class CameraRailHolder;
class NameToCameraParamTransferFunc;
class IUseAudioKeeper;
class CameraDirector : public al::IUseExecutor {
private:
    s32 mCameraCount;
    al::SceneCameraInfo* mSceneCameraInfo;
    al::SceneCameraCtrl* mSceneCameraCtrl;
    al::CameraPoseUpdater** mCameraPoserUpdaters;
    al::CameraPoserFactory* mCameraPoserFactory;
    al::CameraPoserSceneInfo* mCameraPoserSceneInfo;
    void* field_38;
    al::SpecialCameraHolder* mSpecialCameraHolder;
    al::CameraTargetCollideInfoHolder* mCameraTargetCollideInfoHolder;
    al::CameraTargetHolder* mCameraTargetHolder;
    al::CameraInputHolder* mCameraInputHolder;
    al::CameraAngleVerticalRequester* mCameraAngleVerticalRequester;
    al::CameraStartParamCtrl* mCameraStartParamCtrl;
    al::CameraStopJudge* mCameraStopJudge;
    al::CameraParamTransfer* mCameraParamTransfer;
    al::CameraResourceHolder* mCameraResourceHolder;
    al::CameraFlagCtrl* mCameraFlagCtrl;
    void* field_90;
    al::CameraInSwitchOnAreaDirector* mCameraInSwitchOnAreaDirector;
    void* field_a0;

public:
    CameraDirector(s32 cameraCount);
    ~CameraDirector();
    void init(al::CameraPoserSceneInfo*, const al::CameraPoserFactory*);
    void initAreaCameraSwitcherMultiForPrototype(al::AreaObjDirector*);
    void initAreaCameraSwitcherSingle();
    void initResourceHolder(const al::CameraResourceHolder* resourceHolder);
    void initSceneFovyDegree(f32 fov);
    void initSettingCloudSea(f32);
    void initSnapShotCameraAudioKeeper(al::IUseAudioKeeper* audioKeeper);
    void initAndCreatePauseCameraCtrl(f32);

    void execute() override;
    void update();
    void endInit();

    al::CameraPoseUpdater* getPoseUpdater(s32 index);
    al::CameraTicket* createCameraFromFactory(const char*, const al::PlacementId*, const char*, s32, const sead::Matrix34f&);
    al::CameraTicket* createCameraFromFactory(al::CameraPoser*, const al::PlacementId*, const char*, s32, const sead::Matrix34f&, bool);
    al::CameraTicket* createObjectCamera(const al::PlacementId*, const char*, const char*, s32, const sead::Matrix34f&);
    al::CameraTicket* createObjectEntranceCamera(const al::PlacementId*, const char*, const sead::Matrix34f&);
    al::CameraTicket* createMirrorObjectCamera(const al::PlacementId*, const char*, s32, const sead::Matrix34f&);

    al::ICameraInput* getCameraInput();
    void setCameraInput(const al::ICameraInput* input);
    void setViewCameraInput(const al::ICameraInput* input, s32);
    void registerCameraRailHolder(al::CameraRailHolder* railHolder);
    void setCameraParamTransferFuncTable(const al::NameToCameraParamTransferFunc*, s32);
    f32 getSceneFovyDegree();
    void validateCameraArea2D();
    void invalidateCameraArea2D();
    void stopByDeathPlayer();
    void restartByDeathPlayer();
    void startInvalidStopJudgeByDemo();
    void endInvalidStopJudgeByDemo();
    void startSnapShotMode(bool);
    void endSnapShotMode();
};

class IUseCamera {
public:
    virtual CameraDirector* getCameraDirector() const = 0;
};
}  // namespace al
