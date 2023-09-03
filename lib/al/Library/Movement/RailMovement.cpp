#include <al/Library/Math/MathSpeedUtil.h>
#include <al/Library/Movement/RailMovement.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Placement/PlacementFunction.h>

namespace {
using namespace al;

NERVE_IMPL(SwingMovement, Move);
NERVE_IMPL(SwingMovement, Stop);

struct {
    NERVE_MAKE(SwingMovement, Stop);
    NERVE_MAKE(SwingMovement, Move);
} NrvSwingMovement;

}  // namespace

namespace al {

SwingMovement::SwingMovement()
    : al::NerveExecutor("スイング動作計算"), mSwingAngle(45.0), mSwingCycle(240), mStopTime(6), field_10(0), mDelayRate(0), mOffsetRotate(0.0),
      field_28(0.0) {
    initNerve(&NrvSwingMovement.Stop, 0);
}

SwingMovement::SwingMovement(const al::ActorInitInfo& initInfo)
    : al::NerveExecutor("スイング動作計算"), mSwingAngle(45.0), mSwingCycle(240), mStopTime(6), field_10(0), mDelayRate(0), mOffsetRotate(0.0),
      field_28(0.0) {
    tryGetArg(&mSwingAngle, initInfo, "SwingAngle");
    tryGetArg(&mSwingCycle, initInfo, "SwingCycle");
    tryGetArg(&mDelayRate, initInfo, "DelayRate");
    tryGetArg(&mStopTime, initInfo, "StopTime");
    tryGetArg(&mOffsetRotate, initInfo, "OffsetRotate");

    field_10 = (mDelayRate - 25.0f) / 100.0f * mSwingCycle;

    updateRotate();
    initNerve(&NrvSwingMovement.Stop, 0);
}

void SwingMovement::exeMove() {
    if (updateRotate())
        setNerve(this, &NrvSwingMovement.Stop);

    field_10 = modi(field_10 + mSwingCycle + 1, mSwingCycle);
}

void SwingMovement::exeStop() {
    if (isGreaterEqualStep(this, mStopTime))
        setNerve(this, &NrvSwingMovement.Stop);
}

bool SwingMovement::isLeft() const {
    f32 angle = (field_10 * 360.0f) / mSwingCycle;
    return angle >= 90 && angle < 270;
}

bool SwingMovement::isStop() const {
    return isNerve(this, &NrvSwingMovement.Stop);
}

}  // namespace al