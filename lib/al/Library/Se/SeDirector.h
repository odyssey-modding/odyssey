#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class SePlayerGroupKeeper;
class SeListenerKeeper;
class MeInfoKeeper;
class SeMaterialInfoKeeper;
class SeCategoryHolder;
class SeSituationKeeper;
struct SeStageInfo;
class SeSourceKeeper;
class SeBarrierKeeper;
class SeLoopSequencer;
class SeDuckingController;
class SeDataBase;
class PadRumbleDirector;
class AudioDirector;
struct AudioSystemInfo;
class IUseActiveBgmLine;
class AreaObjDirector;
class PlayerHolder;
struct SeRequestParam;
class SeEmitter;
class AudioBusSendController;
struct MeInfo;
class Projection;

struct SeDirectorInitInfo {
    s32 maxRequests;
    s32 playerCount;
    s32 listenerCount;
    const char* defaultListenerName;
    const char* defaultStageEffectName;
    bool useMeInfo;
    bool useLoopSequencer;
    u32* field_28;
    s32 field_30;  // length of field_28
    sead::Vector3f* cameraPos;
    sead::Matrix34f* cameraMatrix;
    al::Projection* cameraProjection;
    sead::Vector3f* cameraAt;
    void* field_58;
    f32 interiorSize;
    f32 pitchModifier;
};

class SeDirector {
private:
    al::SePlayerGroupKeeper* mSePlayerGroupKeeper;
    al::SeListenerKeeper* mSeListenerKeeper;
    al::MeInfoKeeper* mMeInfoKeeper;
    al::SeMaterialInfoKeeper* mSeMaterialInfoKeeper;
    s32 mListenerCount;
    al::SeCategoryHolder* mSeCategoryHolder;
    al::SeSituationKeeper* mSeSituationKeeper;
    al::SeStageInfo* mSeStageInfo;
    const char* mStageEffectName;
    al::SeSourceKeeper* mSeSourceKeeper;
    al::SeBarrierKeeper* mSeBarrierKeeper;
    al::SeLoopSequencer* mSeLoopSequencer;
    al::SeDuckingController* mSeDuckingController;
    al::SeDataBase* mSeDatabase;
    void* field_70;
    f32 mVolume;
    void* field_80;
    const char** mSystemPauses;
    s32 mSystemPauseCount;
    bool* mUnderThreeChannels;
    bool* mAudioStereoJackOutput;
    char** field_a8;
    s32 field_b0;  // length for field_a8
    al::PadRumbleDirector* mPadRumbleDirector;

public:
    SeDirector();
    void init(const al::AudioDirector*, const al::SeDirectorInitInfo&, const char*, s32, const al::AudioSystemInfo*, al::MeInfoKeeper*,
              const al::IUseActiveBgmLine*);
    void getSeDataBase();
    void init3D(const al::SeDirectorInitInfo&);
    void initAfterInitPlacement(al::AreaObjDirector*);
    void finalize();
    void update();
    void isSystemPaused() const;
    void setPlayerHolder(const al::PlayerHolder*);
    void notifyIsModeHandheld(bool);
    void addRequest(al::SeRequestParam*, const char*, s32, bool);
    void notifiedUpdateMaterial(al::SeEmitter*, const char*, s32);
    void pauseSystem(bool, const char*, u32);
    void startSituation(const char*, s32, s32, s32);
    void endSituation(const char*, s32);
    void checkIsActiveSituation(const char*) const;
    void getDuckingVolume() const;
    void getListener(s32) const;
    void setAudioBusSendController(al::AudioBusSendController*);
    void requestPlayLoopSeSequence(const char*, const al::MeInfo*, s32);
    const char* getStageEffectName() const;
};
}  // namespace al