#include "game/scenes/FirstSequenceScene/SceneStateSelectMode.h"
#include "al/input/KeyRepeatCtrl.h"
#include "al/layout/actors/SimpleLayoutAppearWaitEnd.h"
#include "rs/KidsMode.h"

SceneStateSelectMode::SceneStateSelectMode(const char* name, al::Scene* scene,
                                           const al::LayoutInitInfo& initInfo,
                                           FooterParts* footerParts,
                                           al::WindowConfirm* confirmWindow,
                                           al::WaveVibrationHolder* waveVibrationHolder)
    : al::HostStateBase<al::Scene>(name, scene) {
    mModeSelection =
        new al::SimpleLayoutAppearWaitEnd("モード選択", "ModeSelect", initInfo, nullptr, false);
    mModeSelection->kill();
    mKeyRepeatCtrl = new al::KeyRepeatCtrl();
    mKeyRepeatCtrl->init(30, 5);
}

void SceneStateSelectMode::appear() {
    mIsDead = true;
    al::setNerve(this, &nrvSceneStateSelectModeAppear);
    rs::isKidsMode()
}

void SceneStateSelectMode::exeAppear() {
    if (al::isFirstStep(this)) {
        mModeSelection->appear();

    }
}

namespace {
NERVE_IMPL(SceneStateSelectMode, Appear)
NERVE_IMPL(SceneStateSelectMode, Wait)
NERVE_IMPL(SceneStateSelectMode, Decide)
NERVE_IMPL(SceneStateSelectMode, DecideWait)
NERVE_IMPL(SceneStateSelectMode, DecideConfirm)
NERVE_IMPL(SceneStateSelectMode, End)
}
