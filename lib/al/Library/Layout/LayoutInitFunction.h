#pragma once

#include "LayoutSceneInfo.h"

namespace al {
class ExecuteDirector;
class EffectSystemInfo;
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

    void init(al::ExecuteDirector*, al::EffectSystemInfo const*, al::SceneObjHolder*, al::AudioDirector const*, al::CameraDirector*,
              al::LayoutSystem const*, al::MessageSystem const*, al::GamePadSystem const*, al::PadRumbleDirector*);

    al::MessageSystem* getMessageSystem(void) const;
};

void initLayoutActor(al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*);
void initLayoutActorLocalized(al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*);
void initLayoutActorUseOtherMessage(al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*, char const*);
void initLayoutTextPaneAnimator(al::LayoutActor*, char const*);
void initLayoutTextPaneAnimatorWithShadow(al::LayoutActor*, char const*);
void initLayoutPartsActor(al::LayoutActor*, al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*);
void initLayoutPartsActorLocalized(al::LayoutActor*, al::LayoutActor*, al::LayoutInitInfo const&, char const*, char const*);

}  // namespace al