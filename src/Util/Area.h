#pragma once

#include <al/Library/LiveActor/LiveActor.h>
#include <math/seadVector.h>

namespace al {
class AreaObj;
class Triangle;
}  // namespace al

namespace rs {
bool tryFind2DAreaObj(al::IUseAreaObj const*, sead::Vector3f const&);
bool tryFind2DAreaObj(al::LiveActor const*, sead::Vector3f*, sead::Vector3f*);
void calc2DAreaLockDir(sead::Vector3f*, al::AreaObj const*, sead::Vector3f const&);
void get2DAreaPos(sead::Vector3f*, al::AreaObj const*);
bool isIn2DArea(al::LiveActor const*, sead::Vector3f*, sead::Vector3f*);
bool isInChangeStageArea(al::LiveActor const*, sead::Vector3f const*);
bool isInWarpArea(al::LiveActor const*);
bool isInLowGravityArea(al::LiveActor const*);
bool isInItemVanishArea(al::LiveActor const*);
bool tryFindStageMapAreaAndGetPlayerPoint(sead::Vector3f*, al::IUseAreaObj const*, sead::Vector3f const&);
void calcFindWaterAreaSurfaceNoWaveByArrow(al::LiveActor const*, sead::Vector3f*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
bool isPushOut2DAreaOpposite(al::AreaObj const*);
bool isFaceTo2DAreaPushOutDir(al::AreaObj const*);
void calc2DAreaFreeDir(sead::Vector3f*, al::AreaObj const*, sead::Vector3f const&);
void calc2DAreaGravity(sead::Vector3f*, al::AreaObj const*, sead::Vector3f const&);
void calc2DAreaSnapPower(sead::Vector3f*, float*, al::AreaObj const*, sead::Vector3f const&);
void calc2DAreaDistanceGravity(sead::Vector3f*, al::AreaObj const*, sead::Vector3f const&);
float get2DAreaSurfaceDistance(al::AreaObj const*);
void calc2DAreaSnapPowerSurfaceDistance(sead::Vector3f*, float*, al::AreaObj const*, sead::Vector3f const&, float);
void calcExtForceAreaVelocity(sead::Vector3f*, al::IUseAreaObj const*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
bool tryFindRecoveryTargetPosArea(bool*, sead::Vector3f*, sead::Vector3f*, al::AreaObj const**, al::IUseAreaObj const*, sead::Vector3f const&);
bool tryFindForceRecoveryArea(sead::Vector3f*, sead::Vector3f*, al::AreaObj const**, al::IUseAreaObj const*, sead::Vector3f const&);
bool isInvalidTriangleDisk(al::Triangle const&, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, float,
                           float);
bool isInTriangleDisk(al::Triangle const&, sead::Vector3f const&, sead::Vector3f const&, float, float);
}  // namespace rs