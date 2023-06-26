#pragma once

#include "gfx/seadColor.h"
#include "math/seadMatrix.h"
#include "math/seadVector.h"
namespace al {
    class IUseEffectKeeper;

    void emitEffectCurrentPos(al::IUseEffectKeeper *,char const*);
    void emitEffect(al::IUseEffectKeeper *,char const*,sead::Vector3<float> const*);
    bool tryEmitEffect(al::IUseEffectKeeper *,char const*,sead::Vector3<float> const*);
    void deleteEffect(al::IUseEffectKeeper *,char const*);
    bool tryDeleteEffect(al::IUseEffectKeeper *,char const*);
    void deleteEffectAll(al::IUseEffectKeeper *);
    void tryKillEmitterAndParticleAll(al::IUseEffectKeeper *);
    void onCalcAndDrawEffect(al::IUseEffectKeeper *);
    void offCalcAndDrawEffect(al::IUseEffectKeeper *);
    void forceSetStopCalcAndDraw(al::IUseEffectKeeper *,bool);
    bool isEffectEmitting(al::IUseEffectKeeper const*,char const*);
    void setEffectEmitRatio(al::IUseEffectKeeper *,char const*,float);
    void setEffectAllScale(al::IUseEffectKeeper *,char const*,sead::Vector3<float> const&);
    void setEffectEmitterVolumeScale(al::IUseEffectKeeper *,char const*,sead::Vector3<float> const&);
    void setEffectParticleScale(al::IUseEffectKeeper *,char const*,float);
    void setEffectParticleScale(al::IUseEffectKeeper *,char const*,sead::Vector3<float> const&);
    void setEffectParticleAlpha(al::IUseEffectKeeper *,char const*,float);
    void setEffectParticleColor(al::IUseEffectKeeper *,char const*,sead::Color4f const&);
    void setParticleLifeScale(al::IUseEffectKeeper *,char const*,float);
    void setEffectParticleDirectionalVel(al::IUseEffectKeeper *,char const*,float);
    void setEffectFollowPosPtr(al::IUseEffectKeeper *,char const*,sead::Vector3<float> const*);
    void setEffectFollowMtxPtr(al::IUseEffectKeeper *,char const*,sead::Matrix34<float> const*);
    void setEffectNamedMtxPtr(al::IUseEffectKeeper *,char const*,sead::Matrix34<float> const*);
    bool trySetEffectNamedMtxPtr(al::IUseEffectKeeper *,char const*,sead::Matrix34<float> const*);
    bool tryUpdateEffectMaterialCode(al::IUseEffectKeeper *,char const*);
    void resetEffectMaterialCode(al::IUseEffectKeeper *);
    void updateEffectMaterialWater(al::IUseEffectKeeper *,bool);
    void updateEffectMaterialWet(al::IUseEffectKeeper *,bool);
    void updateEffectMaterialPuddle(al::IUseEffectKeeper *,bool);
}