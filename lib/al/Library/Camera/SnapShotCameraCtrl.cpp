#include "SnapShotCameraCtrl.h"
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Yaml/ByamlUtil.h>

namespace {
using namespace al;
NERVE_IMPL(SnapShotCameraCtrl, Wait);
NERVE_IMPL(SnapShotCameraCtrl, Reset);

struct {
    NERVE_MAKE(SnapShotCameraCtrl, Reset);
    NERVE_MAKE(SnapShotCameraCtrl, Wait);
} NrvSnapShotCameraCtrl;
}  // namespace

namespace al {

// NON_MATCHING: tools/check cannot find this function
SnapShotCameraCtrl::SnapShotCameraCtrl(const al::SnapShotCameraSceneInfo* info) : al::NerveExecutor("スナップショットモード中のカメラ制御") {
    mCameraSceneInfo = info;
    initNerve(&NrvSnapShotCameraCtrl.Reset, 0);

    al::SnapShotParam* param = new al::SnapShotParam();
    mParam = param;
}

void SnapShotCameraCtrl::load(const al::ByamlIter& iter) {
    auto param = mParam;
    al::ByamlIter paramIter;
    if (!al::tryGetByamlIterByKey(&paramIter, iter, "SnapShotParam"))
        return;
    if (al::tryGetByamlF32(&param->mMinFovyDegree, paramIter, "MinFovyDegree"))
        param->gotMin = true;
    if (al::tryGetByamlF32(&param->mMaxFovyDegree, paramIter, "MaxFovyDegree"))
        param->gotMax = true;
}
}  // namespace al
