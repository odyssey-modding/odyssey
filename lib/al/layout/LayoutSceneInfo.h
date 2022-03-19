#pragma once

#include "al/camera/CameraDirector.h"
#include "al/message/IUseMessageSystem.h"
#include "al/rumble/PadRumbleDirector.h"
#include "al/scene/SceneObjHolder.h"

namespace eui {
class FontMgr;
}

namespace al {
class MessageSystem;
class GamePadSystem;
class LayoutSceneInfo {
public:
    LayoutSceneInfo();
    eui::FontMgr* mFontMgr = nullptr;
    al::CameraDirector* mCameraDirector = nullptr;
    al::PadRumbleDirector* mPadRumbleDirector = nullptr;
    al::SceneObjHolder* mSceneObjHolder = nullptr;
    const al::MessageSystem* mMessageSystem = nullptr;
    const al::GamePadSystem* mGamePadSystem = nullptr;
};
}  // namespace al
