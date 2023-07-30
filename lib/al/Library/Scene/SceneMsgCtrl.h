#pragma once

#include <al/Library/Scene/SceneMsg.h>

namespace al {
class SceneMsgCtrl {
private:
    al::SceneMsg mMessages[32];

public:
    SceneMsgCtrl();
};
}  // namespace al
