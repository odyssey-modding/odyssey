#pragma once

#include "al/Library/Layout/LayoutSceneInfo.h"

namespace al {
class ExecuteDirector;
struct EffectSystemInfo;
class AudioDirector;
class LayoutSystem;
class LayoutActor;

struct LayoutInitInfo : public LayoutSceneInfo {
    void* field_30;
    void* field_38;
    void* field_40;
    al::ExecuteDirector* mExecuteDirector;
    al::EffectSystemInfo* mEffectSysInfo;
    al::AudioDirector* mAudioDirector;
    al::LayoutSystem* mLayoutSystem;

    void init(al::ExecuteDirector*, const al::EffectSystemInfo*, al::SceneObjHolder*, const al::AudioDirector*, al::CameraDirector*,
              const al::LayoutSystem*, const al::MessageSystem*, const al::GamePadSystem*, al::PadRumbleDirector*);

    al::MessageSystem* getMessageSystem() const;
};

void initLayoutActor(al::LayoutActor*, const al::LayoutInitInfo&, const char*, const char*);
void initLayoutActorLocalized(al::LayoutActor*, const al::LayoutInitInfo&, const char*, const char*);
void initLayoutActorUseOtherMessage(al::LayoutActor*, const al::LayoutInitInfo&, const char*, const char*, const char*);
void initLayoutTextPaneAnimator(al::LayoutActor*, const char*);
void initLayoutTextPaneAnimatorWithShadow(al::LayoutActor*, const char*);
void initLayoutPartsActor(al::LayoutActor*, al::LayoutActor*, const al::LayoutInitInfo&, const char*, const char*);
void initLayoutPartsActorLocalized(al::LayoutActor*, al::LayoutActor*, const al::LayoutInitInfo&, const char*, const char*);

}  // namespace al