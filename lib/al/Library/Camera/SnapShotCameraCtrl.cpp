#include "SnapShotCameraCtrl.h"
#include "al/Library/Yaml/ByamlUtil.h"

namespace al {
#ifdef NON_MATCHING
void SnapShotCameraCtrl::load(al::ByamlIter const& iter) {
    al::ByamlIter param;
    if (!al::tryGetByamlIterByKey(&param, iter, "SnapShotParam"))
        return;
    if (al::tryGetByamlF32(&mParam->mMinFovyDegree, param, "MinFovyDegree"))
        mParam->gotMin = true;
    if (al::tryGetByamlF32(&mParam->mMinFovyDegree, param, "MinFovyDegree"))
        mParam->gotMax = true;
}
#endif
}  // namespace al