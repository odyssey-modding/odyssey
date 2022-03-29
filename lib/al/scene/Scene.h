#pragma once

#include "al/audio/AudioKeeper.h"
#include "al/camera/CameraDirector.h"
#include "al/nerve/NerveExecutor.h"
#include "al/scene/SceneInitInfo.h"
#include "al/scene/SceneObjHolder.h"
#include "al/iuse/IUseCamera.h"
#include "al/iuse/IUseAudioKeeper.h"
#include <prim/seadSafeString.h>

namespace al {
class StageResourceKeeper;
class LiveActorKit;
class LayoutKit;
class SceneStopCtrl;
class SceneMsgCtrl;
class ScreenCoverCtrl;
class AudioDirector;
class AudioKeeper;
class NerveKeeper;

class Scene : public al::NerveExecutor,
              public al::IUseAudioKeeper,
              public al::IUseCamera,
              public al::IUseSceneObjHolder {
public:
    Scene(const char*);

    virtual ~Scene();
    virtual void init(const al::SceneInitInfo&);
    virtual void appear();
    virtual void kill();
    virtual void movement();
    virtual void control();
    virtual void drawMain();
    virtual void drawSub();
    virtual al::AudioKeeper* getAudioKeeper();
    virtual al::SceneObjHolder* getSceneObjHolder();
    virtual al::CameraDirector* getCameraDirector();

private:
    bool mIsAlive;
    sead::FixedSafeString<0x40> mName;
    StageResourceKeeper* mStageResourceKeeper;
    LiveActorKit* mLiveActorKit;
    LayoutKit* mLayoutKit;
    SceneObjHolder* mSceneObjHolder;
    SceneStopCtrl* mSceneStopCtrl;
    SceneMsgCtrl* mSceneMsgCtrl;
    ScreenCoverCtrl* mScreenCoverCtrl;
    AudioDirector* mAudioDirector;
    AudioKeeper* mAudioKeeper;
    NerveKeeper* mNerveKeeper;
};

static_assert(sizeof(al::Scene) == 0xd8);
}  // namespace al