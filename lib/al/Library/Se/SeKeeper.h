#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class AudioSystemInfo;
class SeDirector;
class MeInfo;
class SeadAudioPlayer;
class SePlayParamList;
class SeRequestParam;
class IAudioResourceLoader;
class ModelKeeper;
class CameraDirector;

class SeKeeper {
    public:
    static void create(al::AudioSystemInfo const*, al::SeDirector*, char const*, sead::Vector3<float> const*, sead::Matrix34<float> const*,
                       al::ModelKeeper const*, al::CameraDirector*);
    SeKeeper(al::AudioSystemInfo const*, al::SeDirector*, char const*, sead::Vector3<float> const*, sead::Matrix34<float> const*,
             al::ModelKeeper const*, al::CameraDirector*);

    void tryLoadAddonSoundArchive(al::SeadAudioPlayer*);
    void requestPlaySe(char const*, float, char const*, al::SePlayParamList const*, al::MeInfo const*, bool, char const*,
                       sead::Vector3<float> const*);
    void tryRequestPlaySe(char const*, float, char const*, al::SePlayParamList const*, al::MeInfo const*, bool, char const*,
                          sead::Vector3<float> const*);
    void requestPlaySeIdLocal(al::SeRequestParam*, char const*);
    void requestPlayLoopSeSequence(char const*, al::MeInfo const*, int);
    void stopSe(char const*, int, bool, char const*);
    void tryFindPlayInfo(char const*) const;
    void setLifeTimeForHoldCall(char const*, unsigned int, char const*);
    void stopAll(int, char const*);
    void separatePlayingSePosFromEmitter(void);
    void tryGetCurrentStreamSamplePos(char const*, char const*) const;
    void isPlaying(char const*);
    void checkIsPlayingSe(char const*, char const*);
    void validate(void);
    void invalidate(void);
    void startClipped(void);
    void endClipped(void);
    void appear(void);
    void kill(void);
    void resetPosition(void);
    void setIsInWater(bool);
    void getWaterState(void);
    void setIsMaterialWet(bool);
    void setIsMaterialPuddle(bool);
    void tryUpdateMaterial(char const*);
    void setSeSourceVolume(float);
    void setSyncParamPtr(float const*, char const*);
    void setSyncParamPtrInt(int const*, char const*);
    void setEmitterPoseMtxPtr(sead::Matrix34<float> const*, char const*);
    void setEmitterPosePosPtr(sead::Vector3<float> const*, char const*);
    void loadSe(al::IAudioResourceLoader*);
};
}  // namespace al