#pragma once

#include <al/Library/Nerve/NerveStateBase.h>

class IUsePlayerCollision;
class PlayerInput;
class PlayerConst;
class PlayerAnimator;
class PlayerActionGroundMoveControl;

class PlayerStateGroundSpin : public al::ActorStateBase {
    const IUsePlayerCollision* mCollision;
    const PlayerInput* mPlayerInput;
    const PlayerConst* mPlayerConst;
    PlayerAnimator* mPlayerAnimator;
    PlayerActionGroundMoveControl* mGroundMoveCtrl = nullptr;
    bool mIsSpinClockwise = false;

public:
    PlayerStateGroundSpin(al::LiveActor* parent, const IUsePlayerCollision* collision,
                          const PlayerInput* input, const PlayerConst* playerConst, PlayerAnimator* animator);
    ~PlayerStateGroundSpin() override = default;

    void appear() override;
    void exeGroundSpin();
};

