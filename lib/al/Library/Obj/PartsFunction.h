#pragma once

#include <al/Library/LiveActor/LiveActor.h>

namespace al {
class HostSyncTowerCamera;

void createCollisionObj(const al::LiveActor*, const al::ActorInitInfo&, const char*, al::HitSensor*, const char*, const char*);
void createCollisionObjMtx(const al::LiveActor*, const al::ActorInitInfo&, const char*, al::HitSensor*, const sead::Matrix34f*, const char*);
void createPartsModel(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const sead::Matrix34f*);
void createPartsModelFile(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const char*);
void createPartsModelFileSuffix(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const char*, const char*);
void createSimplePartsModel(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const char*);
void createSimplePartsModelSuffix(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const char*, const char*);
void createPartsModelSuffix(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const char*, const sead::Matrix34f*);
void createPartsModelJoint(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const char*);
void createPartsModelSuffixJoint(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const char*, const char*);
void appearBreakModelRandomRotateY(al::LiveActor*);
bool updateSyncHostVisible(bool*, al::LiveActor*, const al::LiveActor*, bool);
bool isTraceModelRandomRotate(const al::LiveActor*);
void createBreakModel(const al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const char*, const sead::Matrix34f*, const char*);
void createHostSyncTowerCamera(al::LiveActor*, const al::ActorInitInfo&);
void activateHostSyncTowerCamera(al::HostSyncTowerCamera*);
void deactivateHostSyncTowerCamera(al::HostSyncTowerCamera*);
void updateHostSyncTowerCamera(al::HostSyncTowerCamera*);
bool tryCreateLinksKeyMoveCameraObj(const al::ActorInitInfo&, const char*);
bool tryCreateLinksKeyMoveCameraObjWithInterpole(const al::ActorInitInfo&, const char*);
}  // namespace al