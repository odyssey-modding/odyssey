#include <al/Library/Audio/AudioKeeper.h>
#include <al/Library/Collision/Collider.h>
#include <al/Library/HitSensor/SensorFunction.h>
#include <al/Library/LiveActor/ActorCollisionFunction.h>
#include <al/Library/LiveActor/ActorMovementFunction.h>
#include <al/Library/LiveActor/ActorPoseKeeper.h>
#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/Screen/ScreenPointKeeper.h>
#include <al/Library/Se/SeKeeper.h>
#include <al/Library/Math/MathLerpUtil.h>
#include <al/Library/Math/MathVectorUtil.h>

namespace al {
void resetPosition(al::LiveActor* actor) {
    if (actor->getPoseKeeper())
        actor->calcAnim();
    if (actor->getHitSensorKeeper()) {
        alSensorFunction::clearHitSensors(actor);
        alSensorFunction::updateHitSensorsAll(actor);
    }
    if (actor->getScreenPointKeeper()) {
        alScreenPointFunction::updateScreenPointAll(actor);
    }
    if (actor->getCollider())
        actor->getCollider()->onInvalidate();
    if (actor->getCollisionParts())
        al::resetAllCollisionMtx(actor);
    if (!actor->getAudioKeeper())
        return;
    if (!actor->getAudioKeeper()->getSeKeeper())
        return;
    actor->getAudioKeeper()->getSeKeeper()->resetPosition();
}

void resetPosition(al::LiveActor* actor, const sead::Vector3f& trans) {
    al::updatePoseTrans(actor, trans);
    al::resetPosition(actor);
}

void resetRotatePosition(al::LiveActor* actor, const sead::Vector3f& rot, const sead::Vector3f& trans) {
    al::updatePoseRotate(actor, rot);
    al::updatePoseTrans(actor, trans);
    al::resetPosition(actor);
}

void resetQuatPosition(al::LiveActor* actor, const sead::Quatf& quat, const sead::Vector3f& trans) {
    al::updatePoseQuat(actor, quat);
    al::updatePoseTrans(actor, trans);
    al::resetPosition(actor);
}

void resetMtxPosition(al::LiveActor* actor, const sead::Matrix34f& mtx) {
    al::updatePoseMtx(actor, &mtx);
    al::resetPosition(actor);
}

void resetActorPosition(al::LiveActor* actor, const al::LiveActor* target) {
    al::updatePoseMtx(actor, target->getBaseMtx());
    al::resetPosition(actor);
}

// trySetPosOnGround

const sead::Vector3f& getVelocity(const al::LiveActor* actor) {
    return actor->getPoseKeeper()->getVelocity();
}

sead::Vector3f* getVelocityPtr(al::LiveActor* actor) {
    return actor->getPoseKeeper()->getVelocityPtr();
}

void separateVelocityHV(sead::Vector3f* horizontal, sead::Vector3f* vertical, const al::LiveActor* actor) {
    al::separateVectorHV(horizontal, vertical, al::getGravity(actor), actor->getPoseKeeper()->getVelocity());
}

void separateVelocityDirHV(sead::Vector3f* horizontal, sead::Vector3f* vertical, const al::LiveActor* actor, const sead::Vector3f& direction) {
    al::separateVectorHV(horizontal, vertical, direction, actor->getPoseKeeper()->getVelocity());
}

void separateVelocityParallelVertical(sead::Vector3f* horizontal, sead::Vector3f* vertical, const al::LiveActor* actor,
                                      const sead::Vector3f& direction) {
    al::separateVectorParallelVertical(horizontal, vertical, direction, actor->getPoseKeeper()->getVelocity());
}

void setVelocity(al::LiveActor* actor, const sead::Vector3f& vel) {
    sead::Vector3f* velocityPtr = actor->getPoseKeeper()->getVelocityPtr();
    velocityPtr->e = vel.e;
}

void setVelocity(al::LiveActor* actor, f32 x, f32 y, f32 z) {
    sead::Vector3f* velocityPtr = actor->getPoseKeeper()->getVelocityPtr();
    velocityPtr->x = x;
    velocityPtr->y = y;
    velocityPtr->z = z;
}

void setVelocityX(al::LiveActor* actor, f32 x) {
    sead::Vector3f* velocityPtr = actor->getPoseKeeper()->getVelocityPtr();
    velocityPtr->x = x;
}

void setVelocityY(al::LiveActor* actor, f32 y) {
    sead::Vector3f* velocityPtr = actor->getPoseKeeper()->getVelocityPtr();
    velocityPtr->y = y;
}

void setVelocityZ(al::LiveActor* actor, f32 z) {
    sead::Vector3f* velocityPtr = actor->getPoseKeeper()->getVelocityPtr();
    velocityPtr->z = z;
}

void setVelocityZero(al::LiveActor* actor) {
    sead::Vector3f* velocityPtr = actor->getPoseKeeper()->getVelocityPtr();
    velocityPtr->x = 0;
    velocityPtr->y = 0;
    velocityPtr->z = 0;
}

void setVelocityZeroX(al::LiveActor* actor) {
    sead::Vector3f* velocityPtr = actor->getPoseKeeper()->getVelocityPtr();
    velocityPtr->x = 0;
}

void setVelocityZeroY(al::LiveActor* actor) {
    sead::Vector3f* velocityPtr = actor->getPoseKeeper()->getVelocityPtr();
    velocityPtr->y = 0;
}

void setVelocityZeroZ(al::LiveActor* actor) {
    sead::Vector3f* velocityPtr = actor->getPoseKeeper()->getVelocityPtr();
    velocityPtr->z = 0;
}

void addVelocity(al::LiveActor* actor, const sead::Vector3f& vel) {
    sead::Vector3f& currentVelocity = *actor->getMutPoseKeeper()->getVelocityPtr();
    currentVelocity += vel;
}

void addVelocity(al::LiveActor* actor, f32 x, f32 y, f32 z) {
    sead::Vector3f& currentVelocity = *actor->getMutPoseKeeper()->getVelocityPtr();
    currentVelocity.x += x;
    currentVelocity.y += y;
    currentVelocity.z += z;
}

void addVelocityX(al::LiveActor* actor, f32 x) {
    sead::Vector3f& currentVelocity = *actor->getMutPoseKeeper()->getVelocityPtr();
    currentVelocity.x += x;
}

void addVelocityY(al::LiveActor* actor, f32 y) {
    sead::Vector3f& currentVelocity = *actor->getMutPoseKeeper()->getVelocityPtr();
    currentVelocity.y += y;
}

void addVelocityZ(al::LiveActor* actor, f32 z) {
    sead::Vector3f& currentVelocity = *actor->getMutPoseKeeper()->getVelocityPtr();
    currentVelocity.z += z;
}

}  // namespace al
