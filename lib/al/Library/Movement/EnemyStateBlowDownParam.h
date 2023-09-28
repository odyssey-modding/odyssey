#pragma once

#include <basis/seadTypes.h>

namespace al {
struct EnemyStateBlowDownParam {
    const char* mActionName = "BlowDown";
    f32 mGravityStrength = 10.3f;
    f32 mVelocityStrength = 28.2f;
    f32 mVelocityMultiplier = 1.1f;
    f32 mVelocityScale = 0.995f;
    s32 mBlowDownLength = 120;
    bool mFaceAwayFromActor = true;

    EnemyStateBlowDownParam();
    EnemyStateBlowDownParam(const char* actionName);
    EnemyStateBlowDownParam(const char* actionName, float gravityStrength, float velocityStrength, float velocityMultiplier, float velocityScale,
                            int blowDownLength, bool faceAwayFromActor);
};
}  // namespace al