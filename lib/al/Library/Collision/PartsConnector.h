#pragma once

#include <math/seadMatrix.h>
#include "PartsMtxConnector.h"

namespace al {
class ActorInitInfo;
class CollisionDirector;
class CollisionParts;
class HitInfo;
class HitSensor;
class LiveActor;
class ScreenPointTarget;

class CollisionPartsConnector : public al::MtxConnector {
private:
    const al::CollisionParts* mCollisionParts;

public:
    CollisionPartsConnector();
    void init(const sead::Matrix34f*, const sead::Matrix34f&, const al::CollisionParts*);
    void getConnectingSensor() const;

    virtual bool isConnecting() const override;
    virtual void clear() override;
    virtual bool isMoved() const;
    bool isConnectInvalidCollision() const;
};

class SensorConnector;
class Triangle;

void createMtxConnector(const al::LiveActor*);
void createMtxConnector(const al::LiveActor*, const sead::Quatf&);
bool tryCreateMtxConnector(const al::LiveActor*, const al::ActorInitInfo&);
bool tryCreateMtxConnector(const al::LiveActor*, const al::ActorInitInfo&, const sead::Quatf&);
void createCollisionPartsConnector(const al::LiveActor*, const sead::Quatf&);
bool tryCreateCollisionPartsConnector(const al::LiveActor*, const al::ActorInitInfo&);
bool tryCreateCollisionPartsConnector(const al::LiveActor*, const al::ActorInitInfo&, const sead::Quatf&);
bool isMtxConnectorConnecting(const al::MtxConnector*);
void disconnectMtxConnector(al::MtxConnector*);
void attachMtxConnectorToCollision(al::MtxConnector*, const al::LiveActor*, const sead::Vector3f&, const sead::Vector3f&);
void attachMtxConnectorToCollision(al::MtxConnector*, const al::LiveActor*, bool);
void attachMtxConnectorToCollision(al::MtxConnector*, const al::LiveActor*, float, float);
void attachMtxConnectorToCollisionParts(al::MtxConnector*, const al::CollisionParts*);
void setConnectorBaseQuatTrans(const sead::Quatf&, const sead::Vector3f&, al::MtxConnector*);
void setConnectorBaseQuatTrans(al::LiveActor*, al::MtxConnector*);
void connectPoseQT(al::LiveActor*, const al::MtxConnector*);
void connectPoseQT(al::LiveActor*, const al::MtxConnector*, const sead::Quatf&, const sead::Vector3f&);
void connectPoseTrans(al::LiveActor*, const al::MtxConnector*, const sead::Vector3f&);
void connectPoseMtx(al::LiveActor*, const al::MtxConnector*, const sead::Matrix34f&);
void calcConnectTrans(sead::Vector3f*, const al::MtxConnector*, const sead::Vector3f&);
void calcConnectTrans(sead::Vector3f*, const al::MtxConnector*);
void calcConnectDir(sead::Vector3f*, const al::MtxConnector*, const sead::Vector3f&);
void calcConnectQT(sead::Quatf*, sead::Vector3f*, const al::MtxConnector*, const sead::Quatf&, const sead::Vector3f&);
void calcConnectQT(sead::Quatf*, sead::Vector3f*, const al::MtxConnector*);
void calcConnectMtx(sead::Matrix34f*, const al::MtxConnector*, const sead::Matrix34f&);
void calcConnectMtx(sead::Matrix34f*, const al::MtxConnector*, const sead::Quatf&, const sead::Vector3f&);
void attachMtxConnectorToCollisionRT(al::MtxConnector*, const al::LiveActor*, bool, bool);
void attachMtxConnectorToCollisionQT(al::MtxConnector*, const al::LiveActor*, bool, bool);
void attachMtxConnectorToJoint(al::MtxConnector*, const al::LiveActor*, char const*);
void attachMtxConnectorToJoint(al::MtxConnector*, const al::LiveActor*, char const*, const sead::Vector3f&, const sead::Vector3f&);
void attachMtxConnectorToMtxPtr(al::MtxConnector*, const sead::Matrix34f*, const sead::Vector3f&, const sead::Vector3f&);
void attachMtxConnectorToActor(al::MtxConnector*, const al::LiveActor*);
void attachMtxConnectorToActor(al::MtxConnector*, const al::LiveActor*, const sead::Vector3f&, const sead::Vector3f&);
void attachMtxConnectorToMtxPtr(al::MtxConnector*, const sead::Matrix34f*);
void attachMtxConnectorToSensor(al::MtxConnector*, al::HitSensor*, const sead::Matrix34f&);
void attachSensorConnectorToSensor(al::SensorConnector*, al::HitSensor*, const sead::Matrix34f&);
void attachMtxConnectorToScreenPointTarget(al::MtxConnector*, al::ScreenPointTarget*, const sead::Matrix34f&);
void attachCollisionPartsConnector(al::CollisionPartsConnector*, const al::CollisionParts*);
void attachCollisionPartsConnectorToGround(al::CollisionPartsConnector*, const al::LiveActor*);
void attachToHitTriangle(al::CollisionPartsConnector*, const al::Triangle&, const sead::Matrix34f&);
void attachToHitInfo(al::CollisionPartsConnector*, const al::HitInfo&, const sead::Matrix34f&);
void attachToHitInfoNrmToMinusZ(al::CollisionPartsConnector*, const al::HitInfo&);
void calcConnectInfo(const al::MtxConnector*, sead::Vector3f*, sead::Quatf*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void connectPoseQTUsingConnectInfo(al::LiveActor*, const al::MtxConnector*);
void getConnectBaseQuat(const al::MtxConnector*);
void getConnectBaseTrans(const al::MtxConnector*);
}  // namespace al