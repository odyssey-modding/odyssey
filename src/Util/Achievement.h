#pragma once

#include <math/seadVector.h>

namespace al {
class IUseMessageSystem;
class LayoutActor;
class LiveActor;
}  // namespace al

class AchievementHolder;
class AchievementNpc;
class GameDataHolderAccessor;
class GameDataHolder;

namespace rs {
const char16_t* getAchievementName(const al::IUseMessageSystem*, const char*);
const char16_t* getAchievementName(const al::LayoutActor*, s32);
const char16_t* getAchievementHint(const al::IUseMessageSystem*, const char*);
const char16_t* getAchievementHint(const al::LayoutActor*, s32);
AchievementHolder* getAchievementHolder(const al::LayoutActor*);
void unlockAchievementShineName(GameDataHolderAccessor);
bool isUnlockAchievementShineName(GameDataHolderAccessor);
bool checkGetAchievement(GameDataHolderAccessor, const char*);
bool checkGetAchievement(const al::LayoutActor*, s32);
u64 findAchievementGetTime(const al::LayoutActor*, s32);
const char* findAchievementGetTime(const al::LayoutActor*, const char*);
sead::Vector3f* findAchievementTrans(const al::LayoutActor*, s32);
s32 getAchievementNum(const al::LayoutActor*);
s32 calcReceivedAchievementNum(const GameDataHolder*);
s32 getTotalCoinNum(const GameDataHolder*);
s32 calcWorldWarpHoleThroughNum(const GameDataHolder*);
s32 getWorldWarpHoleThroughNumMax(const GameDataHolder*);
s32 calcGetCheckpointNum(const GameDataHolder*);
s32 calcBuyItemNumForCoinCollectByWorld(const GameDataHolder*);
s32 calcClearWorldNum(const GameDataHolder*);
s32 addPlayerJumpCount(const al::LiveActor*);
s32 getPlayerJumpCount(const GameDataHolder*);
s32 addPlayerThrowCapCount(const al::LiveActor*);
s32 getPlayerThrowCapCount(const GameDataHolder*);
s32 checkGetCoinCollectAllInWorld(const al::LiveActor*, s32);
s32 checkGetCoinCollectHalfInWorld(const AchievementNpc*, s32);
s32 checkGetShineAllInWorld(const AchievementNpc*, s32);
s32 checkGetClothAndCapNum(const AchievementNpc*, s32);
s32 checkUnlockMoonRockAllWorld(GameDataHolderAccessor);
s32 calcUnlockMoonRockNum(GameDataHolderAccessor);
s32 calcHackObjNum(GameDataHolderAccessor);
s32 calcSphinxQuizCompleteNum(GameDataHolderAccessor);
s32 calcGetShineNumDot(const GameDataHolder*);
s32 calcGetShineNumTreasureBox(const GameDataHolder*);
s32 calcGetShineNumNoteObj(const GameDataHolder*);
s32 calcGetShineNumTimerAthletic(const GameDataHolder*);
s32 calcGetShineNumKinopioBrigade(const GameDataHolder*);
s32 calcGetShineNumWorldTravelingPeach(const GameDataHolder*);
s32 calcGetShineNumCollectAnimal(const GameDataHolder*);
s32 calcAllShineNumCollectAnimal(const GameDataHolder*);
s32 calcGetShineNumKuriboGirl(const GameDataHolder*);
s32 calcGetShineNumJugemFish(const GameDataHolder*);
s32 calcGetShineNumGrowPlant(const GameDataHolder*);
s32 calcGetShineNumRabbit(const GameDataHolder*);
s32 calcGetShineNumDigPoint(const GameDataHolder*);
s32 calcGetShineNumCapHanger(const GameDataHolder*);
s32 calcGetShineNumBird(const GameDataHolder*);
s32 calcGetShineNumCostumeRoom(const GameDataHolder*);
s32 calcGetShineNumSlot(const GameDataHolder*);
s32 calcGetShineNumRace(const GameDataHolder*);
s32 calcGetShineNumFigureWalking(const GameDataHolder*);
s32 calcGetShineNumHideAndSeekCapMan(const GameDataHolder*);
s32 calcAllShineNumHideAndSeekCapMan(const GameDataHolder*);
s32 calcGetShineNumCollectBgmNpc(const GameDataHolder*);
s32 calcAllShineNumCollectBgmNpc(const GameDataHolder*);
s32 calcGetShineNumHintPhoto(const GameDataHolder*);
}  // namespace rs