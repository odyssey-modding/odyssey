#pragma once

#include <math/seadVector.h>

namespace al {
class AreaObj;
class IUseAreaObj;
class LiveActor;
class Triangle;
}  // namespace al

namespace rs {
bool tryFind2DAreaObj(const al::IUseAreaObj*, const sead::Vector3f&);
bool tryFind2DAreaObj(const al::LiveActor*, sead::Vector3f*, sead::Vector3f*);
bool calc2DAreaLockDir(sead::Vector3f*, const al::AreaObj*, const sead::Vector3f&);
void get2DAreaPos(sead::Vector3f*, const al::AreaObj*);
bool isIn2DArea(const al::LiveActor*, sead::Vector3f*, sead::Vector3f*);
bool isInChangeStageArea(const al::LiveActor*, const sead::Vector3f*);
bool isInWarpArea(const al::LiveActor*);
bool isInLowGravityArea(const al::LiveActor*);
bool isInItemVanishArea(const al::LiveActor*);
bool tryFindStageMapAreaAndGetPlayerPoint(sead::Vector3f*, const al::IUseAreaObj*, const sead::Vector3f&);
bool calcFindWaterAreaSurfaceNoWaveByArrow(const al::LiveActor*, sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
bool isPushOut2DAreaOpposite(const al::AreaObj*);
bool isFaceTo2DAreaPushOutDir(const al::AreaObj*);
bool calc2DAreaFreeDir(sead::Vector3f*, const al::AreaObj*, const sead::Vector3f&);
bool calc2DAreaGravity(sead::Vector3f*, const al::AreaObj*, const sead::Vector3f&);
bool calc2DAreaSnapPower(sead::Vector3f*, f32*, const al::AreaObj*, const sead::Vector3f&);
bool calc2DAreaDistanceGravity(sead::Vector3f*, const al::AreaObj*, const sead::Vector3f&);
f32 get2DAreaSurfaceDistance(const al::AreaObj*);
bool calc2DAreaSnapPowerSurfaceDistance(sead::Vector3f*, f32*, const al::AreaObj*, const sead::Vector3f&, f32);
bool calcExtForceAreaVelocity(sead::Vector3f*, const al::IUseAreaObj*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
bool tryFindRecoveryTargetPosArea(bool*, sead::Vector3f*, sead::Vector3f*, const al::AreaObj**, const al::IUseAreaObj*, const sead::Vector3f&);
bool tryFindForceRecoveryArea(sead::Vector3f*, sead::Vector3f*, const al::AreaObj**, const al::IUseAreaObj*, const sead::Vector3f&);
bool isInvalidTriangleDisk(const al::Triangle&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32, f32);
bool isInTriangleDisk(const al::Triangle&, const sead::Vector3f&, const sead::Vector3f&, f32, f32);
}  // namespace rs