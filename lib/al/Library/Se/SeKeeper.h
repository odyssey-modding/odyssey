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
    static void create(const al::AudioSystemInfo*, al::SeDirector*, const char*, const sead::Vector3f*, const sead::Matrix34f*,
                       const al::ModelKeeper*, al::CameraDirector*);
    SeKeeper(const al::AudioSystemInfo*, al::SeDirector*, const char*, const sead::Vector3f*, const sead::Matrix34f*, const al::ModelKeeper*,
             al::CameraDirector*);

    void tryLoadAddonSoundArchive(al::SeadAudioPlayer*);
    void requestPlaySe(const char*, float, const char*, const al::SePlayParamList*, const al::MeInfo*, bool, const char*, const sead::Vector3f*);
    void tryRequestPlaySe(const char*, float, const char*, const al::SePlayParamList*, const al::MeInfo*, bool, const char*, const sead::Vector3f*);
    void requestPlaySeIdLocal(al::SeRequestParam*, const char*);
    void requestPlayLoopSeSequence(const char*, const al::MeInfo*, int);
    void stopSe(const char*, int, bool, const char*);
    void tryFindPlayInfo(const char*) const;
    void setLifeTimeForHoldCall(const char*, unsigned int, const char*);
    void stopAll(int, const char*);
    void separatePlayingSePosFromEmitter();
    void tryGetCurrentStreamSamplePos(const char*, const char*) const;
    void isPlaying(const char*);
    void checkIsPlayingSe(const char*, const char*);
    void validate();
    void invalidate();
    void startClipped();
    void endClipped();
    void appear();
    void kill();
    void resetPosition();
    void setIsInWater(bool);
    void getWaterState();
    void setIsMaterialWet(bool);
    void setIsMaterialPuddle(bool);
    void tryUpdateMaterial(const char*);
    void setSeSourceVolume(float);
    void setSyncParamPtr(const float*, const char*);
    void setSyncParamPtrInt(const int*, const char*);
    void setEmitterPoseMtxPtr(const sead::Matrix34f*, const char*);
    void setEmitterPosePosPtr(const sead::Vector3f*, const char*);
    void loadSe(al::IAudioResourceLoader*);
};
}  // namespace al
