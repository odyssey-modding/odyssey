#pragma once

#include "al/Library/LiveActor/LiveActor.h"

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
void getSensorKeeper(al::LiveActor const*);
void sendMsgSensorToSensor(al::SensorMsg const&, al::HitSensor*, al::HitSensor*);
void sendMsgToActorUnusedSensor(al::SensorMsg const&, al::LiveActor*);
}  // namespace alActorSensorFunction

namespace al {
class SensorSortCmpFuncBase;
class ActorSensorController;

void addHitSensorPlayer(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensor(al::LiveActor*, al::ActorInitInfo const&, char const*, unsigned int, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorPlayerAttack(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorPlayerEye(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorEnemy(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorEnemyBody(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorEnemyAttack(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorMapObj(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorBindable(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorBindableGoal(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorBindableAllPlayer(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorBindableBubbleOutScreen(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorBindableKoura(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorBindableRouteDokan(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorBindableBubblePadInput(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorCollisionParts(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void addHitSensorEye(al::LiveActor*, al::ActorInitInfo const&, char const*, float, unsigned short, sead::Vector3<float> const&);
void setHitSensorSort(al::LiveActor*, char const*, al::SensorSortCmpFuncBase const*);
void setHitSensorPosPtr(al::LiveActor*, char const*, sead::Vector3<float> const*);
void getHitSensor(al::LiveActor const*, char const*);
void setHitSensorMtxPtr(al::LiveActor*, char const*, sead::Matrix34<float> const*);
void setHitSensorJointMtx(al::LiveActor*, char const*, char const*);
void setSensorRadius(al::LiveActor*, char const*, float);
void setSensorRadius(al::LiveActor*, float);
void getSensorRadius(al::LiveActor const*, char const*);
void getSensorRadius(al::LiveActor const*);
void getSensorPos(al::LiveActor const*, char const*);
void getSensorPos(al::LiveActor const*);
void setSensorFollowPosOffset(al::LiveActor*, char const*, sead::Vector3<float> const&);
void setSensorFollowPosOffset(al::LiveActor*, sead::Vector3<float> const&);
void getSensorFollowPosOffset(al::LiveActor const*, char const*);
void getSensorFollowPosOffset(al::LiveActor const*);
void createActorSensorController(al::LiveActor*, char const*);
void setSensorRadius(al::ActorSensorController*, float);
void setSensorScale(al::ActorSensorController*, float);
void setSensorFollowPosOffset(al::ActorSensorController*, sead::Vector3<float> const&);
void getOriginalSensorRadius(al::ActorSensorController const*);
void getOriginalSensorFollowPosOffset(al::ActorSensorController const*);
void resetActorSensorController(al::ActorSensorController*);
void calcPosBetweenSensors(sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*, float);
void calcDistance(al::HitSensor const*, al::HitSensor const*);
void getSensorPos(al::HitSensor const*);
void calcDistanceV(sead::Vector3<float> const&, al::HitSensor const*, al::HitSensor const*);
void calcDistanceH(sead::Vector3<float> const&, al::HitSensor const*, al::HitSensor const*);
void calcDirBetweenSensors(sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*);
void calcDirBetweenSensorsH(sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*);
void calcDirBetweenSensorsNormal(sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*, sead::Vector3<float>);
void calcVecBetweenSensors(sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*);
void calcVecBetweenSensorsH(sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*);
void calcVecBetweenSensorsNormal(sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*, sead::Vector3<float>);
void calcStrikeArrowCollideWallAndCeilingBetweenAttackSensor(al::LiveActor const*, al::HitSensor const*, al::HitSensor const*,
                                                             sead::Vector3<float> const&, float);
void getSensorHost(al::HitSensor const*);
bool isFaceBetweenSensors(sead::Vector3<float> const&, al::HitSensor const*, al::HitSensor const*);
bool isFaceBetweenSensorsH(sead::Vector3<float> const&, al::HitSensor const*, al::HitSensor const*);
bool isEnableLookAtTargetSensor(al::HitSensor const*, sead::Vector3<float> const&, float);
bool isSensorValid(al::HitSensor const*);
bool isHitBoxSensor(al::HitSensor const*, sead::Vector3<float> const&, sead::BoundBox3<float> const&);
void getSensorRadius(al::HitSensor const*);
bool isHitBoxSensor(al::HitSensor const*, sead::Matrix34<float> const&, sead::BoundBox3<float> const&);
bool isHitCylinderSensor(al::HitSensor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float);
bool isHitCylinderSensor(al::HitSensor const*, al::HitSensor const*, sead::Vector3<float> const&, float);
bool isHitCylinderSensor(sead::Vector3<float>*, sead::Vector3<float>*, al::HitSensor const*, sead::Vector3<float> const&, sead::Vector3<float> const&,
                         float);
bool isHitCylinderSensor(sead::Vector3<float>*, sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*, sead::Vector3<float> const&,
                         float);
bool isHitCylinderSensorHeight(al::HitSensor const*, al::HitSensor const*, sead::Vector3<float> const&, float, float);
bool isHitCircleSensor(sead::Vector3<float>*, sead::Vector3<float>*, al::HitSensor const*, sead::Vector3<float> const&, sead::Vector3<float> const&,
                       float, float);
bool isHitCircleSensor(sead::Vector3<float>*, sead::Vector3<float>*, al::HitSensor const*, al::HitSensor const*, sead::Vector3<float> const&, float,
                       float);
bool isHitCircleSensor(al::HitSensor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float, float);
bool isHitCircleSensor(al::HitSensor const*, al::HitSensor const*, sead::Vector3<float> const&, float, float);
bool isHitPlaneSensor(al::HitSensor const*, sead::Vector3<float> const&, sead::Vector3<float> const&, float);
bool isHitPlaneSensor(al::HitSensor const*, al::HitSensor const*, sead::Vector3<float> const&, float);
void getActorTrans(al::HitSensor const*);
void getActorVelocity(al::HitSensor const*);
void getActorGravity(al::HitSensor const*);
bool isSensorName(al::HitSensor const*, char const*);
bool isSensorHostName(al::HitSensor const*, char const*);
bool isSensorHost(al::HitSensor const*, al::LiveActor const*);
void validateHitSensors(al::LiveActor*);
void invalidateHitSensors(al::LiveActor*);
bool isSensorValid(al::LiveActor const*, char const*);
void validateHitSensor(al::LiveActor*, char const*);
void invalidateHitSensor(al::LiveActor*, char const*);
void validateHitSensorBindableAll(al::LiveActor*);
bool isSensorBindableAll(al::HitSensor const*);
void validateHitSensorEnemyAll(al::LiveActor*);
bool isSensorEnemy(al::HitSensor const*);
void validateHitSensorEnemyAttackAll(al::LiveActor*);
bool isSensorEnemyAttack(al::HitSensor const*);
void validateHitSensorEnemyBodyAll(al::LiveActor*);
bool isSensorEnemyBody(al::HitSensor const*);
void validateHitSensorEyeAll(al::LiveActor*);
bool isSensorEye(al::HitSensor const*);
void validateHitSensorMapObjAll(al::LiveActor*);
bool isSensorMapObj(al::HitSensor const*);
void validateHitSensorNpcAll(al::LiveActor*);
bool isSensorNpc(al::HitSensor const*);
void validateHitSensorPlayerAll(al::LiveActor*);
bool isSensorPlayerAll(al::HitSensor const*);
void validateHitSensorRideAll(al::LiveActor*);
bool isSensorRide(al::HitSensor const*);
void invalidateHitSensorEyeAll(al::LiveActor*);
void invalidateHitSensorPlayerAll(al::LiveActor*);
void invalidateHitSensorPlayerAttackAll(al::LiveActor*);
bool isSensorPlayerAttack(al::HitSensor const*);
}  // namespace al