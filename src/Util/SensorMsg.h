#pragma once

namespace al {
class SensorMsg;
class HitSensor;
}  // namespace al

// TODO: Please define all sensor functions using macros. Until then, only declare what you need to use here.
namespace rs {
bool isMsgCapAttack(const al::SensorMsg*);
bool isMsgStartHack(const al::SensorMsg*);
void requestHitReactionToAttacker(const al::SensorMsg*, const al::HitSensor*, const al::HitSensor*);
}  // namespace rs