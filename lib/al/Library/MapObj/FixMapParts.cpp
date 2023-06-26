#include <al/Library/Demo/DemoFunction.h>
#include <al/Library/HitSensor/Messages.h>
#include <al/Library/LiveActor/ActorActionFunction.h>
#include <al/Library/LiveActor/ActorInitFunction.h>
#include <al/Library/LiveActor/ActorModelFunction.h>
#include <al/Library/MapObj/FixMapParts.h>
#include <al/Library/Placement/PlacementFunction.h>
#include <al/Library/Stage/StageSwitchUtil.h>

namespace al {
FixMapParts::FixMapParts(const char* name) : LiveActor(name) {}
void FixMapParts::init(const ActorInitInfo& info) {
    const char* suffix = nullptr;
    al::tryGetStringArg(&suffix, info, "Suffix");
    al::initMapPartsActor(this, info, suffix);
    al::trySyncStageSwitchAppearAndKill(this);
    al::registActorToDemoInfo(this, info);

    if (getModelKeeper() != nullptr && !al::isExistAction(this) && !al::isViewDependentModel(this)) {
        mStatic = true;
    }
}
void FixMapParts::appear() {
    LiveActor::appear();

    if (al::isExistModel(this))
        al::tryStartAction(this, "Appear");
}
void FixMapParts::movement() {
    if (!mStatic)
        LiveActor::movement();
}
void FixMapParts::calcAnim() {
    if (!mStatic)
        LiveActor::calcAnim();
    else
        al::calcViewModel(this);
}
bool FixMapParts::receiveMsg(const SensorMsg* message, HitSensor* source, HitSensor* target) {
    if (al::isMsgAskSafetyPoint(message))
        return !al::isValidSwitchAppear(this) && !al::isValidSwitchKill(this);

    if (al::isMsgShowModel(message)) {
        al::showModelIfHide(this);
        return true;
    }

    if (al::isMsgHideModel(message)) {
        al::hideModelIfShow(this);
        return true;
    }

    return false;
}
}  // namespace al
