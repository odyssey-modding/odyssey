#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <al/Library/HostIO/IUseHioNode.h>

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
private:
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
};
}  // namespace al
