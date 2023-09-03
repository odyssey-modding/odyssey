#include <al/Library/Math/MathSpeedUtil.h>
#include <al/Library/Movement/RailMovement.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Placement/PlacementFunction.h>

namespace {
using namespace al;

NERVE_IMPL(SwingMovement, Move);
NERVE_IMPL(SwingMovement, Stop);

struct {
    NERVE_MAKE(SwingMovement, Move);
    NERVE_MAKE(SwingMovement, Stop);
} NrvSwingMovement;

}  // namespace

namespace al {

SwingMovement::SwingMovement()
    : al::NerveExecutor("スイング動作計算"), field_10(10), mDelayRate(0), mSwingAngle(45.0), mSwingCycle(240.0), mStopTime(6), mOffsetRotate(0.0),
      field_28(0.0) {}

SwingMovement::SwingMovement(const al::ActorInitInfo& initInfo) : al::NerveExecutor("スイング動作計算") {
    al::tryGetArg(&mSwingAngle, initInfo, "SwingAngle");
    al::tryGetArg(&mSwingCycle, initInfo, "SwingCycle");
    al::tryGetArg(&mDelayRate, initInfo, "DelayRate");
    al::tryGetArg(&mStopTime, initInfo, "StopTime");
    al::tryGetArg(&mOffsetRotate, initInfo, "OffsetRotate");

    field_10 = mSwingCycle * ((mDelayRate + -25.0) / 100.0);

    updateRotate();
    initNerve(&NrvSwingMovement.Move, 0);
}

void SwingMovement::exeMove() {
    if (updateRotate())
        al::setNerve(this, &NrvSwingMovement.Stop);

    field_10 = al::modi(field_10 + mSwingCycle + 1, mSwingCycle);
}

void SwingMovement::exeStop() {
    if (al::isGreaterEqualStep(this, mStopTime))
        al::setNerve(this, &NrvSwingMovement.Move);
}

bool SwingMovement::isLeft() const {
    f32 angle = (field_10 * 360) / mSwingCycle;
    return angle >= 90.0 && angle < 270.0;
}

bool SwingMovement::isStop() const {
    return al::isNerve(this, &NrvSwingMovement.Stop);
}

}  // namespace al