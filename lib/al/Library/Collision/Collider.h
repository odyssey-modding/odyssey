#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include <al/Library/Collision/CollisionDirector.h>
#include <al/Library/HostIO/HioNode.h>

typedef unsigned int uint;

namespace al {
class SphereInterpolator;
class SphereHitInfo;
class CollisionPartsFilterBase;
class TriangleFilterBase;
class CollisionDirector;

class Collider : public al::HioNode, public al::IUseCollision {
public:
    Collider(al::CollisionDirector*, const sead::Matrix34f*, const sead::Vector3f*, const sead::Vector3f*, float, float, uint);
    void calcCheckPos(sead::Vector3f*);
    void calcMovePowerByContact(sead::Vector3f*, const sead::Vector3f&);
    void clear();
    void clearContactPlane();
    void clearStoredPlaneNum();
    sead::Vector3f collide(const sead::Vector3f&);
    void findCollidePos(int*, al::SphereInterpolator*, al::SphereHitInfo*, uint);
    void getPlane(int);
    void getRecentOnGroundNormal(uint);
    void obtainMomentFixReaction(al::SphereHitInfo*, sead::Vector3f*, sead::Vector3f*, bool, uint);
    void onInvalidate();
    void preCollide(al::SphereInterpolator*, sead::Vector3f*, float*, const sead::Vector3f&, al::SphereHitInfo*, uint);
    void setCollisionPartsFilter(const al::CollisionPartsFilterBase*);
    void setTriangleFilter();
    void storeContactPlane(al::SphereHitInfo*);
    void storeCurrentHitInfo(al::SphereHitInfo*, uint);
    void updateRecentOnGroundInfo();
};
}  // namespace al
