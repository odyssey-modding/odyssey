#pragma once

#include <al/Library/Placement/PlacementId.h>
#include <container/seadBuffer.h>

namespace al {
class PlacementInfo;

class ViewIdHolder {
private:
    s32 mNumPlacements = 0;
    al::PlacementId* mPlacementIds = nullptr;

public:
    ViewIdHolder();
    void init(const al::PlacementInfo& placementInfo);

    static ViewIdHolder* tryCreate(const al::PlacementInfo& placementInfo);
};
}  // namespace al
