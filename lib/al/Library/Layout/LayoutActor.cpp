#include <al/Library/Audio/AudioKeeper.h>
#include <al/Library/Layout/LayoutActor.h>
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
al::NerveKeeper* LayoutActor::getNerveKeeper() const {
    return mNerveKeeper;
}
const char* LayoutActor::getName() const {
    return mName.cstr();
}
al::EffectKeeper* LayoutActor::getEffectKeeper() const {
    return mEffectKeeper;
}
al::AudioKeeper* LayoutActor::getAudioKeeper() const {
    return mAudioKeeper;
}
al::LayoutActionKeeper* LayoutActor::getLayoutActionKeeper() const {
    return mLayoutActionKeeper;
}
al::LayoutKeeper* LayoutActor::getLayoutKeeper() const {
    return mLayoutKeeper;
}
al::CameraDirector* LayoutActor::getCameraDirector() const {
    return mLayoutSceneInfo->getCameraDirector();
}
al::SceneObjHolder* LayoutActor::getSceneObjHolder() const {
    return mLayoutSceneInfo->getSceneObjHolder();
}
const al::MessageSystem* LayoutActor::getMessageSystem() const {
    return mLayoutSceneInfo->getMessageSystem();
}
}  // namespace al
