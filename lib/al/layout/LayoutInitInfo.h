#pragma once

#include "al/audio/AudioDirector.h"
#include "al/layout/LayoutSceneInfo.h"
#include "al/rumble/PadRumbleDirector.h"
#include "al/camera/CameraDirector.h"
#include "al/scene/SceneObjHolder.h"
#include "al/layout/LayoutKit.h"
#include "al/layout/LayoutSystem.h"

namespace al {

class ExecuteDirector;
class EffectSystemInfo;

class LayoutInitInfo : public LayoutSceneInfo {
public:
    void init(al::ExecuteDirector*, al::EffectSystemInfo const*, al::SceneObjHolder*,
              al::AudioDirector const*, al::CameraDirector*, al::LayoutSystem const*,
              al::MessageSystem const*, al::GamePadSystem const*, al::PadRumbleDirector*);

    void *qword30 = nullptr;
    void *qword38 = nullptr;
    void *qword40 = nullptr;
    const al::ExecuteDirector *mExecuteDirector = nullptr;
    const al::EffectSystemInfo *mEffectSysInfo = nullptr;
    const al::AudioDirector *mAudioDirector = nullptr;
    const al::LayoutSystem *mLayoutSystem = nullptr;
};

void initLayoutInitInfo(al::LayoutInitInfo *,al::LayoutKit const*,al::SceneObjHolder *,al::AudioDirector const*,al::LayoutSystem const*,al::MessageSystem const*,al::GamePadSystem const*);
} // namespace al
