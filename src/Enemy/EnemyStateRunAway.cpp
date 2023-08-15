#include "EnemyStateRunAway.h"
#include <al/Library/LiveActor/ActorPoseKeeper.h>
#include <al/Library/Math/MathLengthUtil.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Nerve/NerveUtil.h>

namespace {
NERVE_IMPL(EnemyStateRunAway, Run);
NERVE_IMPL(EnemyStateRunAway, PanicRun);
NERVE_IMPL(EnemyStateRunAway, PanicRunCollided);

NERVE_MAKE(EnemyStateRunAway, Run);
NERVE_MAKE(EnemyStateRunAway, PanicRun);
NERVE_MAKE(EnemyStateRunAway, PanicRunCollided);
}  // namespace

// NON_MATCHING: Mismatching Vector math, should be equivalent
void EnemyStateRunAway::appear() {
    mIsDead = false;
    if (mParam->mShouldFaceDir)
        mNeedToFaceToDirection = true;
    al::calcFrontDir(&mFrontDir, mActor);
    if (mScaredOfActor) {
        sead::Vector3f normalized = al::getTrans(mScaredOfActor) - al::getTrans(mActor);
        normalized.y = 0.0f;
        al::normalize(&normalized);
        normalized = -normalized;

        mFrontDir = normalized;
    } else {
        mFrontDir = sead::Vector3f::ez;
    }
    al::setNerve(this, &PanicRun);
}
