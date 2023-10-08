#pragma once

#include <basis/seadTypes.h>

namespace al {
enum class CameraPriority {
    Entrance = 2,
    BossField = 3,
    Capture = 4,
    Object = 5,
    Area = 6,
    Entrance2 = 7,
    SafetyPointRecovery = 8,
    Player = 9,
    DemoTalk = 10,
    Demo = 11,
    Demo2 = 12
};

struct CameraStartInfo {
    s32 mPrePriority;
    char unk[20];
    f32 mPreCameraMaxSwingAngleH;
    f32 mPreCameraMaxSwingAngleV;
    bool mIsInvalidCollidePreCamera;
    bool mIsInvalidKeepPreCameraDistance;
    bool mIsInvalidKeepPreCameraDistanceIfNoCollide;
    bool mIsValidResetPreCameraPose;
    bool mIsValidKeepPreSelfCameraPose;
    bool mIsOnGround;
    bool mIsExistAreaAngleH;
    bool field_27;
    f32 mAreaAngleH;
    bool mIsExistAreaAngleV;
    f32 mAreaAngleV;
    bool mIsExistNextPoseByPreCamera;
    f32 mNextAngleHByPreCamera;
    f32 mNextAngleVByPreCamera;
};
}  // namespace al