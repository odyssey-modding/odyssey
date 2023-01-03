#pragma once

#include <container/seadPtrArray.h>
#include <math/seadVector.h>

namespace al {

class Resource;
class ByamlIter;
class GraphicsSystemInfo;
class LiveActor;
class DepthShadowMapInfo;
class ModelDrawerDepthShadowMap;
class ModelDrawerMask;

class DepthShadowMapCtrl {
private:
    al::LiveActor* mLiveActor;
    sead::Vector3<f32> lightDir;
    bool mIsAppendSubActor;
    sead::PtrArray<DepthShadowMapInfo> mDepthShadowMaps;
    sead::PtrArray<ModelDrawerDepthShadowMap> mModelDrawerDepthShadowMaps;
    sead::PtrArray<ModelDrawerMask> mModelDrawerMasks;

public:
    DepthShadowMapCtrl(const al::Resource* resource);
    ~DepthShadowMapCtrl();

    void actorModelDrawDepth();
    void actorModelDrawMask();
    void appendDepthShadowMapInfo(char const*, s32, s32, s32, f32, bool, sead::Vector3f const&, bool, sead::Vector3f const&, sead::Vector3f const&,
                                  bool, char const*, s32, bool, f32, f32, f32, bool, bool, f32, s32, bool, bool, f32);
    DepthShadowMapInfo* getDepthShadowMapInfo(s32 index );
    u32 getDepthShadowMapNum();
    void hide();
    void init(al::LiveActor* actor, const al::ByamlIter& iter);
    void initAfterPlacement(al::GraphicsSystemInfo* graphicsSystemInfo);
    void initWithoutIter(al::LiveActor* actor, s32);
    void show();
    DepthShadowMapInfo* tryFindDepthShadowMapInfo(const char*);
    void update();
    void updateShapeVisible(const al::LiveActor* actor);
};

}  // namespace al
