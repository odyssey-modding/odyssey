#include <al/Library/Clipping/ViewIdHolder.h>
#include <al/Library/Placement/PlacementFunction.h>

namespace al {
ViewIdHolder::ViewIdHolder() {}
ViewIdHolder* ViewIdHolder::tryCreate(const al::PlacementInfo& placementInfo) {
    if (al::calcLinkChildNum(placementInfo, "ViewGroup") < 1) {
        return nullptr;
    } else {
        ViewIdHolder* holder = new ViewIdHolder();
        holder->init(placementInfo);
        return holder;
    }
}
void ViewIdHolder::init(const al::PlacementInfo& placementInfo) {
    mPlacementIds = new al::PlacementId[al::calcLinkChildNum(placementInfo, "ViewGroup")];
}
}  // namespace al
