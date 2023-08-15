#include "Util/ActorDimensionKeeper.h"
#include <al/Library/LiveActor/ActorPoseKeeper.h>
#include <container/seadPtrArray.h>

void ActorDimensionKeeper::validate() {
    mIsValid = true;
}

void ActorDimensionKeeper::invalidate() {
    mIsValid = false;
    if (!mIs2D)
        return;
    mIs2D = false;
    mIsIn2DArea = false;
    mIsCurrently2D = false;
    mIsCanChange3D = true;
}

void ActorDimensionKeeper::forceChange2DKeep() {
    mIsCurrently2D = true;
}

void ActorDimensionKeeper::forceEndChange2DKeep() {
    mIsCurrently2D = false;
}

namespace rs {
ActorDimensionKeeper* createDimensionKeeper(const al::LiveActor* actor) {
    return new ActorDimensionKeeper(actor);
}

// Why did they feel the need to create these?
void updateDimensionKeeper(ActorDimensionKeeper* keeper) {
    keeper->update();
}

const char* getSpecialPurposeName2DOnly() {
    return "2DOnly";
}

bool is2D(const IUseDimension* iuse) {
    return iuse->getActorDimensionKeeper()->getIs2D();
}

bool isIn2DArea(const IUseDimension* iuse) {
    return iuse->getActorDimensionKeeper()->getIsIn2DArea();
}

bool is3D(const IUseDimension* iuse) {
    auto keeper = iuse->getActorDimensionKeeper();
    return !keeper->getIs2D() && !keeper->getIsCurrently2D();
}

bool isChange2D(const IUseDimension* iuse) {
    return iuse->getActorDimensionKeeper()->getIsCanChange2D();
}

bool isChange3D(const IUseDimension* iuse) {
    return iuse->getActorDimensionKeeper()->getIsCanChange3D();
}

}  // namespace rs