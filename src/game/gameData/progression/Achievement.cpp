#include "game/gameData/progression/Achievement.h"

#include "game/gameData/progression/AchievementInfoReader.h"
#include "al/util/ResourceUtil.h"

Achievement::Achievement(const AchievementInfo* info) : mInfo(info) {}

bool Achievement::isGet(GameDataHolderAccessor accessor) const {
    return mGet || rs::checkGetAchievement(accessor, mInfo->mName);
}
