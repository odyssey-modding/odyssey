#pragma once

#include "Player/PlayerHackKeeper.h"

class IUsePlayerHack {
public:
    virtual PlayerHackKeeper* getPlayerHackKeeper() const = 0;
};
