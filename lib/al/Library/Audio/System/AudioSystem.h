#pragma once

#include <nn/audio.h>
#include <nn/os.h>

namespace aal {
class IAudioFrameProcess;
}

namespace al {
class AudioResourcePlayerKeeper;
struct AudioSoundArchiveInfo;
class SeDataBase;
class BgmDataBase;
class AudioInfoListWithParts;
struct AudioSystemInfo;
class AudioEffectDataBase;
class CollisionCodeList;
class AudioSystemPauseController;
class AudioSystemNin;
class AudioBusSendController;
class AudioFrameProcessMgr;
class AudioMaximizer;
struct AudioSystemInitInfo;

class AudioSystem {
private:
    al::AudioResourcePlayerKeeper* mAudioResourcePlayerKeeper;
    al::AudioSoundArchiveInfo** mAudioResourceLoadingInfo;
    al::SeDataBase* mSeDataBase;
    al::BgmDataBase* mBgmDataBase;
    al::AudioInfoListWithParts* mBgmMusicalInfoList;
    al::AudioSystemInfo* mAudioSystemInfo;
    float mMasterVolume;
    float mDockedVolume;
    float mUndockedVolume;
    al::AudioEffectDataBase* mAudioEffectDataBase;
    al::CollisionCodeList* mMaterialCodeList;
    al::CollisionCodeList* mMaterialCodePrefixList;
    bool mIsChangeStereo;
    bool mIsHeadphones;
    al::AudioSystemPauseController* mAudioSystemPauseController;
    al::AudioSystemNin* mAudioSystemNin;
    al::AudioBusSendController* mAudioBusSendController;
    al::AudioFrameProcessMgr* mAudioFrameProcessMgr;
    al::AudioMaximizer* mAudioMaximizer;
    nn::audio::MemoryPoolType* mMemoryPool;
    nn::os::SystemEvent mAudioDeviceSwitchNotification;
    bool mIsMixed;
    float mMonoVolume;
    float mStereoVolume;
    bool mIsStereo;

public:
    AudioSystem();
    void init(const al::AudioSystemInitInfo&);
    void initDataBase();
    void initResourcePlayer(const al::AudioSystemInitInfo&);
    void applyDeviceVolume();
    void updateHWOutputSetting();
    void changeFinalMixInputBgmChVolume();
    void initDebugModule(const al::AudioSystemInitInfo&);
    void initSystemInfo();
    void update();
    void finalize();
    void addAudiioFrameProccess(aal::IAudioFrameProcess*);
    void removeAudiioFrameProccess(aal::IAudioFrameProcess*);
    void pauseSystemImmediately(bool, const char*, bool);

    al::AudioSystemInfo* getAudioSystemInfo() const { return mAudioSystemInfo; }
};
}  // namespace al