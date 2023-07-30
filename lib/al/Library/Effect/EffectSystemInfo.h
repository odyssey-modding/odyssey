#pragma once

#include "gfx/seadColor.h"
#include "math/seadMatrix.h"
#include "math/seadVector.h"
namespace al {
class IUseEffectKeeper;

void emitEffectCurrentPos(al::IUseEffectKeeper*, const char*);
void emitEffect(al::IUseEffectKeeper*, const char*, const sead::Vector3f*);
bool tryEmitEffect(al::IUseEffectKeeper*, const char*, const sead::Vector3f*);
void deleteEffect(al::IUseEffectKeeper*, const char*);
bool tryDeleteEffect(al::IUseEffectKeeper*, const char*);
void deleteEffectAll(al::IUseEffectKeeper*);
void tryKillEmitterAndParticleAll(al::IUseEffectKeeper*);
void onCalcAndDrawEffect(al::IUseEffectKeeper*);
void offCalcAndDrawEffect(al::IUseEffectKeeper*);
void forceSetStopCalcAndDraw(al::IUseEffectKeeper*, bool);
bool isEffectEmitting(const al::IUseEffectKeeper*, const char*);
void setEffectEmitRatio(al::IUseEffectKeeper*, const char*, float);
void setEffectAllScale(al::IUseEffectKeeper*, const char*, const sead::Vector3f&);
void setEffectEmitterVolumeScale(al::IUseEffectKeeper*, const char*, const sead::Vector3f&);
void setEffectParticleScale(al::IUseEffectKeeper*, const char*, float);
void setEffectParticleScale(al::IUseEffectKeeper*, const char*, const sead::Vector3f&);
void setEffectParticleAlpha(al::IUseEffectKeeper*, const char*, float);
void setEffectParticleColor(al::IUseEffectKeeper*, const char*, const sead::Color4f&);
void setParticleLifeScale(al::IUseEffectKeeper*, const char*, float);
void setEffectParticleDirectionalVel(al::IUseEffectKeeper*, const char*, float);
void setEffectFollowPosPtr(al::IUseEffectKeeper*, const char*, const sead::Vector3f*);
void setEffectFollowMtxPtr(al::IUseEffectKeeper*, const char*, const sead::Matrix34f*);
void setEffectNamedMtxPtr(al::IUseEffectKeeper*, const char*, const sead::Matrix34f*);
bool trySetEffectNamedMtxPtr(al::IUseEffectKeeper*, const char*, const sead::Matrix34f*);
bool tryUpdateEffectMaterialCode(al::IUseEffectKeeper*, const char*);
void resetEffectMaterialCode(al::IUseEffectKeeper*);
void updateEffectMaterialWater(al::IUseEffectKeeper*, bool);
void updateEffectMaterialWet(al::IUseEffectKeeper*, bool);
void updateEffectMaterialPuddle(al::IUseEffectKeeper*, bool);
}  // namespace al
