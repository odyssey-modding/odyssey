#pragma once

#include <gfx/seadColor.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class Effect;
class EffectUserInfo;
class MtxPtrHolder;
class EffectSystemInfo;
class EffectPrefixType;
class EffectKeeper {
private:
    const char* mName;
    u32 mEffectCount;
    al::Effect** mEffects;
    const char* mMaterialName;
    bool mHasEmittedEffect;
    bool field_21;
    bool field_22;
    al::EffectUserInfo* mEffectUserInfo;
    al::MtxPtrHolder* mMtxPtrHolder;

public:
    EffectKeeper(al::EffectSystemInfo* systemInfo, const char*, const sead::Vector3f*, const sead::Vector3f*, const sead::Matrix34f);
    void update();
    void tryUpdateMaterial(const char*);
    void updatePrefix(const al::EffectPrefixType&, bool);
    void emitEffectCurrentPos(const char*);
    void findEffect(const char*);
    void emitEffect(const char*, const sead::Vector3f*);
    void tryEmitEffect(const char*, const sead::Vector3f*);
    void deleteEffect(const char*);
    void tryDeleteEffect(const char*);
    void tryKillEmitterAndParticleAll();
    void deleteEffectAll();
    void deleteAndClearEffectAll();
    void onCalcAndDraw();
    void offCalcAndDraw();
    void forceSetStopCalcAndDraw(bool);
    void setEmitRatio(const char*, float);
    void setEmitterAllScale(const char*, const sead::Vector3f&);
    void setEmitterVolumeScale(const char*, const sead::Vector3f&);
    void setParticleScale(const char*, float);
    void setParticleScale(const char*, const sead::Vector3f&);
    void setParticleAlpha(const char*, float);
    void setParticleColor(const char*, const sead::Color4f&);
    void setParticleLifeScale(const char*, float);
    void findMtxPtr(const char*);
    void tryFindEffect(const char*);
};

class IUseEffectKeeper {
public:
    virtual EffectKeeper* getEffectKeeper() const = 0;
};
}  // namespace al
