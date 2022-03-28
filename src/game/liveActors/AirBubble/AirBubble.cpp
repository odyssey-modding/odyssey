#include "game/objects/AirBubble/AirBubble.h"

AirBubble::AirBubble(const char* name) : al::LiveActor(name) {}
void AirBubble::init(const al::ActorInitInfo& info) {
    LiveActor::init(info);
}
void AirBubble::startClipped() {
    LiveActor::startClipped();
}
void AirBubble::endClipped() {
    LiveActor::endClipped();
}
bool AirBubble::receiveMsg(const al::SensorMsg* message, al::HitSensor* source,
                           al::HitSensor* target) {
    return LiveActor::receiveMsg(message, source, target);
}
