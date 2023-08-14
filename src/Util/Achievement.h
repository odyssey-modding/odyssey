#pragma once

#include <basis/seadTypes.h>
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
char16_t const* getAchievementName(al::IUseMessageSystem const*, char const*);
char16_t const* getAchievementName(al::LayoutActor const*, int);
char16_t const* getAchievementHint(al::IUseMessageSystem const*, char const*);
char16_t const* getAchievementHint(al::LayoutActor const*, int);
AchievementHolder* getAchievementHolder(al::LayoutActor const*);
void unlockAchievementShineName(GameDataHolderAccessor);
bool isUnlockAchievementShineName(GameDataHolderAccessor);
bool checkGetAchievement(GameDataHolderAccessor, char const*);
bool checkGetAchievement(al::LayoutActor const*, int);
u64 findAchievementGetTime(al::LayoutActor const*, int);
const char* findAchievementGetTime(al::LayoutActor const*, char const*);
sead::Vector3f findAchievementTrans(al::LayoutActor const*, int);
int getAchievementNum(al::LayoutActor const*);
int calcReceivedAchievementNum(GameDataHolder const*);
int getTotalCoinNum(GameDataHolder const*);
int calcWorldWarpHoleThroughNum(GameDataHolder const*);
int getWorldWarpHoleThroughNumMax(GameDataHolder const*);
int calcGetCheckpointNum(GameDataHolder const*);
int calcBuyItemNumForCoinCollectByWorld(GameDataHolder const*);
int calcClearWorldNum(GameDataHolder const*);
int addPlayerJumpCount(al::LiveActor const*);
int getPlayerJumpCount(GameDataHolder const*);
int addPlayerThrowCapCount(al::LiveActor const*);
int getPlayerThrowCapCount(GameDataHolder const*);
int checkGetCoinCollectAllInWorld(al::LiveActor const*, int);
int checkGetCoinCollectHalfInWorld(AchievementNpc const*, int);
int checkGetShineAllInWorld(AchievementNpc const*, int);
int checkGetClothAndCapNum(AchievementNpc const*, int);
int checkUnlockMoonRockAllWorld(GameDataHolderAccessor);
int calcUnlockMoonRockNum(GameDataHolderAccessor);
int calcHackObjNum(GameDataHolderAccessor);
int calcSphinxQuizCompleteNum(GameDataHolderAccessor);
int calcGetShineNumDot(GameDataHolder const*);
int calcGetShineNumTreasureBox(GameDataHolder const*);
int calcGetShineNumNoteObj(GameDataHolder const*);
int calcGetShineNumTimerAthletic(GameDataHolder const*);
int calcGetShineNumKinopioBrigade(GameDataHolder const*);
int calcGetShineNumWorldTravelingPeach(GameDataHolder const*);
int calcGetShineNumCollectAnimal(GameDataHolder const*);
int calcAllShineNumCollectAnimal(GameDataHolder const*);
int calcGetShineNumKuriboGirl(GameDataHolder const*);
int calcGetShineNumJugemFish(GameDataHolder const*);
int calcGetShineNumGrowPlant(GameDataHolder const*);
int calcGetShineNumRabbit(GameDataHolder const*);
int calcGetShineNumDigPoint(GameDataHolder const*);
int calcGetShineNumCapHanger(GameDataHolder const*);
int calcGetShineNumBird(GameDataHolder const*);
int calcGetShineNumCostumeRoom(GameDataHolder const*);
int calcGetShineNumSlot(GameDataHolder const*);
int calcGetShineNumRace(GameDataHolder const*);
int calcGetShineNumFigureWalking(GameDataHolder const*);
int calcGetShineNumHideAndSeekCapMan(GameDataHolder const*);
int calcAllShineNumHideAndSeekCapMan(GameDataHolder const*);
int calcGetShineNumCollectBgmNpc(GameDataHolder const*);
int calcAllShineNumCollectBgmNpc(GameDataHolder const*);
int calcGetShineNumHintPhoto(GameDataHolder const*);
}  // namespace rs