#pragma once

#include <math/seadVector.h>
#include <math/seadMatrix.h>

#include <al/Library/HostIO/HioNode.h>
#include <al/Library/IUse/IUseCollision.h>

typedef unsigned int uint;

namespace al
{
struct SphereInterpolator;
struct SphereHitInfo;
struct CollisionPartsFilterBase;
struct TriangleFilterBase;
class CollisionDirector;

class Collider : public al::HioNode, public IUseCollision {
public:
    Collider(al::CollisionDirector*, sead::Matrix34f const*, sead::Vector3f const*,
             sead::Vector3f const*, float, float, uint);
    void calcCheckPos(sead::Vector3f*);
    void calcMovePowerByContact(sead::Vector3f*, sead::Vector3f const&);
    void clear();
    void clearContactPlane();
    void clearStoredPlaneNum();
    sead::Vector3f collide(sead::Vector3f const&);
    void findCollidePos(int*, al::SphereInterpolator*, al::SphereHitInfo*, uint);
    void getPlane(int);
    void getRecentOnGroundNormal(uint);
    void obtainMomentFixReaction(al::SphereHitInfo*, sead::Vector3f*,
                                          sead::Vector3f*, bool, uint);
    void onInvalidate();
    void preCollide(al::SphereInterpolator*, sead::Vector3f*, float*, sead::Vector3f const&,
                    al::SphereHitInfo*, uint);
    void setCollisionPartsFilter(al::CollisionPartsFilterBase const*);
    void setTriangleFilter(al::TriangleFilterBase const *);
    void storeContactPlane(al::SphereHitInfo *);
    void storeCurrentHitInfo(al::SphereHitInfo *, uint);
    void updateRecentOnGroundInfo();
};
} // namespace al