#pragma once

#include <al/Library/LiveActor/LiveActor.h>

namespace al {
class FixMapParts : public al::LiveActor {
private:
    bool mStatic = false;

public:
    FixMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void movement() override;
    void calcAnim() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* source, al::HitSensor* target) override;
};
}  // namespace al
