#include "Player/PlayerActionGroundMoveControl.h"
#include <math/seadVector.h>

namespace rs {
void calcGroundNormalExceptJustLandOrGravityDir(sead::Vector3f*, const al::LiveActor*, const IUsePlayerCollision*);
void calcGroundNormalOrGravityDir(sead::Vector3f*, const al::LiveActor*, const IUsePlayerCollision*);
}  // namespace rs

PlayerActionGroundMoveControl::PlayerActionGroundMoveControl(al::LiveActor* parent, const PlayerConst* playerConst, const PlayerInput* input,
                                                             const IUsePlayerCollision* collision)
    : mParent(parent), mPlayerConst(playerConst), mPlayerInput(input), mCollision(collision) {}