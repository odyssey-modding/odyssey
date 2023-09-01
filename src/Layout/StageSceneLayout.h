#pragma once

#include <al/Library/Nerve/NerveStateBase.h>

class CoinCounter;
class CounterLifeCtrl;
class ShineCounter;
class CoinCounter;
class ShineChipLayoutParts;
class PlayGuideCamera;
class PlayGuideBgm;
class MapMini;
class SimpleLayoutAppearWaitEnd;
class GamePadPlayStyleInfo;

namespace al {
    class LayoutActor;
    class LayoutInitInfo;
    class PlayerHolder;
    class SubCameraRenderer;
} // namespace al

class StageSceneLayout : public al::NerveStateBase {
private:
    CoinCounter* mCoinCounter;
    CounterLifeCtrl* mCounterLifeCtrl;
    ShineCounter* mShineCounter;
    CoinCounter* mCoinCollectCounter;
    ShineChipLayoutParts* mShineChipLayoutParts;
    PlayGuideCamera* mPlayerGuideCamera;
    PlayGuideBgm* mPlayGuideBgm;
    MapMini* mMapMini;
    al::PlayerHolder* mPlayerHolder;
    bool field_60;
    SimpleLayoutAppearWaitEnd* mPlayGuideMenu;
    GamePadPlayStyleInfo* mGamePadPlayStyleInfo;
    al::LayoutActor* mKidsModeLayout;


public:
    StageSceneLayout(const char*, const al::LayoutInitInfo&, const al::PlayerHolder*, const al::SubCameraRenderer*);
    ~StageSceneLayout() override;
    void startActionAll(const char*);
    void control();
    void updatePlayGuideMenuText();
    void setDirtyFlagForPlayGuideMenu();
    void start();
    void updateCounterParts();
    bool tryAppearCoinCollectCounter();
    void startOnlyCoin(bool);
    void endWithoutCoin(bool);
    void end();
    bool isEnd() const;
    bool isWait() const;
    bool isActive() const;
    bool isEndLifeDemo() const;
    bool tryStartLifeDemo();
    void startCoinCountAnim(s32);
    void startCoinCollectCountAnim(s32);
    void appearCoinCounterForDemo();
    bool isEndCoinCountAnim() const;
    bool isEndShineChipCompleteAnim() const;
    void startShineChipCompleteAnim();
    void endShineChipCompleteAnim();
    bool tryStartDemoGetLifeMaxUpItem(bool);
    bool isEndDemoGetLifeMaxUpItem() const;
    void killShineCount();
    void appearShineCountWait();
    void startCloset();
    void endCloset();
    void missEnd();
    void appearPlayGuideCamera();
    void exeAppear();
    bool isActionEndAll() const;
    void exeWait();
    void exeEnd();
    void exeEndWithoutCoin();
    void exeCoinCountAnim();
    void exeShineChipComplete();
    void exeShineCountAppear();
    void updateLifeCounter();
    void updateKidsModeLayout();
    void startShineCountAnim(bool);
    bool isEndShineCountAnim() const;
};