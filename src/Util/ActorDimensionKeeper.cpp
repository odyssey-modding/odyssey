#include "ActorDimensionKeeper.h"
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

void ActorDimensionKeeper::update() {
    sead::PtrArray<al::LiveActor*> actors;
    actors.setBuffer(8, nullptr);

    if (mIsValid) {
        auto actorPos = al::getTrans(mLiveActor);
    }
}

namespace rs {
ActorDimensionKeeper* createDimensionKeeper(al::LiveActor const* actor) {
    return new ActorDimensionKeeper(actor);
}

// Why did they feel the need to create these?
void updateDimensionKeeper(ActorDimensionKeeper* keeper) {
    keeper->update();
}

const char* getSpecialPurposeName2DOnly() {
    return "2DOnly";
}

bool is2D(IUseDimension const* iuse) {
    return iuse->getActorDimensionKeeper()->getIs2D();
}

bool isIn2DArea(IUseDimension const* iuse) {
    return iuse->getActorDimensionKeeper()->getIsIn2DArea();
}

bool is3D(IUseDimension const* iuse) {
    auto keeper = iuse->getActorDimensionKeeper();
    return !keeper->getIs2D() && !keeper->getIsCurrently2D();
}

bool isChange2D(IUseDimension const* iuse) {
    return iuse->getActorDimensionKeeper()->getIsCanChange2D();
}

bool isChange3D(IUseDimension const* iuse) {
    return iuse->getActorDimensionKeeper()->getIsCanChange3D();
}

}  // namespace rs