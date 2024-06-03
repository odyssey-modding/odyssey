#pragma once

#include <math/seadMatrix.h>
#include "al/Library/Placement/PlacementInfo.h"

namespace al {
class AreaObj;
class MtxConnector;
class PlacementInfo;
class ValidatorBase;

class AreaObjMtxConnecter {
private:
    AreaObj* mAreaObj;
    sead::Matrix34f mMatrix;
    MtxConnector* mMtxConnector = nullptr;
    PlacementInfo mPlacementInfo;
    ValidatorBase* mValidatorBase = nullptr;

public:
    AreaObjMtxConnecter(al::AreaObj* areaObj, const al::PlacementInfo& placementInfo);
    bool trySetParentMtx(const sead::Matrix34f* parentMtx, const al::PlacementInfo& placementInfo, const al::ValidatorBase* validatorBase);
    bool trySyncParentMtx(const sead::Matrix34f* parentMtx, const al::PlacementInfo& placementInfo, const al::ValidatorBase* validatorBase);
    void update();
};

class AreaObjMtxConnecterHolder {
private:
    al::MtxConnector** mMtxConnectors;
    s32 mNumConnectors = 0;
    s32 mCapacity;

public:
    AreaObjMtxConnecterHolder(s32 capacity);
    void registerParentMtx(const sead::Matrix34f* parentMtx, const al::PlacementInfo& placementInfo, const al::ValidatorBase* validatorBase);
    void registerSyncParentMtx(const sead::Matrix34f* parentMtx, const al::PlacementInfo& placementInfo, const al::ValidatorBase* validatorBase);
    s32 tryAddArea(al::AreaObj* areaObj, const al::PlacementInfo& placementInfo);
    void update();
};

}  // namespace al