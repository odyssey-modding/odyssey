#pragma once

#include <basis/seadTypes.h>

namespace al {
class GamePadSystem {
    GamePadSystem();
    void changeSinglePlayMode();
    bool isDisconnectPlayable();
    const char* getPadName(u8);
};
}
