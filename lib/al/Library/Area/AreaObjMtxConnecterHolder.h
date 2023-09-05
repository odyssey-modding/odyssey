#pragma once

#include <math/seadMatrix.h>
#include "al/Library/Area/AreaObjMtxConnecter.h"
#include "al/Library/Placement/PlacementInfo.h"

namespace al {

class AreaObjMtxConnecterHolder {
private:
    al::MtxConnector** mMtxConnectors;
    s32 mNumConnectors = 0;
    s32 mCapacity;
public:
    AreaObjMtxConnecterHolder(s32);
    void registerParentMtx(const sead::Matrix34f* parentMtx, const al::PlacementInfo& placementInfo, const al::ValidatorBase* validatorBase);
    void registerSyncParentMtx(const sead::Matrix34f* parentMtx, const al::PlacementInfo& placementInfo, const al::ValidatorBase* validatorBase);
    s32 tryAddArea(al::AreaObj* areaObj, const al::PlacementInfo& placementInfo);
    void update();
};

}