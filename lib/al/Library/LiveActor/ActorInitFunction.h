#pragma once

#include <al/Library/LiveActor/ActorSceneInfo.h>
#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/Nerve/NerveUtil.h>
#include <al/Library/Resource/Resource.h>
#include <al/Library/Yaml/ByamlIter.h>
#include <basis/seadTypes.h>
#include <gfx/seadColor.h>
#include <gfx/seadDrawContext.h>
#include <math/seadBoundBox.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>

namespace al {

class ShadowMaskBase;

void initShadowMaskCtrl(al::LiveActor*, const al::ActorInitInfo&, const al::ByamlIter&, const char*);
void initShadowMaskCtrlWithoutInitFile(al::LiveActor*, const al::ActorInitInfo&, s32);
al::ShadowMaskBase* createShadowMaskSphere(al::LiveActor*, const char*, const char*, const char*);
al::ShadowMaskBase* createShadowMaskCube(al::LiveActor*, const char*, const char*, const char*, const sead::Color4f&, const sead::Vector3f&, f32, f32,
                                         f32, const sead::Vector3f&, f32);
al::ShadowMaskBase* createShadowMaskCylinder(al::LiveActor*, const char*, const char*, const char*, const sead::Color4f&, const sead::Vector3f&, f32,
                                             f32, f32, f32, f32);
al::ShadowMaskBase* createShadowMaskCastOvalCylinder(al::LiveActor*, const char*, const char*, const char*, const sead::Color4f&,
                                                     const sead::Vector3f&, const sead::Vector3f&, f32, f32, f32, f32);
void initActorCollision(al::LiveActor*, const sead::SafeString&, al::HitSensor*, const sead::Matrix34f*);
void initActorCollisionWithResource(al::LiveActor*, const al::Resource*, const sead::SafeString&, al::HitSensor*, const sead::Matrix34f*,
                                    const char*);
void initActorCollisionWithArchiveName(al::LiveActor*, const sead::SafeString&, const sead::SafeString&, al::HitSensor*, const sead::Matrix34f*);
void initActorCollisionWithFilePtr(al::LiveActor*, void*, const void*, al::HitSensor*, const sead::Matrix34f*, const char*, const char*, s32);
void initStageSwitch(al::LiveActor*, const al::ActorInitInfo&);
void initActorItemKeeper(al::LiveActor*, const al::ActorInitInfo&, const al::ByamlIter&);
void initActorPrePassLightKeeper(al::LiveActor*, const al::Resource*, const al::ActorInitInfo&, const char*);
void initActorOcclusionKeeper(al::LiveActor*, const al::Resource*, const al::ActorInitInfo&, const char*);
void initSubActorKeeper(al::LiveActor*, const al::ActorInitInfo&, const char*, s32);
void initSubActorKeeperNoFile(al::LiveActor*, const al::ActorInitInfo&, s32);
void registerSubActor(al::LiveActor*, al::LiveActor*);
void registerSubActorSyncClipping(al::LiveActor*, al::LiveActor*);
void registerSubActorSyncClippingAndHide(al::LiveActor*, al::LiveActor*);
void registerSubActorSyncAll(al::LiveActor*, al::LiveActor*);
void setSubActorOffSyncClipping(al::LiveActor*);
void initScreenPointKeeper(al::LiveActor*, const al::Resource*, const al::ActorInitInfo&, const char*);
void initScreenPointKeeperNoYaml(al::LiveActor*, s32);
void initActorMaterialCategory(al::LiveActor*, const al::ActorInitInfo&, const char*);

class LiveActor;
class LiveActorGroup;
class PlacementInfo;
class LayoutInitInfo;
class AreaObjDirector;
class CameraDirector;
class ClippingDirector;
class CollisionDirector;
class DemoDirector;
class GameDataHolderBase;
class GravityHolder;
class ItemDirectorBase;
class NatureDirector;
class GamePadSystem;
class PadRumbleDirector;
class PlayerHolder;
class SceneObjHolder;
class SceneStopCtrl;
class SceneMsgCtrl;
class ScreenCoverCtrl;
class ShadowDirector;
class ModelGroup;
class GraphicsSystemInfo;
class ModelDrawBufferCounter;
class ActorFactory;
class ActorResourceHolder;
class AudioDirector;
class EffectSystemInfo;
class ExecuteDirector;
class HitSensorDirector;
class StageSwitchDirector;
class ScreenPointDirector;
class ViewIdHolder;
class SceneCameraInfo;
class Nerve;
class PlacementInfo;
class LayoutInitInfo;
class AudioDirector;
class CollisionDirector;
class GraphicsSystemInfo;

class ActorInitInfo {
private:
    al::LiveActorGroup* mKitDrawingGroup;
    const al::PlacementInfo* mPlacementInfo;
    const al::LayoutInitInfo* mLayoutInitInfo;
    al::ActorSceneInfo mActorSceneInfo;
    al::LiveActorGroup* mAllActorsGroup;
    const al::ActorFactory* mActorFactory;
    al::ActorResourceHolder* mActorResourceHolder;
    al::AudioDirector* mAudioDirector;
    al::EffectSystemInfo* mEffectSystemInfo;
    al::ExecuteDirector* mExecuteDirector;
    al::HitSensorDirector* mHitSensorDirector;
    al::ScreenPointDirector* mScreenPointDirector;
    al::StageSwitchDirector* mStageSwitchDirector;
    al::ViewIdHolder* mViewIdHolder;

public:
    ActorInitInfo();
    void initNew(const PlacementInfo*, const LayoutInitInfo*, LiveActorGroup*, const ActorFactory*, ActorResourceHolder*, AreaObjDirector*,
                 AudioDirector*, CameraDirector*, ClippingDirector*, CollisionDirector*, DemoDirector*, EffectSystemInfo*, ExecuteDirector*,
                 GameDataHolderBase*, GravityHolder*, HitSensorDirector*, ItemDirectorBase*, NatureDirector*, const GamePadSystem*,
                 PadRumbleDirector*, PlayerHolder*, SceneObjHolder*, SceneMsgCtrl*, SceneStopCtrl*, ScreenCoverCtrl*, ScreenPointDirector*,
                 ShadowDirector*, StageSwitchDirector*, ModelGroup*, GraphicsSystemInfo*, ModelDrawBufferCounter*, LiveActorGroup*);
    void initViewIdSelf(const PlacementInfo*, const ActorInitInfo&);
    void copyHostInfo(const ActorInitInfo&, const PlacementInfo*);
    void initViewIdHost(const PlacementInfo*, const ActorInitInfo&);
    void initViewIdHostActor(const ActorInitInfo&, const LiveActor*);
    void initNoViewId(const PlacementInfo*, const ActorInitInfo&);

