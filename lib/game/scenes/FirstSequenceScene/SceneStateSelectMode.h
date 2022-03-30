#pragma once

#include "al/message/IUseMessageSystem.h"
#include "al/nerve/HostStateBase.h"
#include "al/nerve/NerveStateBase.h"

namespace al {
class Scene;
class LayoutInitInfo;
class WindowConfirm;
class WaveVibrationHolder;
}  // namespace al
class FooterParts;

class SceneStateSelectMode : public al::HostStateBase<al::Scene>, public al::IUseMessageSystem {
    SceneStateSelectMode(const char* name, al::Scene* scene, const al::LayoutInitInfo& initInfo,
                         FooterParts* footerParts, al::WindowConfirm* confirmWindow,
                         al::WaveVibrationHolder* waveVibrationHolder);
    void appear() override;
    void kill() override;
    void updateCursorParts(bool);
    void updateCursorPartsTrans();

    const al::MessageSystem* getMessageSystem() const override {

    }

    void exeAppear();
    void exeWait();
    void exeDecide();
    void exeDecideWait();
    void exeDecideConfirm();
    void exeEnd();
};