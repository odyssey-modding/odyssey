#include "PlayerHitPointData.h"

PlayerHitPointData::PlayerHitPointData() {}

void PlayerHitPointData::setKidsModeFlag(bool isKidsMode) {
    mIsKidsMode = isKidsMode;
}

void PlayerHitPointData::init() {
    mIsHaveMaxUpItem = false;
    mIsForceNormalHealth = false;
    if (mIsKidsMode)
        mCurrentHit = 6;
    else
        mCurrentHit = 3;
}