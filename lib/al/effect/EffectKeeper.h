#pragma once

#include "al/effect/EffectPrefixType.h"
#include <math/seadVector.h>
#include <math/seadMatrix.h>
#include <gfx/seadColor.h>

namespace al {
class EffectSystemInfo;
class Effect;
class EffectKeeper {
public:
    EffectKeeper(al::EffectSystemInfo const*, char const*, sead::Vector3f const*,
                 sead::Vector3f const*, sead::Matrix34f const*);
    void update();
    bool tryUpdateMaterial(const char* material);
    void updatePrefix(const al::EffectPrefixType&, bool);
    void emitEffectCurrentPos(const char* effect);
    al::Effect* findEffect(const char* effect);
    void emitEffect(const char* effect, const sead::Vector3f* position);
    bool tryEmitEffect(const char* effect, const sead::Vector3f* position);
    void deleteEffect(const char* effect);
    bool tryDeleteEffect(const char* effect);
    bool tryKillEmitterAndParticleAll();
    void deleteEffectAll();
    void deleteAndClearEffectAll();
    void onCalcAndDraw();
    void offCalcAndDraw();
    void forceSetStopCalcAndDraw();
    void setEmitterRatio(const char*, float);
    void setEmitterAllScale(const char*, const sead::Vector3f&);
    void setEmitterVolumeScale(const char*, const sead::Vector3f&);
    void setParticleScale(const char*, float);
    void setParticleScale(const char*, const sead::Vector3f&);
    void setParticleAlpha(const char*, float);
    void setParticleColor(const char*, const sead::Color4f&);
    void setParticleLifeScale(const char*, float);
    sead::Matrix34f* findMtxPtr(const char*);
    void tryFindEffect(const char*);

private:
    char padding_0[0x38];
};
};  // namespace al