#include "System/PlayerHitPointData.h"

PlayerHitPointData::PlayerHitPointData() {}

void PlayerHitPointData::setKidsModeFlag(bool isKidsMode) {
    mIsKidsMode = isKidsMode;
}

void PlayerHitPointData::init() {
    mIsHaveMaxUpItem = false;
    mIsForceNormalHealth = false;
    mCurrentHit = !mIsKidsMode ? 3 : 6;
}