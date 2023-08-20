#pragma once

#include <container/seadPtrArray.h>
#include "al/Library/Bgm/IUseActiveBgmLine.h"

namespace al {
class BgmDataBase;
class SeadAudioPlayer;
class BgmLineKeeper;
class BgmSituationDirector;
class Bgm3DParamsController;
class BgmMultiPlayingController;
class BgmRhythmSyncController;
struct AudioSystemInfo;
class AudioDirector;
class BgmPlayingRequest;
class FunctorBase;
class IBgmParamsChanger;
class AudioBusSendController;

struct BgmDirectorInitInfo {
    bool isScene;
    const char* stageName;
};

class BgmDirector : public al::IUseActiveBgmLine {
private:
    al::BgmDataBase* mBgmDataBase;
    al::SeadAudioPlayer* mBgmAudioPlayer;
    al::BgmLineKeeper* mBgmLineKeeper;
    s32 field_20;
    f32 field_24;
    s32 field_28;
    const char* mStageName;
    s32 scenarioNo;
    al::BgmDirector* mParentDirector;
    al::BgmSituationDirector* mBgmSituationDirector;
    al::Bgm3DParamsController* mBgm3DParamsController;
    sead::PtrArray<al::BgmMultiPlayingController> mBgmMultiPlayingControllers;
    al::BgmRhythmSyncController* mBgmRhythmSyncController;

public:
    BgmDirector();
    void init(const al::AudioSystemInfo*, const al::AudioDirector*, const al::BgmDirectorInitInfo&, const char*, s32);
    void setDependentModule(al::BgmDirector*);
    void reset(const char*, s32);
    void update();
    void clearPlayData();
    void enableLineChange();
    void finalize();
    void startBgm(const al::BgmPlayingRequest&, bool);
    void prepareBgm(const al::BgmPlayingRequest&);
    void stopBgm(const char*, s32);
    void endSituation(const char*, bool, bool);
    void pauseBgm(const char*, s32);
    void resumeBgm(const char*, s32);
    bool isPlayingBgm();
    bool isPlayingBgm(const char*);
    bool isRunningBgm(const char*);
    void pauseBgmById(u32, s32, bool);
    void updatePauseIdForPause(u32);
    void pauseBgmIfFadeOut(s32);
    void resumeBgmById(u32, s32, bool);
    void updatePauseIdForResume(u32);
    void resumeBgmIfFadeOut(s32);
    void stopAllBgm(s32, bool);
    void stopAllBgmWithoutUpperLayer(s32);
    bool tryStopAllBgm(s32);
    void setTriggerEventForStopAllBgm(const al::FunctorBase&);
    bool tryPauseBgmIfNotPlaying(const char*, s32);
    bool tryPauseBgmIfLowPriority(const char*, s32);
    void startSituation(const char*, bool, bool, bool);
    void startSituation(sead::PtrArray<al::IBgmParamsChanger>*, const char*, bool, bool, bool);
    void endSituation(sead::PtrArray<al::IBgmParamsChanger>*, const char*, bool, bool);
    void disableLineChange();
    bool isDisableLineChange();
    bool isUsedLineGroupName(const char*) const;
    void getPlayingBgmLine(const char*) const;
    void getBgmLineByLineName(const char*) const;
    al::BgmLine* getActiveBgmLine() const override;
    void getActiveBgmLineWithoutUpperLayer() const;
    void getLoopEndSamplePosition(const char*) const;
    void setAudioBusSendController(al::AudioBusSendController*);
    al::BgmMultiPlayingController*  tryAllocMultiPlayingController();
    bool tryReleaseMultiPlayingController(al::BgmMultiPlayingController*);
    void deactiveAllBgmMultiPlayingController(s32);
    s32 getBgmLineNum(bool);
    void getBgmLineAccessor(s32, bool);
    void getBgmLineIndex(const char*, bool) const;
};
}  // namespace al