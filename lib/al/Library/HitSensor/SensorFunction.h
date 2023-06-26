#pragma once

#include <al/Library/LiveActor/LiveActor.h>

namespace alSensorFunction {
    void updateHitSensorsAll(al::LiveActor *);
    void clearHitSensors(al::LiveActor *);
    // TODO: find this type
    void findSensorTypeByName(char const*);
}