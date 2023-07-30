#include <al/Library/Rail/Rail.h>
#include <al/Library/Rail/RailKeeper.h>

namespace al {
RailKeeper::RailKeeper(const al::PlacementInfo& info) {
    auto* rail = new al::Rail();
    rail->init(info);
    mRailRider = new RailRider(rail);
}
al::RailRider* RailKeeper::getRailRider() const {
    return mRailRider;
}
}  // namespace al
