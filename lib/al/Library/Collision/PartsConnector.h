#pragma once

#include <al/Library/LiveActor/LiveActor.h>
#include <math/seadMatrix.h>
#include "CollisionDirector.h"
#include "PartsMtxConnector.h"

namespace al {
class CollisionPartsConnector : public al::MtxConnector {
private:
    const al::CollisionParts* mCollisionParts;

public:
    CollisionPartsConnector();
    void init(sead::Matrix34f const*, sead::Matrix34f const&, al::CollisionParts const*);
    void getConnectingSensor() const;

    virtual bool isConnecting() const override;
    virtual void clear() override;
    virtual bool isMoved() const;
    bool isConnectInvalidCollision() const;
};

class SensorConnector;
class Triangle;

void createMtxConnector(al::LiveActor const*);
void createMtxConnector(al::LiveActor const*, sead::Quatf const&);
bool tryCreateMtxConnector(al::LiveActor const*, al::ActorInitInfo const&);
bool tryCreateMtxConnector(al::LiveActor const*, al::ActorInitInfo const&, sead::Quatf const&);
void createCollisionPartsConnector(al::LiveActor const*, sead::Quatf const&);
bool tryCreateCollisionPartsConnector(al::LiveActor const*, al::ActorInitInfo const&);
bool tryCreateCollisionPartsConnector(al::LiveActor const*, al::ActorInitInfo const&, sead::Quatf const&);
bool isMtxConnectorConnecting(al::MtxConnector const*);
void disconnectMtxConnector(al::MtxConnector*);
void attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, sead::Vector3f const&, sead::Vector3f const&);
void attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, bool);
void attachMtxConnectorToCollision(al::MtxConnector*, al::LiveActor const*, float, float);
void attachMtxConnectorToCollisionParts(al::MtxConnector*, al::CollisionParts const*);
void setConnectorBaseQuatTrans(sead::Quatf const&, sead::Vector3f const&, al::MtxConnector*);
void setConnectorBaseQuatTrans(al::LiveActor*, al::MtxConnector*);
void connectPoseQT(al::LiveActor*, al::MtxConnector const*);
void connectPoseQT(al::LiveActor*, al::MtxConnector const*, sead::Quatf const&, sead::Vector3f const&);
void connectPoseTrans(al::LiveActor*, al::MtxConnector const*, sead::Vector3f const&);
void connectPoseMtx(al::LiveActor*, al::MtxConnector const*, sead::Matrix34f const&);
void calcConnectTrans(sead::Vector3f*, al::MtxConnector const*, sead::Vector3f const&);
void calcConnectTrans(sead::Vector3f*, al::MtxConnector const*);
void calcConnectDir(sead::Vector3f*, al::MtxConnector const*, sead::Vector3f const&);
void calcConnectQT(sead::Quatf*, sead::Vector3f*, al::MtxConnector const*, sead::Quatf const&, sead::Vector3f const&);
void calcConnectQT(sead::Quatf*, sead::Vector3f*, al::MtxConnector const*);
void calcConnectMtx(sead::Matrix34f*, al::MtxConnector const*, sead::Matrix34f const&);
void calcConnectMtx(sead::Matrix34f*, al::MtxConnector const*, sead::Quatf const&, sead::Vector3f const&);
void attachMtxConnectorToCollisionRT(al::MtxConnector*, al::LiveActor const*, bool, bool);
void attachMtxConnectorToCollisionQT(al::MtxConnector*, al::LiveActor const*, bool, bool);
void attachMtxConnectorToJoint(al::MtxConnector*, al::LiveActor const*, char const*);
void attachMtxConnectorToJoint(al::MtxConnector*, al::LiveActor const*, char const*, sead::Vector3f const&, sead::Vector3f const&);
void attachMtxConnectorToMtxPtr(al::MtxConnector*, sead::Matrix34f const*, sead::Vector3f const&, sead::Vector3f const&);
void attachMtxConnectorToActor(al::MtxConnector*, al::LiveActor const*);
void attachMtxConnectorToActor(al::MtxConnector*, al::LiveActor const*, sead::Vector3f const&, sead::Vector3f const&);
void attachMtxConnectorToMtxPtr(al::MtxConnector*, sead::Matrix34f const*);
void attachMtxConnectorToSensor(al::MtxConnector*, al::HitSensor*, sead::Matrix34f const&);
void attachSensorConnectorToSensor(al::SensorConnector*, al::HitSensor*, sead::Matrix34f const&);
void attachMtxConnectorToScreenPointTarget(al::MtxConnector*, al::ScreenPointTarget*, sead::Matrix34f const&);
void attachCollisionPartsConnector(al::CollisionPartsConnector*, al::CollisionParts const*);
void attachCollisionPartsConnectorToGround(al::CollisionPartsConnector*, al::LiveActor const*);
void attachToHitTriangle(al::CollisionPartsConnector*, al::Triangle const&, sead::Matrix34f const&);
void attachToHitInfo(al::CollisionPartsConnector*, al::HitInfo const&, sead::Matrix34f const&);
void attachToHitInfoNrmToMinusZ(al::CollisionPartsConnector*, al::HitInfo const&);
void calcConnectInfo(al::MtxConnector const*, sead::Vector3f*, sead::Quatf*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
void connectPoseQTUsingConnectInfo(al::LiveActor*, al::MtxConnector const*);
void getConnectBaseQuat(al::MtxConnector const*);
void getConnectBaseTrans(al::MtxConnector const*);
}  // namespace al