#pragma once

#include "al/Library/Area/AreaObjDirector.h"
#include "al/Library/Bgm/BgmDirector.h"
#include "al/Library/HostIO/HioNode.h"
#include "al/Library/Se/SeDirector.h"
#include "AudioSystemPauseController.h"

namespace aal {
class IAudioFrameProcess;
}
namespace al {
class SeDirector;
class BgmDirector;
class AudioMic;
class AudioEventController;
class AudioRequestKeeperSyncedBgm;
struct AudioSystemInfo;
class Sequence;
class AudioDuckingDirector;
class AudioFrameProcessMgr;
struct AudioEffectController;
class PlayerHolder;
class AudioMaximizer;
class DemoDirector;

struct AudioDirectorInitInfo {
    al::AudioSystemInfo* audioSystemInfo;
    al::Sequence* sequence;
    const char* currentStage;
    s32 scenarioNo;
    al::DemoDirector* demoDirector;
    al::SeDirectorInitInfo seDirectorInitInfo;
    al::BgmDirectorInitInfo bgmDirectorInitInfo;
    const char* duckingName;
};

class AudioDirector : public al::HioNode, public al::IUseAreaObj, public al::IAudioSystemPause {
private:
    struct PauseEntry {
        const char* name;
        bool active;
        bool field_0A;
    };
    al::SeDirector* mSeDirector;
    al::BgmDirector* mBgmDirector;
    al::AudioMic* mAudioMic;
    al::AudioEventController* mAudioEventController;
    al::AudioRequestKeeperSyncedBgm* mAudioRequestKeeperSyncedBgm;
    al::AudioSystemInfo* mAudioSystemInfo;
    al::Sequence* mSequence;
    al::AudioDuckingDirector* mAudioDuckingDirector;
    sead::PtrArray<PauseEntry> mPauseEntries;
    bool mIsEffectControllerFinalizing;
    al::AudioFrameProcessMgr* mAudioFrameProcessMgr;
    al::AudioEffectController* mAudioEffectController;

public:
    AudioDirector();
    void init(const al::AudioDirectorInitInfo& initInfo);
    void init3D(const al::AudioDirectorInitInfo& initInfo);
    void initAfterInitPlacement();
    void initMic(al::AudioMic* mic);
    void setDependentModule(al::AudioDirector* parentModule);
    void updatePre();
    void updatePost();
    void startFinalizeUnsafeModuleInParallelThread();
    void updateFinalizeUnsafeModuleInParallelThread();
    bool isFinalizedUnsafeModuleInParallelThread();
    void finalize();
    bool isSystemPauseNow();
    void setPlayerHolder(const al::PlayerHolder* playerHolder);
    void addAudiioFrameProccess(aal::IAudioFrameProcess* frameProcess);
    void removeAudiioFrameProccess(aal::IAudioFrameProcess* frameProcess);
    al::AudioMaximizer* getAudioMaximizer() const;
    void pauseSystem(bool, const char*, bool, f32, bool, bool, bool) override;
    bool isPpausedSystem(const char*);
    al::AreaObjDirector* getAreaObjDirector() const override;
};
}  // namespace al