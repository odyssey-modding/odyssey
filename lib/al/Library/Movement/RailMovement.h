#pragma once

#include <al/Library/LiveActor/ActorInitFunction.h>
#include <al/Library/Nerve/NerveExecutor.h>

namespace al {
class SwingMovement : public NerveExecutor {
private:
    s32 field_10;
    s32 mDelayRate;
    f32 mSwingAngle;
    s32 mSwingCycle;
    s32 mStopTime;
    f32 mOffsetRotate;
    f32 field_28;

public:
    SwingMovement();
    SwingMovement(const al::ActorInitInfo&);
    ~SwingMovement() = default;

    bool updateRotate();

    void exeMove();
    void exeStop();

    bool isLeft() const;
    bool isStop() const;
};
}  // namespace al