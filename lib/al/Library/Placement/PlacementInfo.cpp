#include <al/Library/Placement/PlacementInfo.h>

namespace al {
PlacementInfo::PlacementInfo() = default;

void PlacementInfo::set(const al::ByamlIter& placement_iter, const al::ByamlIter& zone_iter) {
    mPlacementIter = placement_iter;
    mZoneIter = zone_iter;
}
}
