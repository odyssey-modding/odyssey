#pragma once

#include "al/message/IUseMessageSystem.h"
#include "al/nerve/HostStateBase.h"
#include "al/nerve/NerveStateBase.h"
#include "al/util/NerveUtil.h"

namespace al {
class Scene;
class LayoutInitInfo;
class WindowConfirm;
class WaveVibrationHolder;
class SimpleLayoutAppearWaitEnd;
class LayoutActor;
class WindowConfirm;
class KeyRepeatCtrl;
}  // namespace al
class FooterParts;

class SceneStateSelectMode : public al::HostStateBase<al::Scene>, public al::IUseMessageSystem {
public:
    SceneStateSelectMode(const char* name, al::Scene* scene, const al::LayoutInitInfo& initInfo,
                         FooterParts* footerParts, al::WindowConfirm* confirmWindow,
                         al::WaveVibrationHolder* waveVibrationHolder);
    void appear() override;
    void kill() override;
    void updateCursorParts(bool);
    void updateCursorPartsTrans();

    const al::MessageSystem* getMessageSystem() const override {
        return mMessageSystem;
    }

    void exeAppear();
    void exeWait();
    void exeDecide();
    void exeDecideWait();
    void exeDecideConfirm();
    void exeEnd();

private:
    al::SimpleLayoutAppearWaitEnd* mModeSelection;
    al::LayoutActor* mNormalButton;
    al::LayoutActor* mKidsButton;
    al::LayoutActor* mSelectionCursor;
    FooterParts* mFooterParts;
    al::WindowConfirm* mWindowConfirm;
    bool mIsClosing;
    bool mIsNormal;
    al::KeyRepeatCtrl* mKeyRepeatCtrl;
    al::MessageSystem* mMessageSystem;
    al::WaveVibrationHolder* mWaveVibration;
};

namespace {
NERVE_HEADER(SceneStateSelectMode, Appear)
NERVE_HEADER(SceneStateSelectMode, Wait)
NERVE_HEADER(SceneStateSelectMode, Decide)
NERVE_HEADER(SceneStateSelectMode, DecideWait)
NERVE_HEADER(SceneStateSelectMode, DecideConfirm)
NERVE_HEADER(SceneStateSelectMode, End)
}

static_assert(sizeof(SceneStateSelectMode) == 0x78);
