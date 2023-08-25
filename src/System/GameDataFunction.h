#pragma once

#include <basis/seadTypes.h>
#include <math/seadVectorFwd.h>
#include <prim/seadSafeString.h>
#include <nn/g3d/ResFile.h>
#include <math/seadMatrix.h>

class GameDataHolderWriter;
class ChangeStageInfo;
class GameDataHolderAccessor;
class ShineInfo;
class GameDataHolder;
class GameDataFile;
class RiseMapPartsHolder;
class Shine;
class QuestInfo;
class SessionEventProgress;
class WorldTravelingNpc;
class BindInfo;
class ScenarioStartCamera;
class CollectBgm;
struct HackObjInfo;
struct ShopItemInfo;

namespace al {
    class LiveActor;
    class PlacementId;
    class IUseSceneObjHolder;
    class SceneObjHolder;
    class GameDataHolderBase;
    class LayoutActor;
    class ActorInitInfo;
    class PlacementInfo;
    class Scene;
    class IUseMessageSystem;
    class CameraTicket;
} // namespace al

namespace GameDataFunction {
    GameDataHolder getGameDataHolder(const al::IUseSceneObjHolder*);
    GameDataHolder getGameDataHolder(const al::SceneObjHolder*);
    GameDataHolder getGameDataHolder(al::GameDataHolderBase*);
    GameDataFile getGameDataFile(GameDataHolderWriter);
    void setPlayingFileId(GameDataHolderWriter, s32);
    void initializeData(GameDataHolderWriter, s32);
    bool isPlayDemoOpening(GameDataHolderAccessor);
    bool isGameClear(GameDataHolderAccessor);
    void setRequireSave(GameDataHolderWriter);
    void setRequireSaveFrame(GameDataHolderWriter);
    s64 getPlayTimeTotal(GameDataHolderAccessor);
    s64 getPlayTimeAcrossFile(GameDataHolderAccessor);
    s32 getSaveDataIdForPrepo(GameDataHolderAccessor);
    void startDemoStage(GameDataHolderWriter, const char*);
    bool tryChangeNextStage(GameDataHolderWriter, const ChangeStageInfo*);
    bool tryChangeNextStageWithStartRaceFlag(GameDataHolderWriter, const ChangeStageInfo*);
    bool tryChangeNextStageWithStartRaceYukimaru(GameDataHolderWriter, const ChangeStageInfo*);
    bool tryChangeNextStageWithDemoWorldWarp(GameDataHolderWriter, const char*);
    bool tryChangeNextStageWithWorldWarpHole(GameDataHolderWriter, const char*);
    void changeNextStageWithStartTimeBalloon(GameDataHolderWriter, s32);
    const char* getCurrentStageName(GameDataHolderAccessor);
    void changeNextStageWithEndTimeBalloon(GameDataHolderWriter);
    void changeNextStageWithCloset(GameDataHolderWriter);
    void findAreaAndChangeNextStage(GameDataHolderWriter, const al::LiveActor*, const sead::Vector3f*);
    void returnPrevStage(GameDataHolderWriter);
    bool isTimeBalloonSequence(GameDataHolderAccessor);
    const char* getNextStageName(GameDataHolderAccessor);
    const char* getCurrentStageName(GameDataHolderAccessor, s32);
    bool isSeaOfTreeStage(GameDataHolderAccessor);
    const char* getNextStageName(GameDataHolderAccessor, s32);
    s32 calcNextScenarioNo(GameDataHolderAccessor);
    void restartStage(GameDataHolderWriter);
    void missAndRestartStage(GameDataHolderWriter);
    bool isMissEndPrevStageForInit(GameDataHolderAccessor);
    bool isMissEndPrevStageForSceneDead(GameDataHolderAccessor);
    void reenterStage(GameDataHolderWriter);
    s32 getNextWorldId(GameDataHolderAccessor);
    s32 getPrevWorldId(GameDataHolderAccessor);
    s32 getWorldNumForNewReleaseShop(GameDataHolderAccessor);
    bool isAlreadyGoWorld(GameDataHolderAccessor, s32);
    const char* getWorldDevelopName(GameDataHolderAccessor, s32);
    s32 getWorldIdForNewReleaseShop(GameDataHolderAccessor, s32);
    bool isForwardWorldWarpDemo(GameDataHolderAccessor);
    s32 getWorldNum(GameDataHolderAccessor);
    bool isFirstTimeNextWorld(GameDataHolderAccessor);
    void checkIsNewWorldInAlreadyGoWorld(GameDataHolderAccessor);
    s32 getCurrentWorldIdNoDevelop(GameDataHolderAccessor);
    s32 getScenarioNo(const al::LiveActor*);
    s32 getScenarioNo(const al::LayoutActor*);
    s32 getScenarioNoPlacement(GameDataHolderAccessor);
    bool isEqualScenario(const RiseMapPartsHolder*, s32);
    s32 getMainQuestMin(const al::LiveActor*);
    s32 getCurrentWorldId(GameDataHolderAccessor);
    void clearStartId(GameDataHolderWriter);
    void setCheckpointId(GameDataHolderWriter, const al::PlacementId*);
    void setRestartPointId(GameDataHolderWriter, const al::PlacementId*);
    void tryGetRestartPointIdString(GameDataHolderAccessor);
    void tryGetPlayerStartId(GameDataHolderAccessor);
    bool isPlayerStartObj(const al::LiveActor*, const al::ActorInitInfo&);
    bool isPlayerStartObj(const al::LiveActor*, const al::PlacementInfo&);
    bool isPlayerStartObj(const al::LiveActor*, const char*);
    bool isPlayerStartLinkedObj(const al::LiveActor*, const al::ActorInitInfo&, const char*);
    void setStartShine(const al::LiveActor*, const ShineInfo*);
    s32 getStartShineNextIndex(GameDataHolderAccessor);
    bool isAlreadyShowExplainCheckpointFlag(GameDataHolderAccessor);
    bool isEnableShowExplainCheckpointFlag(GameDataHolderAccessor);
    void showExplainCheckpointFlag(GameDataHolderAccessor);
    s32 getLifeMaxUpItem(const al::LiveActor*);
    s32 getPlayerHitPoint(GameDataHolderAccessor);
    s32 getPlayerHitPointMaxCurrent(GameDataHolderAccessor);
    s32 getPlayerHitPointMaxNormal(GameDataHolderAccessor);
    bool isPlayerHitPointMax(GameDataHolderAccessor);
    bool isPlayerHitPointMaxWithItem(GameDataHolderAccessor);
    void recoveryPlayer(const al::LiveActor*);
    void recoveryPlayerForDebug(const al::LiveActor*);
    void recoveryPlayerMax(const al::LiveActor*);
    void recoveryPlayerForSystem(const GameDataHolder*);
    void recoveryPlayerMaxForSystem(const GameDataHolder*);
    void initPlayerHitPointForSystem(const GameDataHolder*);
    void damagePlayer(GameDataHolderWriter);
    void killPlayer(GameDataHolderWriter);
    bool isPlayerLifeZero(GameDataHolderAccessor);
    bool isGotShine(GameDataHolderAccessor, const ShineInfo*);
    bool isGotShine(GameDataHolderAccessor, const al::PlacementId*);
    bool isGotShine(GameDataHolderAccessor, const char*, const char*);
    bool isGotShine(GameDataHolderAccessor, s32);
    bool isGotShine(const Shine*);
    void setGotShine(GameDataHolderWriter, const ShineInfo*);
    s32 getGotShineNum(GameDataHolderAccessor, s32);
    ShineInfo* getLatestGetShineInfo(GameDataHolderAccessor);
    s32 getCurrentShineNum(GameDataHolderAccessor);
    s32 getTotalShineNum(GameDataHolderAccessor, s32);
    s32 getTotalShopShineNum(GameDataHolderAccessor, s32);
    void tryGetNextMainScenarioLabel(sead::BufferedSafeStringBase<s8>*, sead::BufferedSafeStringBase<s8>*, const al::IUseSceneObjHolder*);
    s32 getMainScenarioNumMax(GameDataHolderAccessor);
    void setMainScenarioNo(GameDataHolderWriter, s32);
    void tryGetNextMainScenarioPos(sead::Vector3f*, GameDataHolderAccessor);
    bool isPlayScenarioCamera(GameDataHolderAccessor, const QuestInfo*);
    bool isPlayAlreadyScenarioStartCamera(GameDataHolderAccessor, s32);
    bool isEnterStageFirst(GameDataHolderAccessor);
    bool isNextMainShine(GameDataHolderAccessor, s32);
    bool isMainShine(GameDataHolderAccessor, s32);
    bool isLatestGetMainShine(GameDataHolderAccessor, const ShineInfo*);
    bool tryFindLinkedShineIndex(const al::LiveActor*, const al::ActorInitInfo&);
    bool tryFindLinkedShineIndex(const al::LiveActor*, const al::ActorInitInfo&, s32);
    bool tryFindLinkedShineIndexByLinkName(const al::LiveActor*, const al::ActorInitInfo&, const char*);
    void calcLinkedShineNum(const al::LiveActor*, const al::ActorInitInfo&);
    bool tryFindShineIndex(const al::LiveActor*, const al::ActorInitInfo&);
    bool tryFindShineIndex(const al::LiveActor*, const char*, const char*);
    bool tryFindShineUniqueId(const al::Scene*, const ShineInfo*);
    void disableHintByShineIndex(const al::LiveActor*, s32);
    void enableHintByShineIndex(const al::LiveActor*, s32);
    void calcIsGetMainShineAll(const al::IUseSceneObjHolder*);
    void calcIsGetShineAllInWorld(GameDataHolderAccessor, s32);
    void calcIsGetShineAllInAllWorld(GameDataHolderAccessor);
    bool tryFindAndInitShineInfoByOptionalId(ShineInfo*, GameDataHolderAccessor, const char*);
    bool isGotLinkedShineBeforeInitActor(const al::ActorInitInfo&, const char*);
    void checkIsComplete(const al::IUseSceneObjHolder*, s32);
    bool isExistInHackDictionary(GameDataHolderAccessor, const char*, s32);
    s32 getCollectedBgmNum(GameDataHolderAccessor, s32);
    s32 getCollectedBgmMaxNum(GameDataHolderWriter);
    bool isEnableOpenMoonRock(const al::LiveActor*);
    void openMoonRock(const al::LiveActor*, const al::PlacementId*);
    bool isOpenMoonRock(GameDataHolderAccessor);
    bool isEnableShowDemoOpenMoonRockFirst(GameDataHolderAccessor);
    bool isEnableShowDemoOpenMoonRockWorld(GameDataHolderAccessor);
    void showDemoOpenMoonRockFirst(GameDataHolderAccessor);
    void showDemoOpenMoonRockWorld(GameDataHolderAccessor);
    void calcMoonRockTalkMessageIndex(GameDataHolderAccessor);
    void addMoonRockTalkMessageIndex(GameDataHolderWriter);
    bool isAppearedMoonRockTalkMessage(GameDataHolderAccessor);
    void addPayShine(GameDataHolderWriter, s32);
    void addPayShineCurrentAll(GameDataHolderWriter);
    s32 getPayShineNum(GameDataHolderAccessor);
    s32 getPayShineNum(GameDataHolderAccessor, s32);
    s32 getTotalPayShineNum(GameDataHolderAccessor);
    s32 getTotalPayShineNumClamp(GameDataHolderAccessor);
    bool isPayShineAllInAllWorld(GameDataHolderAccessor);
    void addKey(GameDataHolderWriter, s32);
    s32 getKeyNum(GameDataHolderAccessor);
    s32 getCurrentKeyNum(GameDataHolderAccessor);
    s32 getOpenDoorLockNum(GameDataHolderAccessor);
    void openDoorLock(GameDataHolderWriter, const al::PlacementId*);
    bool isOpenDoorLock(GameDataHolderAccessor, const al::PlacementId*);
    void setObjStarted(GameDataHolder*, const al::PlacementId*);
    bool isObjStarted(const GameDataHolder*, const al::PlacementId*);
    bool isObjStarted(GameDataHolderAccessor, const char*, const char*);
    void saveObjS32(GameDataHolderWriter, const al::PlacementId*, s32);
    bool tryFindSaveObjS32Value(s32*, GameDataHolderAccessor, const al::PlacementId*);
    void onObjNoWriteSaveData(GameDataHolderWriter, const al::PlacementId*);
    void offObjNoWriteSaveData(GameDataHolderWriter, const al::PlacementId*);
    bool isOnObjNoWriteSaveData(GameDataHolderAccessor, const al::PlacementId*);
    void onObjNoWriteSaveDataResetMiniGame(GameDataHolderWriter, const al::PlacementId*);
    void offObjNoWriteSaveDataResetMiniGame(GameDataHolderWriter, const al::PlacementId*);
    bool isOnObjNoWriteSaveDataResetMiniGame(GameDataHolderAccessor, const al::PlacementId*);
    void onObjNoWriteSaveDataInSameScenario(GameDataHolder*, const al::PlacementId*);
    bool isOnObjNoWriteSaveDataInSameScenario(const GameDataHolder*, const al::PlacementId*);
    void setSessionEventProgress(GameDataHolderWriter, const SessionEventProgress&);
    SessionEventProgress*  getSessionEventProgress(GameDataHolderAccessor);
    bool isPayCoinToSphinx(const al::LiveActor*);
    void payCoinToSphinx(const al::LiveActor*);
    bool isRemovedCapByJango(const al::LiveActor*);
    bool isMainStage(GameDataHolderAccessor);
    bool isGetCapFromJango(const al::LiveActor*);
    void removeCapByJango(const al::LiveActor*);
    void getCapFromJango(const al::LiveActor*);
    void addJangoCount(const al::LiveActor*);
    s32 getJangoCount(const al::LiveActor*);
    bool isFirstWorldTravelingStatus(const WorldTravelingNpc*);
    void saveWorldTravelingStatus(const WorldTravelingNpc*, const char*);
    const char* getWorldTravelingStatus(const WorldTravelingNpc*);
    bool isRaceStart(GameDataHolderAccessor);
    bool isRaceStartFlag(GameDataHolderAccessor);
    bool isRaceStartYukimaru(GameDataHolderAccessor);
    bool isRaceStartYukimaruTutorial(GameDataHolderAccessor);
    bool isRaceWin(GameDataHolderAccessor);
    bool isRaceWin(GameDataHolderAccessor, s32);
    bool isRaceResultSecond(GameDataHolderAccessor);
    bool isRaceResultThird(GameDataHolderAccessor);
    bool isRaceLose(GameDataHolderAccessor);
    bool isRaceCancel(GameDataHolderAccessor);
    void winRace(GameDataHolderWriter);
    void endRaceResultSecond(GameDataHolderWriter);
    void endRaceResultThird(GameDataHolderWriter);
    void loseRace(GameDataHolderWriter);
    s32 getRaceRivalLevel(const al::LiveActor*);
    s32 getRaceRivalLevel(const al::Scene*);
    void setRaceRivalLevel(const al::LiveActor*, s32);
    void setLastRaceRanking(GameDataHolderAccessor, s32);
    s32 getLastRaceRanking(GameDataHolderWriter);
    void incrementRaceLoseCount(const al::Scene*, s32);
    s32 getRaceLoseCount(const al::LiveActor*, s32);
    void addCoinCollect(GameDataHolderWriter, const al::PlacementId*);
    void useCoinCollect(GameDataHolderWriter, s32);
    bool isGotCoinCollect(GameDataHolderAccessor, const al::ActorInitInfo&);
    s32 getCoinCollectNum(GameDataHolderAccessor);
    s32 getCoinCollectGotNum(GameDataHolderAccessor);
    s32 getCoinCollectGotNum(GameDataHolderAccessor, s32);
    s32 getCoinCollectNumMax(GameDataHolderAccessor);
    s32 getCoinCollectNumMax(GameDataHolderAccessor, s32);
    bool tryFindExistCoinCollectStagePosExcludeHomeStageInCurrentWorld(sead::Vector3f*, const char**, GameDataHolderAccessor);
    s32 getWorldScenarioNo(GameDataHolderAccessor, s32);
    void addCoin(GameDataHolderWriter, s32);
    void subCoin(GameDataHolderWriter, s32);
    s32 getCoinNum(GameDataHolderAccessor);
    s32 getTotalCoinNum(GameDataHolderAccessor);
    bool isAppearCourseName(GameDataHolderAccessor);
    void setStageHakoniwa(GameDataHolderWriter);
    bool isEnableCheckpointWarp(GameDataHolderAccessor);
    void validateCheckpointWarp(GameDataHolderWriter);
    void invalidateCheckpointWarp(GameDataHolderWriter);
    s32 getCheckpointNumMaxInWorld(GameDataHolderAccessor);
    sead::Vector3f* getCheckpointTransInWorld(GameDataHolderAccessor, s32);
    const char* getCheckpointObjIdInWorld(GameDataHolderAccessor, s32);
    sead::Vector3f* getCheckpointTransInWorld(GameDataHolderAccessor, const char*);
    bool isGotCheckpointInWorld(GameDataHolderAccessor, s32);
    bool isGotCheckpoint(GameDataHolderAccessor, al::PlacementId*);
    void calcGotCheckpointNumInWorld(GameDataHolderAccessor);
    void changeNextSceneByGotCheckpoint(GameDataHolderWriter, s32);
    void changeNextSceneByHome(GameDataHolderWriter);
    bool isWarpCheckpoint(GameDataHolderAccessor);
    const char* getCheckpointWarpObjId(GameDataHolderAccessor);
    void registerCheckpointTrans(GameDataHolderWriter, const al::PlacementId*, const sead::Vector3f&);
    bool isEnableUnlockHint(GameDataHolderAccessor);
    void unlockHint(GameDataHolderWriter);
    void unlockHintAmiibo(GameDataHolderWriter);
    void calcHintNum(GameDataHolderAccessor);
    void calcRestHintNum(GameDataHolderAccessor);
    void checkExistHint(GameDataHolderAccessor);
    s32 getHintNumMax(GameDataHolderAccessor);
    void calcHintTrans(GameDataHolderAccessor, s32);
    sead::Vector3f* getLatestHintTrans(GameDataHolderAccessor);
    void checkLatestHintSeaOfTree(GameDataHolderAccessor);
    void calcHintMoonRockNum(GameDataHolderAccessor);
    s32 getHintMoonRockNumMax(GameDataHolderAccessor);
    void calcHintMoonRockTrans(GameDataHolderAccessor, s32);
    void initializeHintList(GameDataHolderWriter);
    void calcHintTransMostEasy(GameDataHolderAccessor);
    void calcHintTransMostNear(sead::Vector3f*, GameDataHolderAccessor, const sead::Vector3f&);
    void checkHintSeaOfTree(GameDataHolderAccessor, s32);
    void checkHintSeaOfTreeMoonRock(GameDataHolderAccessor, s32);
    void findUnlockShineNum(bool*, GameDataHolderAccessor);
    void findUnlockShineNumByWorldId(bool*, GameDataHolderAccessor, s32);
    bool isUnlockedWorld(GameDataHolderAccessor, s32);
    bool isUnlockedNextWorld(GameDataHolderAccessor);
    bool isUnlockedAllWorld(GameDataHolderAccessor);
    s32 getWorldIndexSpecial2();
    bool isUnlockedCurrentWorld(GameDataHolderAccessor);
    bool isCollectShineForNextWorldAndNotUnlockNextWorld(const al::LiveActor*);
    const char* getMainStageName(GameDataHolderAccessor, s32);
    void tryGetCurrentMainStageName(GameDataHolderAccessor);
    void tryGetWorldName(const al::LayoutActor*, s32);
    void tryGetWorldNameCurrent(const al::LayoutActor*);
    void tryGetRegionNameCurrent(const al::LayoutActor*);
    const char* getWorldDevelopNameCurrent(GameDataHolderAccessor);
    s32 getWorldScenarioNum(GameDataHolderAccessor, s32);
    void findMainStageNameByDevelopName(GameDataHolderAccessor, const char*);
    void findWorldIdByDevelopName(GameDataHolderAccessor, const char*);
    bool tryFindWorldIdByMainStageName(const al::Scene*, const char*);
    bool tryFindWorldIdByMainStageName(const al::IUseSceneObjHolder*, const char*);
    void checkEnableUnlockWorldSpecial1(const al::LiveActor*);
    s32 getWorldIndexSpecial1();
    void checkEnableUnlockWorldSpecial2(const al::LiveActor*);
    void tryGetWorldNameByFileId(const al::LayoutActor*, s32);
    bool isNewSaveDataByFileId(const al::LayoutActor*, s32);
    s64 getLastUpdateFileTime(const al::LayoutActor*, s32);
    void makeTextureSaveDataFileName(sead::BufferedSafeStringBase<s8>*, const nn::g3d::ResFile*, const GameDataHolder*, s32);
    s32 getWorldIndexPeach();
    s32 getWorldIndexCity();
    bool isCityWorldCeremonyAll(s32, s32);
    s32 getWorldIndexSea();
    void unlockWorld(GameDataHolderWriter, s32);
    s32 getUnlockWorldIdForWorldMap(const al::LayoutActor*, s32);
    s32 getUnlockWorldIdForWorldMap(const al::LiveActor*, s32);
    s32 getUnlockWorldIdForWorldMap(const al::Scene*, s32);
    s32 getUnlockWorldIdForWorldMap(const GameDataHolder*, s32);
    s32 getUnlockWorldNumForWorldMap(const al::Scene*);
    s32 getUnlockWorldNumForWorldMap(const al::LiveActor*);
    s32 getUnlockWorldNumForWorldMap(const al::LayoutActor*);
    void calcNextLockedWorldIdForWorldMap(const al::LayoutActor*, s32);
    void calcNextLockedWorldIdForWorldMap(const al::Scene*, s32);
    void calcNextLockedWorldNumForWorldMap(const al::Scene*);
    void calcNextLockedWorldNumForWorldMap(const al::LayoutActor*);
    s32 getWorldIdForShineList(const al::LayoutActor*, s32);
    void calcWorldNumForShineList(const al::LayoutActor*);
    s32 getLatestUnlockWorldIdForShineTowerMeter(const al::LiveActor*);
    bool isClearSandWorldScenario1(const al::Scene*);
    bool isClearCityWorldScenario1(const al::Scene*);
    bool isClearSkyWorldScenario1(const al::Scene*);
    bool isCityWorldScenario2(const al::IUseSceneObjHolder*);
    bool isWorldCity(GameDataHolderAccessor);
    void calcNextWorldId(GameDataHolderAccessor);
    bool isPlayDemoWorldWarp(GameDataHolderAccessor);
    bool isPlayDemoWorldWarpHole(GameDataHolderAccessor);
    void noPlayDemoWorldWarp(GameDataHolderWriter);
    bool isPlayDemoReturnToHome(GameDataHolderAccessor);
    void requestPlayDemoReturnToHome(GameDataHolderWriter);
    bool isPlayDemoAwardSpecial(GameDataHolderAccessor);
    void requestPlayDemoAwardSpecial(GameDataHolderWriter);
    bool isPlayDemoLavaErupt(GameDataHolderAccessor);
    bool isPlayDemoPlayerDownForBattleKoopaAfter(GameDataHolderAccessor);
    void disablePlayDemoPlayerDownForBattleKoopaAfter(GameDataHolderWriter);
    void enteredStage(GameDataHolderWriter);
    const char* getCurrentCostumeTypeName(GameDataHolderAccessor);
    const char* getCurrentCapTypeName(GameDataHolderAccessor);
    void wearCostume(GameDataHolderWriter, const char*);
    void wearCap(GameDataHolderWriter, const char*);
    void wearCostumeRandom(al::IUseSceneObjHolder*);
    void wearCapRandom(al::IUseSceneObjHolder*);
    bool tryWearCostumeRandomIfEnable(al::IUseSceneObjHolder*);
    bool isCostumeRandomMode(al::IUseSceneObjHolder*);
    bool tryWearCapRandomIfEnable(al::IUseSceneObjHolder*);
    bool isCapRandomMode(al::IUseSceneObjHolder*);
    void setCostumeRandomMode(al::IUseSceneObjHolder*);
    void setCapRandomMode(al::IUseSceneObjHolder*);
    void resetCostumeRandomMode(al::IUseSceneObjHolder*);
    void resetCapRandomMode(al::IUseSceneObjHolder*);
    ShopItemInfo* getShopItemInfoList(GameDataHolderAccessor);
    bool isExistHackObjInfo(GameDataHolderAccessor, const char*);
    HackObjInfo* getHackObjInfo(GameDataHolderAccessor, const char*);
    void addHackDictionary(GameDataHolderWriter, const char*);
    bool isExistInHackDictionary(GameDataHolderAccessor, const char*);
    bool isShowHackTutorial(GameDataHolderAccessor, const char*, const char*);
    void setShowHackTutorial(GameDataHolderWriter, const char*, const char*);
    bool isShowBindTutorial(GameDataHolderAccessor, const BindInfo&);
    void setShowBindTutorial(GameDataHolderWriter, const BindInfo&);
    bool isGotShine(GameDataHolderAccessor, s32, s32);
    bool isOpenShineName(const al::LayoutActor*, s32, s32);
    void checkAchievementShine(const al::LayoutActor*, s32, s32);
    void calcShineNumInOneShine(const al::LayoutActor*, s32, s32);
    bool tryFindShineMessage(const al::LayoutActor*, s32, s32);
    bool tryFindShineMessage(const al::LiveActor*, const al::IUseMessageSystem*, s32, s32);
    void findShineGetTime(const al::LayoutActor*, s32, s32);
    void checkMoonRockShineForShineList(const al::LayoutActor*, s32, s32);
    void checkUnlockHintByHintNpcForShineList(const al::LayoutActor*, s32, s32);
    void checkUnlockHintByAmiiboForShineList(const al::LayoutActor*, s32, s32);
    void checkShineSeaOfTreeForShineList(const al::LayoutActor*, s32, s32);
    s32 getWorldTotalShineNum(GameDataHolderAccessor, s32);
    s32 getWorldTotalShineNumMax(GameDataHolderAccessor, s32);
    void findShineTrans(sead::Vector3f*, GameDataHolderAccessor, s32, s32);
    sead::Vector3f* getHomeTrans(GameDataHolderAccessor);
    bool isExistHome(GameDataHolderAccessor);
    bool isActivateHome(GameDataHolderAccessor);
    s32 getMiniGameNum(GameDataHolderAccessor);
    s32 getMiniGameNumMax(GameDataHolderAccessor);
    sead::Vector3f* getMiniGameTrans(GameDataHolderAccessor, s32);
    s32 getMiniGameName(GameDataHolderAccessor, s32);
    sead::Vector3f* getRaceStartTrans(GameDataHolderAccessor);
    sead::Vector3f* getRaceGoalTrans(GameDataHolderAccessor);
    sead::Vector3f* getHintNpcTrans(GameDataHolderAccessor);
    sead::Vector3f* getShopNpcTrans(GameDataHolderAccessor, s32);
    bool isShopSellout(GameDataHolderAccessor, s32);
    void calcShopNum(GameDataHolderAccessor);
    s32 getShopNpcIconNumMax(GameDataHolderAccessor);
    bool isExistRaceStartNpc(GameDataHolderAccessor);
    bool isExistHintNpc(GameDataHolderAccessor);
    sead::Matrix34f* getCurrentMapView(GameDataHolderAccessor);
    bool isExistJango(GameDataHolderAccessor);
    sead::Vector3f* getJangoTrans(GameDataHolderAccessor);
    bool isExistAmiiboNpc(GameDataHolderAccessor);
    sead::Vector3f* getAmiiboNpcTrans(GameDataHolderAccessor);
    bool isInInvalidOpenMapStage(GameDataHolderAccessor);
    sead::Vector3f* getStageMapPlayerPos(GameDataHolderAccessor);
    bool isExistTimeBalloonNpc(GameDataHolderAccessor);
    sead::Vector3f* getTimeBalloonNpcTrans(GameDataHolderAccessor);
    bool isExistPoetter(GameDataHolderAccessor);
    sead::Vector3f* getPoetterTrans(GameDataHolderAccessor);
    sead::Vector3f* getMoonRockTrans(GameDataHolderAccessor);
    void setHomeTrans(const al::LiveActor*, const sead::Vector3f&);
    void setRaceStartNpcTrans(const al::LiveActor*);
    void setRaceStartTrans(const al::LiveActor*);
    void setRaceGoalTrans(const al::LiveActor*);
    void setHintNpcTrans(const al::LiveActor*);
    void setJangoTrans(const al::LiveActor*);
    void disableJangoTrans(const al::LiveActor*);
    void setAmiiboNpcTrans(const al::LiveActor*);
    void setShopNpcTrans(const al::LiveActor*, const char*, s32);
    void setShopNpcTrans(GameDataHolderAccessor, const al::PlacementInfo&);
    void setMiniGameInfo(GameDataHolderAccessor, const al::PlacementInfo&);
    void setTimeBalloonTrans(GameDataHolderAccessor, const sead::Vector3f&);
    void setPoetterTrans(GameDataHolderAccessor, const sead::Vector3f&);
    void setStageMapPlayerPos(GameDataHolderWriter, const sead::Vector3f&);
    void setMoonRockTrans(GameDataHolderWriter, const sead::Vector3f&);
    s32 getHomeLevel(GameDataHolderAccessor);
    void upHomeLevel(GameDataHolderWriter);
    void activateHome(GameDataHolderWriter);
    bool isLaunchHome(GameDataHolderAccessor);
    void launchHome(GameDataHolderWriter);
    bool isCrashHome(GameDataHolderAccessor);
    void crashHome(GameDataHolderWriter);
    bool isRepairHome(GameDataHolderAccessor);
    void repairHome(GameDataHolderWriter);
    bool isBossAttackedHome(GameDataHolderAccessor);
    void bossAttackHome(GameDataHolderWriter);
    bool isRepairHomeByCrashedBoss(GameDataHolderAccessor);
    void repairHomeByCrashedBoss(GameDataHolderWriter);
    bool isFindKoopaNext(GameDataHolderAccessor, s32);
    bool isBossAttackedHomeNext(GameDataHolderAccessor, s32);
    bool isFindKoopa(GameDataHolderAccessor);
    void findKoopa(GameDataHolderWriter);
    bool isEnableCap(GameDataHolderAccessor);
    bool isMeetCap(GameDataHolderAccessor);
    void enableCap(GameDataHolderWriter);
    void disableCapByPlacement(const al::LiveActor*);
    bool isTalkedCapNearHomeInWaterfall(const al::LiveActor*);
    void talkCapNearHomeInWaterfall(const al::LiveActor*);
    bool isFlagOnTalkMessageInfo(const al::IUseSceneObjHolder*, s32);
    void onFlagTalkMessageInfo(const al::IUseSceneObjHolder*, s32);
    s32 getWorldIndexHat();
    s32 getWorldIndexWaterfall();
    s32 getWorldIndexSand();
    s32 getWorldIndexForest();
    s32 getWorldIndexLake();
    s32 getWorldIndexCloud();
    s32 getWorldIndexClash();
    s32 getWorldIndexSnow();
    s32 getWorldIndexLava();
    s32 getWorldIndexBoss();
    s32 getWorldIndexSky();
    s32 getWorldIndexMoon();
    bool isWorldCap(GameDataHolderAccessor);
    bool isWorldWaterfall(GameDataHolderAccessor);
    bool isWorldSand(GameDataHolderAccessor);
    bool isWorldForest(GameDataHolderAccessor);
    bool isWorldLake(GameDataHolderAccessor);
    bool isWorldCloud(GameDataHolderAccessor);
    bool isWorldClash(GameDataHolderAccessor);
    bool isWorldSnow(GameDataHolderAccessor);
    bool isWorldSea(GameDataHolderAccessor);
    bool isWorldBoss(GameDataHolderAccessor);
    bool isWorldSky(GameDataHolderAccessor);
    bool isWorldMoon(GameDataHolderAccessor);
    bool isWorldPeach(GameDataHolderAccessor);
    bool isWorldSpecial1(GameDataHolderAccessor);
    bool isWorldSpecial2(GameDataHolderAccessor);
    bool isWorldTypeMoon(GameDataHolderAccessor, s32);
    bool isSnowMainScenario1(const al::IUseSceneObjHolder*);
    bool isSnowMainScenario2(const al::IUseSceneObjHolder*);
    bool isHomeShipStage(const GameDataHolder*);
    const char* getHomeShipStageName();
    bool isCityWorldCeremonyAgain(s32, s32);
    bool isGoToCeremonyFromInsideHomeShip(GameDataHolderAccessor);
    void registerScenarioStartCameraInfo(const ScenarioStartCamera*, s32, al::CameraTicket*);
    bool isEnableExplainAmiibo(GameDataHolderAccessor);
    void endExplainAmiibo(GameDataHolderWriter);
    void startSearchHintByAmiibo(GameDataHolderWriter);
    void endSearchHintByAmiibo(GameDataHolderWriter);
    void setKidsModeOn(const al::Scene*);
    void setKidsModeOff(const al::Scene*);
    bool isCollectedBgm(GameDataHolderAccessor, const char*, const char*);
    CollectBgm* getCollectBgmByIndex(GameDataHolderAccessor, s32);
    bool trySetCollectedBgm(GameDataHolderWriter, const char*, const char*);
    s32 getCollectedBgmNum(GameDataHolderWriter);
    void registerShineInfo(GameDataHolderAccessor, const ShineInfo*, const sead::Vector3f&);
    void setHintTrans(GameDataHolderAccessor, s32, const sead::Vector3f&);
    void resetHintTrans(GameDataHolderAccessor, s32);
    bool isKoopaLv3(GameDataHolderAccessor);

};