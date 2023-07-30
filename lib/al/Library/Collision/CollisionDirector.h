#pragma once

#include <al/Library/Execute/IUseExecutor.h>
#include <container/seadPtrArray.h>
#include <math/seadVector.h>
#include <prim/seadDelegate.h>

namespace al {
class ICollisionPartsKeeper;
class CollisionPartsKeeperOctree;
class CollisionPartsKeeperPtrArray;
class CollisionPartsFilterBase;
class TriangleFilterBase;
class Strike;
class HitInfo;
class ArrowHitInfo;
class DiskHitInfo;
class SphereHitInfo;
class CollisionParts;
class ExecuteDirector;
class CollisionDirector : public al::IUseExecutor {
private:
    al::ICollisionPartsKeeper* mActivePartsKeeper;
    al::CollisionPartsKeeperOctree* mRootOctree;
    al::CollisionPartsKeeperPtrArray* mCollisionPartsKeeperPtrArray;
    al::CollisionPartsFilterBase* mCollisionPartsFilterBase;
    al::TriangleFilterBase* mTriangleFilterBase;
    sead::PtrArray<ArrowHitInfo>* mStrikeArrowHitInfos;
    sead::PtrArray<DiskHitInfo>* mStrikeDiskHitInfos;
    sead::PtrArray<SphereHitInfo>* mStrikeSphereHitInfos;
    SphereHitInfo* mSphereHitArray;
    DiskHitInfo* mDiskHitArray;

public:
    CollisionDirector(al::ExecuteDirector* executeDirector);
    void setPartsKeeper(al::ICollisionPartsKeeper* partsKeeper);
    void endInit();
    void setPartsFilter(const al::CollisionPartsFilterBase*);
    void setTriFilter(const al::TriangleFilterBase*);
    bool checkStrikePoint(const sead::Vector3f&, al::HitInfo*);
    bool checkStrikeSphere(const sead::Vector3f&, f32, bool, const sead::Vector3f&);
    bool checkStrikeArrow(const sead::Vector3f&, const sead::Vector3f&);
    bool checkStrikeSphereForPlayer(const sead::Vector3f&, f32);
    bool checkStrikeDisk(const sead::Vector3f&, f32, f32, const sead::Vector3f&);
    sead::PtrArray<ArrowHitInfo>* getStrikeArrowInfo(u32 index);
    u32 getStrikeArrowInfoNum();
    sead::PtrArray<DiskHitInfo>* getStrikeSphereInfo(u32 index);
    u32 getStrikeSphereInfoNum();
    sead::PtrArray<SphereHitInfo>* getStrikeDiskInfo(u32 index);
    u32 getStrikeDiskInfoNum();
    void getSphereHitInfoArrayForCollider(al::SphereHitInfo** infoArray, u32* count);
    void getDiskHitInfoArrayForCollider(al::DiskHitInfo** infoArray, u32* count);
    void execute();
    void searchCollisionPartsWithSphere(const sead::Vector3f&, f32, sead::IDelegate1<al::CollisionParts*>&, const al::CollisionPartsFilterBase*);
    void validateCollisionPartsPtrArray(sead::PtrArray<al::CollisionParts>*);
    void invalidateCollisionPartsPtrArray();
    sead::PtrArray<al::CollisionParts>* getCollisionPartsPtrArray();
};

class IUseCollision {
public:
    virtual CollisionDirector* getCollisionDirector() const = 0;
};
}  // namespace al
