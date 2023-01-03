#pragma once

#include <math/seadBoundBox.h>
#include <math/seadVector.h>

namespace al {
class LiveActor;
class ActorInitInfo;
class ClippingDirector;

void initActorClipping(al::LiveActor* actor, const al::ActorInitInfo& initInfo);
void initGroupClipping(al::LiveActor* actor, const al::ActorInitInfo& initInfo);
f32 getClippingRadius(const al::LiveActor* actor);
void setClippingInfo(al::LiveActor* actor, f32, const sead::Vector3f*);
void setClippingObb(al::LiveActor* actor, const sead::BoundBox3f& boundingBox);
sead::BoundBox3f& getClippingObb(al::LiveActor* actor);
sead::Vector3f& getClippingCenterPos(const al::LiveActor* actor);
void setClippingNearDistance(al::LiveActor* actor, f32 near);
void expandClippingRadiusByShadowLength(al::LiveActor* actor, sead::Vector3f*, f32 radius);
bool tryExpandClippingToGround(al::LiveActor* actor, sead::Vector3f*, f32);
bool tryExpandClippingByShadowMaskLength(al::LiveActor* actor, sead::Vector3f*);
bool tryExpandClippingByDepthShadowLength(al::LiveActor* actor, sead::Vector3f*);
bool tryExpandClippingByExpandObject(al::LiveActor*, const al::ActorInitInfo& initInfo);
bool isClipped(const al::LiveActor*);
bool isInvalidClipping(const al::LiveActor*);
void invalidateClipping(al::LiveActor* actor);
void validateClipping(al::LiveActor* actor);
void onDrawClipping(al::LiveActor* actor);
void offDrawClipping(al::LiveActor* actor);
void onGroupClipping(al::LiveActor* actor);
void offGroupClipping(al::LiveActor* actor);
bool isInClippingFrustum(const al::LiveActor* actor, const sead::Vector3f&, f32, f32, s32);
bool isInClippingFrustum(const al::ClippingDirector* director, const sead::Vector3f&, f32, f32, s32);
bool isInClippingFrustumAllView(const al::LiveActor* actor, const sead::Vector3f& pos, f32, f32);
}  // namespace al
