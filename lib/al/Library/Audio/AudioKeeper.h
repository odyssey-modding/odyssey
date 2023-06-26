#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <al/Library/IUse/IUseHioNode.h>

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
    void *field_0;
    AudioEventController* mAudioEventController;
    AudioEffectController* mAudioEffectController;
    AudioRequestKeeperSyncedBgm* mAudioRequestKeeperSyncedBgm;
    SeKeeper* mSeKeeper;
    BgmKeeper* mBgmKeeper;
    AudioMic* mAudioMic;

public:
    AudioKeeper(al::AudioDirector const*);
    ~AudioKeeper();

    void initSeKeeper(al::AudioDirector const*, char const*, sead::Vector3f const*,
                      sead::Matrix34f const*, al::ModelKeeper const*, al::CameraDirector*);
    void initBgmKeeper(al::AudioDirector const*, char const*);
    void validate(void);
    void invalidate(void);
    void startClipped(void);
    void endClipped(void);
    void appear(void);
    void kill(void);

    AudioEventController* getAudioEventController() const { return mAudioEventController; };
    AudioEffectController* getAudioEffectController() const { return mAudioEffectController; };
    AudioRequestKeeperSyncedBgm* getAudioRequestKeeperSyncedBgm() const { return mAudioRequestKeeperSyncedBgm; };
    SeKeeper* getSeKeeper() const { return mSeKeeper; };
    BgmKeeper* getBgmKeeper() const { return mBgmKeeper; };
    AudioMic* getAudioMic() const { return mAudioMic; };
};
}  // namespace al
