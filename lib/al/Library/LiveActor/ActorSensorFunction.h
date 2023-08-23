#pragma once

#include <al/Library/LiveActor/LiveActor.h>

enum SensorType {
    Eye = 0,
    Player = 1,
    PlayerAttack = 2,
    PlayerFoot = 3,
    PlayerDecoration = 4,
    PlayerEye = 5,
    Npc = 6,
    Ride = 7,
    Enemy = 8,
    EnemyBody = 9,
    EnemyAttack = 10,
    MapObj = 12,
    Bindable = 14,
    Collision = 15,
    PlayerFireBall = 16,
    HoldObj = 17,
    LookAt = 18,
    BindableGoal = 19,
    BindableAllPlayer = 20,
    BindableBubbleOutScreen = 21,
    BindableKoura = 22,
    BindableRouteDokan = 23,
    BindableBubblePadInput = 24
};

namespace alActorSensorFunction {
void getSensorKeeper(const al::LiveActor*);
void sendMsgSensorToSensor(const al::SensorMsg&, al::HitSensor*, al::HitSensor*);
void sendMsgToActorUnusedSensor(const al::SensorMsg&, al::LiveActor*);
}  // namespace alActorSensorFunction

namespace al {
class SensorSortCmpFuncBase;
class ActorSensorController;

void addHitSensorPlayer(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensor(al::LiveActor*, const al::ActorInitInfo&, const char*, unsigned int, float, unsigned short, const sead::Vector3f&);
void addHitSensorPlayerAttack(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorPlayerEye(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorEnemy(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorEnemyBody(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorEnemyAttack(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorMapObj(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorBindable(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorBindableGoal(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorBindableAllPlayer(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorBindableBubbleOutScreen(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorBindableKoura(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorBindableRouteDokan(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorBindableBubblePadInput(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorCollisionParts(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void addHitSensorEye(al::LiveActor*, const al::ActorInitInfo&, const char*, float, unsigned short, const sead::Vector3f&);
void setHitSensorSort(al::LiveActor*, const char*, const al::SensorSortCmpFuncBase*);
void setHitSensorPosPtr(al::LiveActor*, const char*, const sead::Vector3f*);
void getHitSensor(const al::LiveActor*, const char*);
void setHitSensorMtxPtr(al::LiveActor*, const char*, const sead::Matrix34f*);
void setHitSensorJointMtx(al::LiveActor*, const char*, const char*);
void setSensorRadius(al::LiveActor*, const char*, float);
void setSensorRadius(al::LiveActor*, float);
void getSensorRadius(const al::LiveActor*, const char*);
void getSensorRadius(const al::LiveActor*);
void getSensorPos(const al::LiveActor*, const char*);
void getSensorPos(const al::LiveActor*);
void setSensorFollowPosOffset(al::LiveActor*, const char*, const sead::Vector3f&);
void setSensorFollowPosOffset(al::LiveActor*, const sead::Vector3f&);
void getSensorFollowPosOffset(const al::LiveActor*, const char*);
void getSensorFollowPosOffset(const al::LiveActor*);
void createActorSensorController(al::LiveActor*, const char*);
void setSensorRadius(al::ActorSensorController*, float);
void setSensorScale(al::ActorSensorController*, float);
void setSensorFollowPosOffset(al::ActorSensorController*, const sead::Vector3f&);
void getOriginalSensorRadius(const al::ActorSensorController*);
void getOriginalSensorFollowPosOffset(const al::ActorSensorController*);
void resetActorSensorController(al::ActorSensorController*);
void calcPosBetweenSensors(sead::Vector3f*, const al::HitSensor*, const al::HitSensor*, float);
f32 calcDistance(const al::HitSensor*, const al::HitSensor*);
sead::Vector3f& getSensorPos(const al::HitSensor*);
void calcDistanceV(const sead::Vector3f&, const al::HitSensor*, const al::HitSensor*);
void calcDistanceH(const sead::Vector3f&, const al::HitSensor*, const al::HitSensor*);
void calcDirBetweenSensors(sead::Vector3f*, const al::HitSensor*, const al::HitSensor*);
void calcDirBetweenSensorsH(sead::Vector3f*, const al::HitSensor*, const al::HitSensor*);
void calcDirBetweenSensorsNormal(sead::Vector3f*, const al::HitSensor*, const al::HitSensor*, sead::Vector3f);
void calcVecBetweenSensors(sead::Vector3f*, const al::HitSensor*, const al::HitSensor*);
void calcVecBetweenSensorsH(sead::Vector3f*, const al::HitSensor*, const al::HitSensor*);
void calcVecBetweenSensorsNormal(sead::Vector3f*, const al::HitSensor*, const al::HitSensor*, sead::Vector3f);
void calcStrikeArrowCollideWallAndCeilingBetweenAttackSensor(const al::LiveActor*, const al::HitSensor*, const al::HitSensor*, const sead::Vector3f&,
                                                             float);
void getSensorHost(const al::HitSensor*);
bool isFaceBetweenSensors(const sead::Vector3f&, const al::HitSensor*, const al::HitSensor*);
bool isFaceBetweenSensorsH(const sead::Vector3f&, const al::HitSensor*, const al::HitSensor*);
bool isEnableLookAtTargetSensor(const al::HitSensor*, const sead::Vector3f&, float);
bool isSensorValid(const al::HitSensor*);
bool isHitBoxSensor(const al::HitSensor*, const sead::Vector3f&, const sead::BoundBox3f&);
void getSensorRadius(const al::HitSensor*);
bool isHitBoxSensor(const al::HitSensor*, const sead::Matrix34f&, const sead::BoundBox3f&);
bool isHitCylinderSensor(const al::HitSensor*, const sead::Vector3f&, const sead::Vector3f&, float);
bool isHitCylinderSensor(const al::HitSensor*, const al::HitSensor*, const sead::Vector3f&, float);
bool isHitCylinderSensor(sead::Vector3f*, sead::Vector3f*, const al::HitSensor*, const sead::Vector3f&, const sead::Vector3f&, float);
bool isHitCylinderSensor(sead::Vector3f*, sead::Vector3f*, const al::HitSensor*, const al::HitSensor*, const sead::Vector3f&, float);
bool isHitCylinderSensorHeight(const al::HitSensor*, const al::HitSensor*, const sead::Vector3f&, float, float);
bool isHitCircleSensor(sead::Vector3f*, sead::Vector3f*, const al::HitSensor*, const sead::Vector3f&, const sead::Vector3f&, float, float);
bool isHitCircleSensor(sead::Vector3f*, sead::Vector3f*, const al::HitSensor*, const al::HitSensor*, const sead::Vector3f&, float, float);
bool isHitCircleSensor(const al::HitSensor*, const sead::Vector3f&, const sead::Vector3f&, float, float);
bool isHitCircleSensor(const al::HitSensor*, const al::HitSensor*, const sead::Vector3f&, float, float);
bool isHitPlaneSensor(const al::HitSensor*, const sead::Vector3f&, const sead::Vector3f&, float);
bool isHitPlaneSensor(const al::HitSensor*, const al::HitSensor*, const sead::Vector3f&, float);
void getActorTrans(const al::HitSensor*);
void getActorVelocity(const al::HitSensor*);
void getActorGravity(const al::HitSensor*);
bool isSensorName(const al::HitSensor*, const char*);
bool isSensorHostName(const al::HitSensor*, const char*);
bool isSensorHost(const al::HitSensor*, const al::LiveActor*);
void validateHitSensors(al::LiveActor*);
void invalidateHitSensors(al::LiveActor*);
bool isSensorValid(const al::LiveActor*, const char*);
void validateHitSensor(al::LiveActor*, const char*);
void invalidateHitSensor(al::LiveActor*, const char*);
void validateHitSensorBindableAll(al::LiveActor*);
bool isSensorBindableAll(const al::HitSensor*);
void validateHitSensorEnemyAll(al::LiveActor*);
bool isSensorEnemy(const al::HitSensor*);
void validateHitSensorEnemyAttackAll(al::LiveActor*);
bool isSensorEnemyAttack(const al::HitSensor*);
void validateHitSensorEnemyBodyAll(al::LiveActor*);
bool isSensorEnemyBody(const al::HitSensor*);
void validateHitSensorEyeAll(al::LiveActor*);
bool isSensorEye(const al::HitSensor*);
void validateHitSensorMapObjAll(al::LiveActor*);
bool isSensorMapObj(const al::HitSensor*);
void validateHitSensorNpcAll(al::LiveActor*);
bool isSensorNpc(const al::HitSensor*);
void validateHitSensorPlayerAll(al::LiveActor*);
bool isSensorPlayerAll(const al::HitSensor*);
void validateHitSensorRideAll(al::LiveActor*);
bool isSensorRide(const al::HitSensor*);
void invalidateHitSensorEyeAll(al::LiveActor*);
void invalidateHitSensorPlayerAll(al::LiveActor*);
void invalidateHitSensorPlayerAttackAll(al::LiveActor*);
bool isSensorPlayerAttack(const al::HitSensor*);
}  // namespace al
