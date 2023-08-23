#pragma once

#include <prim/seadSafeString.h>
#include <math/seadMatrix.h>

namespace al {
    class ActorDitherAnimator;
} // namespace al

class PlayerModelHolder;

class PlayerAnimator {
public:
    PlayerAnimator(const PlayerModelHolder*,al::ActorDitherAnimator *);
    ~PlayerAnimator() = default;
    void startAnim(const sead::SafeString&);
    void updateAnimFrame();
    void updateModel();
    void copyAnim();
    void startAnimCommon(const sead::SafeString&);
    void setAnimRate(f32);
    void startAnimSpinAttack(const sead::SafeString&);
    void setAnimRateCommon(f32);
    void setAnimFrame(f32);
    void setAnimFrameCommon(f32);
    bool isAnimEnd();
    bool isAnim(const sead::SafeString&);
    bool isCurrentAnimOneTime();
    f32 getAnimFrame();
    f32 getAnimFrameMax();
    f32 getAnimFrameRate();
    void clearinterpolation();
    void startSubAnim(const sead::SafeString&);
    void startSubAnimOnlyAir(const sead::SafeString&);
    void endSubAnim();
    void applyBlendWeight();
    void setSubAnimFrame(f32);
    void setSubAnimRate(f32);
    bool isSubAnimEnd();
    bool isSubAnim(const sead::SafeString&);
    f32 getSubAnimFrame();
    f32 getSubAnimFrameMax();
    bool isUpperBodyAnimAttached();
    bool isUpperBodyAnimEnd();
    bool isUpperBodyAnim(const sead::SafeString&);
    void startUpperBodyAnim(const sead::SafeString&);
    void startPartsPartialAnim(const sead::SafeString&);
    void startUpperBodyAnimSubParts(const sead::SafeString&);
    void startUpperBodyAnimAndHeadVisKeep(const sead::SafeString&);
    void clearUpperBodyAnim();
    void setBlendWeight(f32,f32,f32,f32,f32,f32);
    f32 getBlendWeight(s32);
    void startAnimDead();
    void startPress();
    void forceCapOn();
    void forceCapOff();
    f32 getModelAlpha();
    void updateModelAlpha();
    void setModelAlpha(f32);
    void resetModelAlpha();
    void endDemoInvalidateModelAlpha();
    void startSnapShotMode();
    void endSnapShotMode();
    void startEyeControlAnim(bool);
    void endEyeControlAnim(s32);
    void clearEndEyeControlAnimDelay();
    void updateEyeControlAnim();
    void startRightHandAnim(const char*);
    void overwrideYoshiEatVis();
    void restartYoshiActionVis();
    f32 getMario3DWaitFrameMax();
    f32 getRunStartAnimFrameMax();
    f32 getRunStartAnimBlendRate();
    void recordRunStartAnimRate(f32);
    void calcModelJointRootMtx(sead::Matrix34f*);
    void startPartsAnim(const sead::SafeString&);
    void setPartsAnimRate(f32,const char*);
    void setPartsAnimFrame(f32,const char*);
    void copyAnimLocal();
};
