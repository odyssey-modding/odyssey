#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include "al/Library/Factory/Factory.h"
#include "al/Library/HostIO/HioNode.h"
#include "al/Library/Scene/SceneObjHolder.h"
#include "al/Library/Stage/StageSwitchKeeper.h"

namespace al {
class AreaInitInfo;
class AreaObjGroup;
class AreaShape;
class PlacementInfo;
class SceneObjHolder;
class StageSwitchKeeper;

class AreaObj : public al::IUseStageSwitch, public al::IUseSceneObjHolder, public al::HioNode {
private:
    const char* mName;
    AreaShape* mAreaShape = nullptr;
    al::StageSwitchKeeper* mStageSwitchKeeper = nullptr;
    al::SceneObjHolder* mSceneObjHolder = nullptr;
    sead::Matrix34f mMatrixTR = sead::Matrix34f::ident;
    al::PlacementInfo* mPlacementInfo = nullptr;
    s32 mPriority = -1;
    bool isValid = true;

public:
    AreaObj(const char* name);
    const char* getName() const override;
    al::StageSwitchKeeper* getStageSwitchKeeper() const override;
    void initStageSwitchKeeper() override;
    virtual void init(const al::AreaInitInfo& initInfo);
    virtual bool isInVolume(const sead::Vector3f& position) const;
    virtual bool isInVolumeOffset(const sead::Vector3f&, f32 offset) const;
    al::SceneObjHolder* getSceneObjHolder() const override;
    void validate();
    void invalidate();

    s32 getPriority() { return mPriority; };
};

class AreaObjFactory : public al::Factory<al::AreaObj* (*)()> {
private:
    s32 mUnknown; // might be empty space
    AreaObjGroup** mAreaGroups = nullptr;
    s32 mNumBuffers = 0;
public:
    AreaObjFactory(const char* factoryName);
    s32 tryFindAddBufferSize(const char* bufferName) const;
};

}  // namespace al