    const al::PlacementInfo& getPlacementInfo() const { return *mPlacementInfo; };
    al::StageSwitchDirector* getStageSwitchDirector() const { return mStageSwitchDirector; };
    al::SceneObjHolder* getActorSceneObjHolder() const { return mActorSceneInfo.mSceneObjHolder; };
};

void initActor(al::LiveActor* actor, const al::ActorInitInfo& initInfo);
void initActorSuffix(al::LiveActor* actor, const al::ActorInitInfo& initInfo, const char* suffix);
void initActorChangeModel(al::LiveActor* actor, const al::ActorInitInfo& initInfo);
void initActorChangeModelSuffix(al::LiveActor* actor, const al::ActorInitInfo& initInfo, const char* suffix);
void initActorWithArchiveName(al::LiveActor* actor, const al::ActorInitInfo& initInfo, const sead::SafeString& archiveName, const char* suffix);
void initChildActorWithArchiveNameWithPlacementInfo(al::LiveActor* actor, const al::ActorInitInfo& initInfo, const sead::SafeString& archiveName,
                                                    const char* suffix);
void initChildActorWithArchiveNameNoPlacementInfo(al::LiveActor* actor, const al::ActorInitInfo& initInfo, const sead::SafeString& archiveName,
                                                  const char* suffix);
void initMapPartsActor(al::LiveActor* actor, const al::ActorInitInfo& initInfo, const char* suffix);
void initLinksActor(al::LiveActor* actor, const al::ActorInitInfo& initInfo, const char* suffix, s32 linkIndex);

void createChildLinkSimpleActor(const char* actorName, const char* archiveName, const al::ActorInitInfo& initInfo, bool alive);
void createChildLinkMapPartsActor(const char* actorName, const char* archiveName, const al::ActorInitInfo& initInfo, s32 linkIndex, bool alive);

al::ActorInitInfo* createLinksPlayerActorInfo(al::LiveActor* actor, const al::ActorInitInfo& initInfo);

void initNerve(al::LiveActor* actor, const al::Nerve* nerve, s32 maxStates);
void initNerveAction(al::LiveActor* actor, const char* actionName, alNerveFunction::NerveActionCollector* collector, s32 maxStates);

bool trySyncStageSwitchAppear(al::LiveActor* actor);
bool trySyncStageSwitchKill(al::LiveActor* actor);
bool trySyncStageSwitchAppearAndKill(al::LiveActor* actor);
bool tryListenStageSwitchAppear(al::LiveActor* actor);
bool tryListenStageSwitchKill(al::LiveActor* actor);

void syncSensorScaleY(al::LiveActor* actor);
void syncSensorAndColliderScaleY(al::LiveActor* actor);

void setMaterialCode(al::LiveActor* actor, const char*);
void initMaterialCode(al::LiveActor* actor, const al::ActorInitInfo& initInfo);

bool tryAddDisplayRotate(al::LiveActor* actor, const al::ActorInitInfo& initInfo);
bool tryAddDisplayOffset(al::LiveActor* actor, const al::ActorInitInfo& initInfo);
bool tryAddDisplayScale(al::LiveActor* actor, const al::ActorInitInfo& initInfo);

al::PlacementInfo* getPlacementInfo(const al::ActorInitInfo& initInfo);
const al::LayoutInitInfo* getLayoutInitInfo(const al::ActorInitInfo& initInfo);
al::AudioDirector* getAudioDirector(const al::ActorInitInfo& initInfo);
al::CollisionDirector* getCollisionDirectorFromInfo(const al::ActorInitInfo& initInfo);
const al::SceneCameraInfo* getSceneCameraInfoFromInfo(const al::ActorInitInfo& initInfo);
al::GraphicsSystemInfo* getGraphicsSystemInfo(const al::ActorInitInfo& initInfo);
sead::DrawContext* getDrawContext(const al::ActorInitInfo& initInfo);

void getActorRecourseDataF32(f32*, al::LiveActor*, const char*, const char*);
void getActorRecourseDataString(const char**, al::LiveActor*, const char*, const char*);
void getActorRecourseDataV3f(sead::Vector3f*, al::LiveActor* actor, const char*, const char*);
void getActorRecourseDataBox3f(sead::BoundBox3f* box, al::LiveActor* actor, const char*, const char*);

void createPartsEffectGroup(al::LiveActor* actor, const al::ActorInitInfo& initInfo, s32);
}  // namespace al
