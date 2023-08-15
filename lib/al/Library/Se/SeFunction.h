#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>

namespace al {
class ISeModifier;
class IUseAudioKeeper;
class MeInfo;
class SePlayParamList;

void startSe(const al::IUseAudioKeeper*, sead::SafeString const&);
void verifySeKeeperNull(const al::IUseAudioKeeper*, sead::SafeString const&);
bool tryStartSe(const al::IUseAudioKeeper*, sead::SafeString const&);
void holdSe(const al::IUseAudioKeeper*, sead::SafeString const&);
bool tryHoldSe(const al::IUseAudioKeeper*, sead::SafeString const&);
void startSeWithParam(const al::IUseAudioKeeper*, sead::SafeString const&, f32, const char*);
bool tryStartSeWithParam(const al::IUseAudioKeeper*, sead::SafeString const&, f32, const char*);
void holdSeWithParam(const al::IUseAudioKeeper*, sead::SafeString const&, f32, const char*);
bool tryHoldSeWithParam(const al::IUseAudioKeeper*, sead::SafeString const&, f32, const char*);
void startSeWithMeInfo(const al::IUseAudioKeeper*, sead::SafeString const&, al::MeInfo const*);
void holdSeWithMeInfo(const al::IUseAudioKeeper*, sead::SafeString const&, al::MeInfo const*);
void startSeWithManualControl(const al::IUseAudioKeeper*, sead::SafeString const&, const al::SePlayParamList*, const char*, const sead::Vector3f*);
bool tryStartSeWithManualControl(const al::IUseAudioKeeper*, sead::SafeString const&, const al::SePlayParamList*, const char*, const sead::Vector3f*);
void holdSeWithManualControl(const al::IUseAudioKeeper*, sead::SafeString const&, const al::SePlayParamList*, const char*, const sead::Vector3f*);
bool tryHoldSeWithManualControl(const al::IUseAudioKeeper*, sead::SafeString const&, const al::SePlayParamList*, const char*, const sead::Vector3f*);
void stopSe(const al::IUseAudioKeeper*, sead::SafeString const&, s32, const char*);
void stopSeWithoutFreezed(const al::IUseAudioKeeper*, sead::SafeString const&, s32, const char*);
bool tryStopSe(const al::IUseAudioKeeper*, sead::SafeString const&, s32, const char*);
bool tryStopAllSeFromUser(const al::IUseAudioKeeper*, s32, const char*);
void stopAllSeFromUser(const al::IUseAudioKeeper*, s32, const char*);
bool isPlayingAnySe(const al::IUseAudioKeeper*, const char*);
void checkIsPlayingSe(const al::IUseAudioKeeper*, sead::SafeString const&, const char*);
void setLifeTimeForHoldCall(const al::IUseAudioKeeper*, const char*, s32, const char*);
void setSeSourceVolume(const al::IUseAudioKeeper*, f32);
void setSeKeeperPlayNamePrefix(const al::IUseAudioKeeper*, const char*);
void resetSeKeeperPlayNamePrefix(const al::IUseAudioKeeper*);
bool isExistSeKeeper(const al::IUseAudioKeeper*);
void forceActivateSeKeeper(al::IUseAudioKeeper*);
void validateSeKeeper(al::IUseAudioKeeper*);
void invalidateSeKeeper(al::IUseAudioKeeper*);
void setSeEmitterPoseMtxPtr(const al::IUseAudioKeeper*, const sead::Matrix34f*, const char*);
void setSeEmitterPosePosPtr(const al::IUseAudioKeeper*, const sead::Vector3f*, const char*);
bool tryUpdateSeMaterialCode(al::IUseAudioKeeper*, const char*);
void updateSeMaterialWater(al::IUseAudioKeeper*, bool);
void updateSeMaterialWet(al::IUseAudioKeeper*, bool);
void updateSeMaterialBeyondWall(al::IUseAudioKeeper*, bool);
void updateSeMaterialPuddle(al::IUseAudioKeeper*, bool);
void resetSeMaterialName(const al::IUseAudioKeeper*);
void setSeModifier(const al::IUseAudioKeeper*, al::ISeModifier*);
void setSeUserSyncParamPtr(const al::IUseAudioKeeper*, f32 const*, const char*);
void setSeUserSyncParamPtrInt(const al::IUseAudioKeeper*, s32 const*, const char*);
void setSeOutputFromController(al::SePlayParamList*, s32, bool);
void setSeOutputTvDrcRemoteAll(al::SePlayParamList*);
}  // namespace al