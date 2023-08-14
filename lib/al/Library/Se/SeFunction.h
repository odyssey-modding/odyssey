#pragma once

#include <al/Library/Audio/AudioKeeper.h>
#include <al/Library/Se/SeKeeper.h>
#include <prim/seadSafeString.h>
namespace al {
    class ISeModifier;


    void startSe(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&);
    void verifySeKeeperNull(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&);
    bool tryStartSe(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&);
    void holdSe(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&);
    bool tryHoldSe(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&);
    void startSeWithParam(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,f32,char const*);
    bool tryStartSeWithParam(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,f32,char const*);
    void holdSeWithParam(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,f32,char const*);
    bool tryHoldSeWithParam(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,f32,char const*);
    void startSeWithMeInfo(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,al::MeInfo const*);
    void holdSeWithMeInfo(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,al::MeInfo const*);
    void startSeWithManualControl(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,al::SePlayParamList const*,char const*,sead::Vector3f const*);
    bool tryStartSeWithManualControl(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,al::SePlayParamList const*,char const*,sead::Vector3f const*);
    void holdSeWithManualControl(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,al::SePlayParamList const*,char const*,sead::Vector3f const*);
    bool tryHoldSeWithManualControl(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,al::SePlayParamList const*,char const*,sead::Vector3f const*);
    void stopSe(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,s32,char const*);
    void stopSeWithoutFreezed(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,s32,char const*);
    bool tryStopSe(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,s32,char const*);
    bool tryStopAllSeFromUser(al::IUseAudioKeeper const*,s32,char const*);
    void stopAllSeFromUser(al::IUseAudioKeeper const*,s32,char const*);
    bool isPlayingAnySe(al::IUseAudioKeeper const*,char const*);
    void checkIsPlayingSe(al::IUseAudioKeeper const*,sead::SafeStringBase<char> const&,char const*);
    void setLifeTimeForHoldCall(al::IUseAudioKeeper const*,char const*,s32,char const*);
    void setSeSourceVolume(al::IUseAudioKeeper const*,f32);
    void setSeKeeperPlayNamePrefix(al::IUseAudioKeeper const*,char const*);
    void resetSeKeeperPlayNamePrefix(al::IUseAudioKeeper const*);
    bool isExistSeKeeper(al::IUseAudioKeeper const*);
    void forceActivateSeKeeper(al::IUseAudioKeeper *);
    void validateSeKeeper(al::IUseAudioKeeper *);
    void invalidateSeKeeper(al::IUseAudioKeeper *);
    void setSeEmitterPoseMtxPtr(al::IUseAudioKeeper const*,sead::Matrix34f const*,char const*);
    void setSeEmitterPosePosPtr(al::IUseAudioKeeper const*,sead::Vector3f const*,char const*);
    bool tryUpdateSeMaterialCode(al::IUseAudioKeeper *,char const*);
    void updateSeMaterialWater(al::IUseAudioKeeper *,bool);
    void updateSeMaterialWet(al::IUseAudioKeeper *,bool);
    void updateSeMaterialBeyondWall(al::IUseAudioKeeper *,bool);
    void updateSeMaterialPuddle(al::IUseAudioKeeper *,bool);
    void resetSeMaterialName(al::IUseAudioKeeper const*);
    void setSeModifier(al::IUseAudioKeeper const*,al::ISeModifier *);
    void setSeUserSyncParamPtr(al::IUseAudioKeeper const*,f32 const*,char const*);
    void setSeUserSyncParamPtrInt(al::IUseAudioKeeper const*,s32 const*,char const*);
    void setSeOutputFromController(al::SePlayParamList *,s32,bool);
    void setSeOutputTvDrcRemoteAll(al::SePlayParamList *);
}