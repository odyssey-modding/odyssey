#pragma once

#include <al/Library/LiveActor/ActorInitFunction.h>
#include <al/Library/Nerve/NerveExecutor.h>

namespace al {
class SwingMovement : public NerveExecutor {
private:
    s32 field_10 = 0;
    s32 mDelayRate = 0;
    f32 mSwingAngle = 45.0;
    s32 mSwingCycle = 240;
    s32 mStopTime = 6;
    f32 mOffsetRotate = 0.0;
    f32 field_28 = 0.0;

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