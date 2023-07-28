#include <Player/PlayerActionGroundMoveControl.h>
#include <math/seadVector.h>

namespace rs {
    void calcGroundNormalExceptJustLandOrGravityDir(sead::Vector3f*, const al::LiveActor*, const IUsePlayerCollision*);
    void calcGroundNormalOrGravityDir(sead::Vector3f*, const al::LiveActor*, const IUsePlayerCollision*);
}


PlayerActionGroundMoveControl::PlayerActionGroundMoveControl(al::LiveActor* parent, const PlayerConst* playerConst, const PlayerInput* input,
                                                             const IUsePlayerCollision* collision) : mParent(parent),
                                                             mPlayerConst(playerConst), mPlayerInput(input),
                                                             mCollision(collision) {

}

// unfinished
//void PlayerActionGroundMoveControl::appear() {
//    auto normal = sead::Vector3f::zero;
//    rs::calcGroundNormalExceptJustLandOrGravityDir(&normal, mParent, mCollision);
//    rs::calcGroundNormalOrGravityDir(&mGroundNormal, mParent, mCollision);
//}