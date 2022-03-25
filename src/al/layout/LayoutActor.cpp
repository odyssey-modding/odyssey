#include "al/layout/LayoutActor.h"
#include "al/util/LayoutActorUtil.h"

namespace al {

void LayoutActor::appear() {
    mIsAlive = true;
    if (mAudioKeeper)
        mAudioKeeper->appear();
    if (mLayoutPartsActorKeeper)
        mLayoutPartsActorKeeper->appear();
    al::updateLayoutPaneRecursive(this);
    this->calcAnim(false);
}

void LayoutActor::initLayoutPartsActorKeeper(int capacity) {
    mLayoutPartsActorKeeper = new LayoutPartsActorKeeper(capacity);
}
void LayoutActor::initLayoutKeeper(al::LayoutKeeper* layoutKeeper) {
    mLayoutKeeper = layoutKeeper;
}
}  // namespace al