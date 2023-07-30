#include <al/Library/Rail/Rail.h>
#include <al/Library/Rail/RailRider.h>
namespace al {
RailRider::RailRider(const al::Rail* rail) : mRail(rail), mCoord(rail->normalizeLength(0)) {
    rail->calcPosDir(&mPosition, &mDirection, mCoord);
}
}  // namespace al
