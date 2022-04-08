#include "game/scenes/FirstSequenceScene/SceneStateSelectMode.h"
#include "al/input/KeyRepeatCtrl.h"
#include "al/layout/actors/SimpleLayoutAppearWaitEnd.h"
#include "al/rumble/WaveVibrationPlayer.h"
#include "al/util/LayoutActorUtil.h"
#include "rs/KidsMode.h"
#include "rs/Layout.h"

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
    mNormalButton = new al::LayoutActor("モード選択[通常]");
    al::initLayoutPartsActor(mNormalButton, mModeSelection, initInfo, "ParMode00", nullptr);
    mKidsButton = new al::LayoutActor("モード選択[キッズ]");
    al::initLayoutPartsActor(mKidsButton, mModeSelection, initInfo, "ParMode01", nullptr);
    mSelectionCursor = new al::SimpleLayoutAppearWaitEnd(mModeSelection, "モード選択[カーソル]",
                                                         "ParCursor", initInfo, nullptr);
    al::killLayoutIfActive(mSelectionCursor);
}

void SceneStateSelectMode::appear() {
    mIsDead = false;
    al::setNerve(this, &nrvSceneStateSelectModeAppear);
    mIsNormal = !rs::isKidsMode(mKidsButton);
}

void SceneStateSelectMode::exeAppear() {
    if (al::isFirstStep(this)) {
        mModeSelection->appear();
        al::hidePane(mModeSelection, "ParCursor");
    }

    rs::updateKitListLayoutOnlyLayoutScene(mHost);

    if (!mModeSelection->isWait()) {
        al::setNerve(this, &nrvSceneStateSelectModeWait);
    }
}

void SceneStateSelectMode::exeWait() {}

namespace {
NERVE_IMPL(SceneStateSelectMode, Appear)
NERVE_IMPL(SceneStateSelectMode, Wait)
NERVE_IMPL(SceneStateSelectMode, Decide)
NERVE_IMPL(SceneStateSelectMode, DecideWait)
NERVE_IMPL(SceneStateSelectMode, DecideConfirm)
NERVE_IMPL(SceneStateSelectMode, End)
}  // namespace
