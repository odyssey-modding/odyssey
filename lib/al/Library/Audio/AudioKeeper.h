#pragma once

#include <al/Library/HostIO/HioNode.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class AudioDirector;
class ModelKeeper;
class CameraDirector;
class AudioEventController;
class AudioEffectController;
class AudioRequestKeeperSyncedBgm;
class AudioMic;
class SeKeeper;
class BgmKeeper;

class AudioKeeper : public al::IUseHioNode {
    AudioEventController* mAudioEventController;
    AudioEffectController* mAudioEffectController;
    AudioRequestKeeperSyncedBgm* mAudioRequestKeeperSyncedBgm;
    SeKeeper* mSeKeeper;
    BgmKeeper* mBgmKeeper;
    AudioMic* mAudioMic;

public:
    AudioKeeper(const al::AudioDirector*);
    ~AudioKeeper();

    void initSeKeeper(const al::AudioDirector*, const char*, const sead::Vector3f*, const sead::Matrix34f*, const al::ModelKeeper*,
                      al::CameraDirector*);
    void initBgmKeeper(const al::AudioDirector*, const char*);
    void validate();
    void invalidate();
    void startClipped();
    void endClipped();
    void appear();
    void kill();

    al::AudioEventController* getAudioEventController() const { return mAudioEventController; };
    al::AudioEffectController* getAudioEffectController() const { return mAudioEffectController; };
    al::AudioRequestKeeperSyncedBgm* getAudioRequestKeeperSyncedBgm() const { return mAudioRequestKeeperSyncedBgm; };
    al::SeKeeper* getSeKeeper() const { return mSeKeeper; };
    al::BgmKeeper* getBgmKeeper() const { return mBgmKeeper; };
    al::AudioMic* getAudioMic() const { return mAudioMic; };
};

class IUseAudioKeeper {
public:
    virtual al::AudioKeeper* getAudioKeeper() const = 0;
};
}  // namespace al
