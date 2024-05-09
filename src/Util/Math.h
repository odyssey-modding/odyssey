#pragma once

#include <al/Library/LiveActor/LiveActor.h>
#include <math/seadVector.h>

namespace rs {
    void slerpUpFront(al::LiveActor*, const sead::Vector3f&, const sead::Vector3f&, float, float);
} // namespace rs