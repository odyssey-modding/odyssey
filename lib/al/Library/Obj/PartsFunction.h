#pragma once

#include <al/Library/LiveActor/LiveActor.h>

namespace al {
class HostSyncTowerCamera;

void createCollisionObj(al::LiveActor const*, al::ActorInitInfo const&, char const*, al::HitSensor*, char const*, char const*);
void createCollisionObjMtx(al::LiveActor const*, al::ActorInitInfo const&, char const*, al::HitSensor*, sead::Matrix34f const*, char const*);
void createPartsModel(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, sead::Matrix34f const*);
void createPartsModelFile(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, char const*);
void createPartsModelFileSuffix(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, char const*, char const*);
void createSimplePartsModel(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, char const*);
void createSimplePartsModelSuffix(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, char const*, char const*);
void createPartsModelSuffix(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, char const*, sead::Matrix34f const*);
void createPartsModelJoint(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, char const*);
void createPartsModelSuffixJoint(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*, char const*, char const*);
void appearBreakModelRandomRotateY(al::LiveActor*);
bool updateSyncHostVisible(bool*, al::LiveActor*, al::LiveActor const*, bool);
bool isTraceModelRandomRotate(al::LiveActor const*);
void createBreakModel(al::LiveActor const*, al::ActorInitInfo const&, char const*, char const*, char const*, sead::Matrix34f const*, char const*);
void createHostSyncTowerCamera(al::LiveActor*, al::ActorInitInfo const&);
void activateHostSyncTowerCamera(al::HostSyncTowerCamera*);
void deactivateHostSyncTowerCamera(al::HostSyncTowerCamera*);
void updateHostSyncTowerCamera(al::HostSyncTowerCamera*);
bool tryCreateLinksKeyMoveCameraObj(al::ActorInitInfo const&, char const*);
bool tryCreateLinksKeyMoveCameraObjWithInterpole(al::ActorInitInfo const&, char const*);
}  // namespace al