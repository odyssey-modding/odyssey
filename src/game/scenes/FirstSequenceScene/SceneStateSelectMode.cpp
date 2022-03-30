#include "game/scenes/FirstSequenceScene/SceneStateSelectMode.h"
SceneStateSelectMode::SceneStateSelectMode(const char* name, al::Scene* scene,
                                           const al::LayoutInitInfo& initInfo,
                                           FooterParts* footerParts,
                                           al::WindowConfirm* confirmWindow,
                                           al::WaveVibrationHolder* waveVibrationHolder)
    : al::HostStateBase<al::Scene>(name, scene) {
    al::initLayoutPartsActor()
}
