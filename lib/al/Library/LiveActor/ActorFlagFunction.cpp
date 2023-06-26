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
void validateMaterialCode(al::LiveActor* actor) {}
void invalidateMaterialCode(al::LiveActor* actor) {}
void validatePuddleMaterial(al::LiveActor* actor) {}
void invalidatePuddleMaterial(al::LiveActor* actor) {}
bool isAreaTarget(const al::LiveActor* actor) {}
void onAreaTarget(al::LiveActor* actor) {}
void offAreaTarget(al::LiveActor* actor) {}
void isUpdateMovementEffectAudioCollisionSensor(const al::LiveActor* actor) {}
void onUpdateMovementEffectAudioCollisionSensor(al::LiveActor* actor) {}
void offUpdateMovementEffectAudioCollisionSensor(al::LiveActor* actor) {}
}
