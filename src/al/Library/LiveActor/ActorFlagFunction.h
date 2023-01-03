#pragma once

namespace al {
class LiveActor;

bool isAlive(const al::LiveActor* actor);
bool isDead(const al::LiveActor* actor);
bool isNoCollide(const al::LiveActor* actor);
void onCalcAnim(al::LiveActor* actor);
void offCalcAnim(al::LiveActor* actor);
void validateShadow(al::LiveActor* actor);
void invalidateShadow(al::LiveActor* actor);
void onCollide(al::LiveActor* actor);
void offCollide(al::LiveActor* actor);
void validateMaterialCode(al::LiveActor* actor);
void invalidateMaterialCode(al::LiveActor* actor);
void validatePuddleMaterial(al::LiveActor* actor);
void invalidatePuddleMaterial(al::LiveActor* actor);
bool isAreaTarget(const al::LiveActor* actor);
void onAreaTarget(al::LiveActor* actor);
void offAreaTarget(al::LiveActor* actor);
void isUpdateMovementEffectAudioCollisionSensor(const al::LiveActor* actor);
void onUpdateMovementEffectAudioCollisionSensor(al::LiveActor* actor);
void offUpdateMovementEffectAudioCollisionSensor(al::LiveActor* actor);
}
