#include <al/Library/LiveActor/ActorFlagFunction.h>
#include <al/Library/LiveActor/LiveActor.h>

namespace al {
bool isAlive(const al::LiveActor* actor) {
    return !actor->getFlags()->isDead;
}
bool isDead(const al::LiveActor* actor) {
    return actor->getFlags()->isDead;
}
bool isNoCollide(const al::LiveActor* actor) {
    return actor->getFlags()->isCollideOff;
}
void onCalcAnim(al::LiveActor* actor) {
    actor->getFlags()->isCalcAnim = true;
}
void offCalcAnim(al::LiveActor* actor) {
    actor->getFlags()->isCalcAnim = false;
}
void validateShadow(al::LiveActor* actor) {}
void invalidateShadow(al::LiveActor* actor) {}
void onCollide(al::LiveActor* actor) {
    actor->getFlags()->isCollideOff = false;
}
void offCollide(al::LiveActor* actor) {
    actor->getFlags()->isCollideOff = true;
}
void validateMaterialCode(al::LiveActor* actor) {
    actor->getFlags()->isMaterialCodeValid = true;
}
void invalidateMaterialCode(al::LiveActor* actor) {
    actor->getFlags()->isMaterialCodeValid = false;
}
void validatePuddleMaterial(al::LiveActor* actor) {
    actor->getFlags()->isPuddleMaterialValid = true;
}
void invalidatePuddleMaterial(al::LiveActor* actor) {
    actor->getFlags()->isPuddleMaterialValid = false;
}
bool isAreaTarget(const al::LiveActor* actor) {
    return actor->getFlags()->isAreaTargetOn;
}
void onAreaTarget(al::LiveActor* actor) {
    actor->getFlags()->isAreaTargetOn = true;
}
void offAreaTarget(al::LiveActor* actor) {
    actor->getFlags()->isAreaTargetOn = true;
}
bool isUpdateMovementEffectAudioCollisionSensor(const al::LiveActor* actor) {
    return actor->getFlags()->isUpdateOn;
}
void onUpdateMovementEffectAudioCollisionSensor(al::LiveActor* actor) {
    actor->getFlags()->isUpdateOn = true;
}
void offUpdateMovementEffectAudioCollisionSensor(al::LiveActor* actor) {
    actor->getFlags()->isUpdateOn = false;
}
}  // namespace al
