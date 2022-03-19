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

    void *qword30;
    void *qword38;
    void *qword40;
    const al::ExecuteDirector *mExecuteDirector;
    const al::EffectSystemInfo *mEffectSysInfo;
    const al::AudioDirector *mAudioDirector;
    const al::LayoutSystem *mLayoutSystem;
};

void initLayoutInitInfo(al::LayoutInitInfo *,al::LayoutKit const*,al::SceneObjHolder *,al::AudioDirector const*,al::LayoutSystem const*,al::MessageSystem const*,al::GamePadSystem const*);
} // namespace al
