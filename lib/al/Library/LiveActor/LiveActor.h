#pragma once

#include <math/seadMatrix.h>
#include "ActorClippingFunction.h"
#include <al/Library/IUse/IUse.h>

namespace al {
class ActorPoseKeeperBase;
class ActorExecuteInfo;
class ActorActionKeeper;
class ActorItemKeeper;
class ActorScoreKeeper;
class Collider;
class CollisionParts;
class ModelKeeper;
class NerveKeeper;
class HitSensorKeeper;
class ScreenPointKeeper;
class EffectKeeper;
class AudioKeeper;
class HitReactionKeeper;
class StageSwitchKeeper;
class RailKeeper;
class ShadowKeeper;
class ActorPrePassLightKeeper;
class ActorOcclusionKeeper;
class SubActorKeeper;
class ActorParamHolder;
struct ActorSceneInfo;
struct LiveActorFlag;
class ActorInitInfo;
class HitSensor;
class SensorMsg;
class ScreenPointer;
class ScreenPointTarget;

class LiveActor : public al::IUseNerve,
                  public al::IUseEffectKeeper,
                  public al::IUseAudioKeeper,
                  public al::IUseStageSwitch,
                  public al::IUseSceneObjHolder,
                  public al::IUseAreaObj,
                  public al::IUseCamera,
                  public al::IUseCollision,
                  public al::IUseRail,
                  public al::IUseHioNode {
    friend class alActorFunction;

private:
    const char* mActorName;
    al::ActorPoseKeeperBase* mPoseKeeper;
    al::ActorExecuteInfo* mLayoutExecuteInfo;
    al::ActorActionKeeper* mActorActionKeeper;
    al::ActorItemKeeper* mActorItemKeeper;
    al::ActorScoreKeeper* mActorScoreKeeper;
    al::Collider* mCollider;
    al::CollisionParts* mCollisionParts;
    al::ModelKeeper* mModelKeeper;
    al::NerveKeeper* mNerveKeeper;
    al::HitSensorKeeper* mHitSensorKeeper;
    al::ScreenPointKeeper* mScreenPointKeeper;
    al::EffectKeeper* mEffectKeeper;
    al::AudioKeeper* mAudioKeeper;
    al::HitReactionKeeper* mHitReactionKeeper;
    al::StageSwitchKeeper* mStageSwitchKeeper;
    al::RailKeeper* mRailKeeper;
    al::ShadowKeeper* mShadowKeeper;
    al::ActorPrePassLightKeeper* mActorPrePassLightKeeper;
    al::ActorOcclusionKeeper* mActorOcclusionKeeper;
    al::SubActorKeeper* mSubActorKeeper;
    al::ActorParamHolder* mActorParamHolder;
    al::ActorSceneInfo* mSceneInfo;
    al::LiveActorFlag* mFlags;

public:
    LiveActor(const char* actorName);

    al::NerveKeeper* getNerveKeeper() const override;
    virtual void init(const al::ActorInitInfo& info);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void makeActorAlive();
    virtual void kill();
    virtual void makeActorDead();
    virtual void movement();
    virtual void calcAnim();
    virtual void draw() const;
    virtual void startClipped();
    virtual void endClipped();
    virtual void attackSensor(al::HitSensor* target, al::HitSensor* source);
    virtual bool receiveMsg(const al::SensorMsg* message, al::HitSensor* source, al::HitSensor* target);
    virtual bool receiveMsgScreenPoint(const al::SensorMsg*, al::ScreenPointer*, al::ScreenPointTarget*);
    virtual const char* getName() const override;
    virtual sead::Matrix34f* getBaseMtx() const;
    virtual al::EffectKeeper* getEffectKeeper() const override;
    virtual al::AudioKeeper* getAudioKeeper() const override;
    virtual al::StageSwitchKeeper* getStageSwitchKeeper() const override;
    virtual al::RailRider* getRailRider() const override;
    virtual al::SceneObjHolder* getSceneObjHolder() const override;
    virtual al::CollisionDirector* getCollisionDirector() const override;
    virtual al::AreaObjDirector* getAreaObjDirector() const override;
    virtual al::CameraDirector* getCameraDirector() const override;
    virtual void initStageSwitchKeeper() override;
    virtual void control();
    virtual void updateCollider();

    al::ActorSceneInfo* getSceneInfo() const;
    void initPoseKeeper(al::ActorPoseKeeperBase*);
    void initExecuteInfo(al::ActorExecuteInfo*);
    void initModelKeeper(al::ModelKeeper*);
    void initActionKeeper(al::ActorActionKeeper*);
    void initNerveKeeper(al::NerveKeeper*);
    void initHitSensor(s32);
    void initScreenPointKeeper(al::ScreenPointKeeper*);
    void initEffectKeeper(al::EffectKeeper*);
    void initAudioKeeper(al::AudioKeeper*);
    void initRailKeeper(const al::ActorInitInfo&, const char*);
    void initCollider(f32, f32, u32);
    void initItemKeeper(s32);
    void initScoreKeeper();
    void initActorPrePassLightKeeper(al::ActorPrePassLightKeeper*);
    void initActorOcclusionKeeper(al::ActorOcclusionKeeper*);
    void initSubActorKeeper(al::SubActorKeeper*);
    void initSceneInfo(al::ActorSceneInfo*);

    al::ActorPoseKeeperBase* getPoseKeeper() const { return mPoseKeeper;};
    al::ActorExecuteInfo* getLayoutExecuteInfo() const { return mLayoutExecuteInfo;};
    al::ActorActionKeeper* getActorActionKeeper() const { return mActorActionKeeper;};
    al::ActorItemKeeper* getActorItemKeeper() const { return mActorItemKeeper;};
    al::ActorScoreKeeper* getActorScoreKeeper() const { return mActorScoreKeeper;};
    al::Collider* getCollider() const { return mCollider;};
    al::CollisionParts* getCollisionParts() const { return mCollisionParts;};
    al::ModelKeeper* getModelKeeper() const { return mModelKeeper;};
    al::HitSensorKeeper* getHitSensorKeeper() const { return mHitSensorKeeper;};
    al::ScreenPointKeeper* getScreenPointKeeper() const { return mScreenPointKeeper;};
    al::HitReactionKeeper* getHitReactionKeeper() const { return mHitReactionKeeper;};
    al::RailKeeper* getRailKeeper() const { return mRailKeeper;};
    al::ShadowKeeper* getShadowKeeper() const { return mShadowKeeper;};
    al::ActorPrePassLightKeeper* getActorPrePassLightKeeper() const { return mActorPrePassLightKeeper;};
    al::ActorOcclusionKeeper* getActorOcclusionKeeper() const { return mActorOcclusionKeeper;};
    al::SubActorKeeper* getSubActorKeeper() const { return mSubActorKeeper;};
    al::ActorParamHolder* getActorParamHolder() const { return mActorParamHolder;};
    al::LiveActorFlag* getFlags() const { return mFlags;};
    
};

struct LiveActorFlag {
    bool isDead = true;
    bool isClipped = false;
    bool isClippingInvalid = true;
    bool isDrawClipped = false;
    bool isCalcAnim = false;
    bool isModelVisible = false;
    bool isCollideOff = true;
    bool field_07 = false;
    bool isMaterialCodeValid = false;
    bool isPuddleMaterialValid = false;
    bool isAreaTargetOn = true;
    bool isUpdateOn = true;

    LiveActorFlag();
};
static_assert(sizeof(LiveActorFlag) == 0xC);

}  // namespace al
