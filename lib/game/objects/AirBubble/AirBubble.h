#pragma once

#include "al/LiveActor/LiveActor.h"

class AirBubble : public al::LiveActor {
    AirBubble(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startClipped() override;
    void endClipped() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* source,
                            al::HitSensor* target) override;

};