#include "al/layout/LayoutInitInfo.h"

namespace al {
void LayoutInitInfo::init(al::ExecuteDirector* executeDirector,
                          const al::EffectSystemInfo* effectSystemInfo,
                          al::SceneObjHolder* sceneObjHolder,
                          const al::AudioDirector* audioDirector,
                          al::CameraDirector* cameraDirector,
                          const al::LayoutSystem* layoutSystem,
                          const al::MessageSystem* messageSystem,
                          const al::GamePadSystem* gamePadSystem,
                          al::PadRumbleDirector* padRumbleDirector) {
    mExecuteDirector = executeDirector;
    mEffectSysInfo = effectSystemInfo;
    mSceneObjHolder = sceneObjHolder;
    mAudioDirector = audioDirector;
    mCameraDirector = cameraDirector;
    mLayoutSystem = layoutSystem;
    mMessageSystem = messageSystem;
    mGamePadSystem = gamePadSystem;
}

void initLayoutInitInfo(al::LayoutInitInfo* layoutInitInfo, const al::LayoutKit* layoutKit,
                        al::SceneObjHolder*, const al::AudioDirector*, const al::LayoutSystem*,
                        const al::MessageSystem*, const al::GamePadSystem*) {}
}  // namespace al