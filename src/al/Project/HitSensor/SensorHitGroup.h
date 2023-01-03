#pragma once

#include <basis/seadTypes.h>

namespace al {
class HitSensor;
class SensorHitGroup {
private:
    s32 mMaxSensors;
    s32 mSensorCount = 0;
    HitSensor** mSensors;
public:
    SensorHitGroup(s32 maxSensors, const char* groupName);
};
}  // namespace al
