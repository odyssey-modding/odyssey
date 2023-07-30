#pragma once

#include <al/Library/HostIO/HioNode.h>
#include <al/Library/Placement/PlacementInfo.h>
#include <al/Library/Rail/RailRider.h>

namespace al {
class RailKeeper : public al::IUseHioNode, public al::IUseRail {
private:
    al::RailRider* mRailRider;

public:
    RailKeeper(const al::PlacementInfo&);
    al::RailRider* getRailRider() const override;
};
};  // namespace al
