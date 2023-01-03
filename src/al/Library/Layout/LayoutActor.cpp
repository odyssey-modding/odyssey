#include <al/Library/Layout/LayoutActor.h>
#include <al/Library/Audio/AudioKeeper.h>
#include <al/Library/Layout/LayoutActorUtil.h>
#include <al/Library/Layout/LayoutPartsActorKeeper.h>
#include <al/Library/Layout/LayoutSceneInfo.h>

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
void LayoutActor::initLayoutPartsActorKeeper(s32 capacity) {
    mLayoutPartsActorKeeper = new LayoutPartsActorKeeper(capacity);
}
void LayoutActor::initLayoutKeeper(al::LayoutKeeper* layoutKeeper) {
    mLayoutKeeper = layoutKeeper;
}
al::NerveKeeper* LayoutActor::getNerveKeeper(void) const {
    return mNerveKeeper;
}
const char* LayoutActor::getName(void) const {
    return mName.cstr();
}
al::EffectKeeper* LayoutActor::getEffectKeeper(void) const {
    return mEffectKeeper;
}
al::AudioKeeper* LayoutActor::getAudioKeeper(void) const {
    return mAudioKeeper;
}
al::LayoutActionKeeper* LayoutActor::getLayoutActionKeeper(void) const {
    return mLayoutActionKeeper;
}
al::LayoutKeeper* LayoutActor::getLayoutKeeper(void) const {
    return mLayoutKeeper;
}
al::CameraDirector* LayoutActor::getCameraDirector(void) const {
    return mLayoutSceneInfo->getCameraDirector();
}
al::SceneObjHolder* LayoutActor::getSceneObjHolder(void) const {
    return mLayoutSceneInfo->getSceneObjHolder();
}
const al::MessageSystem* LayoutActor::getMessageSystem(void) const {
    return mLayoutSceneInfo->getMessageSystem();
}
}  // namespace al
