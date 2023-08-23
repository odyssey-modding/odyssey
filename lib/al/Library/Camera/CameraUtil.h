#pragma once

#include <math/seadVectorFwd.h>

namespace al {
    class IUseCamera;

    void calcCameraFront(sead::Vector3f* out, const al::IUseCamera* cameraUser, int);
} // namespace al