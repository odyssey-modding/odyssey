#pragma once

#include "al/nerve/NerveStateBase.h"
#include "al/message/IUseMessageSystem.h"

namespace al {
class Scene;
class LayoutInitInfo;
class WindowConfirm;
class WaveVibrationHolder;
}
class FooterParts;

class SceneStateSelectMode : public al::NerveStateBase, public al::IUseMessageSystem {
    SceneStateSelectMode(const char*, al::Scene*, const al::LayoutInitInfo&, FooterParts*,
                         al::WindowConfirm*, al::WaveVibrationHolder*);
//    ~SceneStateSelectMode();
    void appear() override;
    void kill() override;

};