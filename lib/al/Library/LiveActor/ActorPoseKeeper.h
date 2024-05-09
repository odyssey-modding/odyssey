#pragma once

#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {

class ActorPoseKeeperBase {
protected:  // protected so it's visible to all sub-classes (TFSV, TFGSV, ...)
    sead::Vector3f mTrans{0, 0, 0};

    static sead::Vector3f sDefaultVelocity;

public:
    ActorPoseKeeperBase();

    virtual const sead::Vector3f& getRotate() const;
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Vector3f& getFront() const;
    virtual const sead::Vector3f& getUp() const;
    virtual const sead::Quatf& getQuat() const;
    virtual const sead::Vector3f& getGravity() const;
    virtual const sead::Matrix34f& getMtx() const;
    virtual sead::Vector3f* getRotatePtr();
    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Vector3f* getFrontPtr();
    virtual sead::Vector3f* getUpPtr();
    virtual sead::Quatf* getQuatPtr();
    virtual sead::Vector3f* getGravityPtr();
    virtual sead::Matrix34f* getMtxPtr();
    virtual void updatePoseTrans(const sead::Vector3f& trans) = 0;
    virtual void updatePoseRotate(const sead::Vector3f& rot) = 0;
    virtual void updatePoseQuat(const sead::Quatf& quat) = 0;
    virtual void updatePoseMtx(const sead::Matrix34f* mtx) = 0;
    virtual void copyPose(const ActorPoseKeeperBase* other);
    virtual void calcBaseMtx(sead::Matrix34f* mtx) const = 0;
};

class ActorPoseKeeperTFSV : public ActorPoseKeeperBase {
protected:  // protected so it's visible to all sub-classes (TFGSV, TFUSV)
    sead::Vector3f mFront = sead::Vector3f::ez;
    sead::Vector3f mScale{1.0, 1.0, 1.0};
    sead::Vector3f mVelocity{0.0, 0.0, 0.0};

public:
    ActorPoseKeeperTFSV();

    const sead::Vector3f& getFront() const override;
    sead::Vector3f* getFrontPtr() override;
    const sead::Vector3f& getScale() const override;
    sead::Vector3f* getScalePtr() override;
    const sead::Vector3f& getVelocity() const override;
    sead::Vector3f* getVelocityPtr() override;
    void updatePoseTrans(const sead::Vector3f& trans) override;
    void updatePoseRotate(const sead::Vector3f& rot) override;
    void updatePoseQuat(const sead::Quatf& quat) override;
    void updatePoseMtx(const sead::Matrix34f* mtx) override;
    void calcBaseMtx(sead::Matrix34f* mtx) const override;
};

class ActorPoseKeeperTFGSV : public ActorPoseKeeperTFSV {
private:
    sead::Vector3f mGravity{0.0, -1.0, 0.0};

public:
    ActorPoseKeeperTFGSV();

    const sead::Vector3f& getGravity() const override;
    sead::Vector3f* getGravityPtr() override;
    void updatePoseTrans(const sead::Vector3f& trans) override;
    void updatePoseRotate(const sead::Vector3f& rot) override;
    void updatePoseQuat(const sead::Quatf& quat) override;
    void updatePoseMtx(const sead::Matrix34f* mtx) override;
    void calcBaseMtx(sead::Matrix34f* mtx) const override;
};

class ActorPoseKeeperTFUSV : public ActorPoseKeeperTFSV {
private:
    sead::Vector3f mUp = sead::Vector3f::ey;
    bool mIsFrontUp = false;

public:
    ActorPoseKeeperTFUSV();

    const sead::Vector3f& getUp() const override;
    sead::Vector3f* getUpPtr() override;
    void updatePoseTrans(const sead::Vector3f& trans) override;
    void updatePoseRotate(const sead::Vector3f& rot) override;
    void updatePoseQuat(const sead::Quatf& quat) override;
    void updatePoseMtx(const sead::Matrix34f* mtx) override;
    void calcBaseMtx(sead::Matrix34f* mtx) const override;
};

class ActorPoseKeeperTQSV : public ActorPoseKeeperBase {
private:
    sead::Quatf mQuat = sead::Quatf::unit;
    sead::Vector3f mScale{1.0, 1.0, 1.0};
    sead::Vector3f mVelocity{0.0, 0.0, 0.0};

public:
    ActorPoseKeeperTQSV();

    const sead::Quatf& getQuat() const override;
    sead::Quatf* getQuatPtr() override;
    const sead::Vector3f& getScale() const override;
    sead::Vector3f* getScalePtr() override;
    const sead::Vector3f& getVelocity() const override;
    sead::Vector3f* getVelocityPtr() override;
    void updatePoseTrans(const sead::Vector3f& trans) override;
    void updatePoseRotate(const sead::Vector3f& rot) override;
    void updatePoseQuat(const sead::Quatf& quat) override;
    void updatePoseMtx(const sead::Matrix34f* mtx) override;
    void calcBaseMtx(sead::Matrix34f* mtx) const override;
};

class ActorPoseKeeperTQGSV : public ActorPoseKeeperBase {
private:
    sead::Quatf mQuat = sead::Quatf::unit;
    sead::Vector3f mGravity{0.0, -1.0, 0.0};
    sead::Vector3f mScale{1.0, 1.0, 1.0};
    sead::Vector3f mVelocity{0.0, 0.0, 0.0};

public:
    ActorPoseKeeperTQGSV();

    const sead::Quatf& getQuat() const override;
    sead::Quatf* getQuatPtr() override;
    const sead::Vector3f& getGravity() const override;
    sead::Vector3f* getGravityPtr() override;
    const sead::Vector3f& getScale() const override;
    sead::Vector3f* getScalePtr() override;
    const sead::Vector3f& getVelocity() const override;
    sead::Vector3f* getVelocityPtr() override;
    void updatePoseTrans(const sead::Vector3f& trans) override;
    void updatePoseRotate(const sead::Vector3f& rot) override;
    void updatePoseQuat(const sead::Quatf& quat) override;
    void updatePoseMtx(const sead::Matrix34f* mtx) override;
    void calcBaseMtx(sead::Matrix34f* mtx) const override;
};

class ActorPoseKeeperTQGMSV : public ActorPoseKeeperBase {
private:
    sead::Quatf mQuat = sead::Quatf::unit;
    sead::Vector3f mGravity{0.0, -1.0, 0.0};
    sead::Vector3f mScale{1.0, 1.0, 1.0};
    sead::Vector3f mVelocity{0.0, 0.0, 0.0};
    sead::Matrix34f mMtx = sead::Matrix34f::ident;

public:
    ActorPoseKeeperTQGMSV();

    const sead::Quatf& getQuat() const override;
    sead::Quatf* getQuatPtr() override;
    const sead::Vector3f& getGravity() const override;
    sead::Vector3f* getGravityPtr() override;
    const sead::Matrix34f& getMtx() const override;
    sead::Matrix34f* getMtxPtr() override;
    const sead::Vector3f& getScale() const override;
    sead::Vector3f* getScalePtr() override;
    const sead::Vector3f& getVelocity() const override;
    sead::Vector3f* getVelocityPtr() override;
    void updatePoseTrans(const sead::Vector3f& trans) override;
    void updatePoseRotate(const sead::Vector3f& rot) override;
    void updatePoseQuat(const sead::Quatf& quat) override;
    void updatePoseMtx(const sead::Matrix34f* mtx) override;
    void calcBaseMtx(sead::Matrix34f* mtx) const override;
};

class ActorPoseKeeperTRSV : public ActorPoseKeeperBase {
private:
    sead::Vector3f mRotate{0.0, 0.0, 0.0};
    sead::Vector3f mScale{1.0, 1.0, 1.0};
    sead::Vector3f mVelocity{0.0, 0.0, 0.0};

public:
    ActorPoseKeeperTRSV();

    const sead::Vector3f& getRotate() const override;
    sead::Vector3f* getRotatePtr() override;
    const sead::Vector3f& getScale() const override;
    sead::Vector3f* getScalePtr() override;
    const sead::Vector3f& getVelocity() const override;
    sead::Vector3f* getVelocityPtr() override;
    void updatePoseTrans(const sead::Vector3f& trans) override;
    void updatePoseRotate(const sead::Vector3f& rot) override;
    void updatePoseQuat(const sead::Quatf& quat) override;
    void updatePoseMtx(const sead::Matrix34f* mtx) override;
    void calcBaseMtx(sead::Matrix34f* mtx) const override;
};

class ActorPoseKeeperTRMSV : public ActorPoseKeeperBase {
private:
    sead::Vector3f mRotate{0.0, 0.0, 0.0};
    sead::Vector3f mScale{1.0, 1.0, 1.0};
    sead::Vector3f mVelocity{0.0, 0.0, 0.0};
    sead::Matrix34f mMtx;  // manually set in the ctor
public:
    ActorPoseKeeperTRMSV();

    const sead::Vector3f& getRotate() const override;
    sead::Vector3f* getRotatePtr() override;
    const sead::Matrix34f& getMtx() const override;
    sead::Matrix34f* getMtxPtr() override;
    const sead::Vector3f& getScale() const override;
    sead::Vector3f* getScalePtr() override;
    const sead::Vector3f& getVelocity() const override;
    sead::Vector3f* getVelocityPtr() override;
    __attribute__((flatten)) void updatePoseTrans(const sead::Vector3f& trans) override;
    void updatePoseRotate(const sead::Vector3f& rot) override;
    void updatePoseQuat(const sead::Quatf& quat) override;
    void updatePoseMtx(const sead::Matrix34f* mtx) override;
    void calcBaseMtx(sead::Matrix34f* mtx) const override;
};

class ActorPoseKeeperTRGMSV : public ActorPoseKeeperBase {
private:
    sead::Vector3f mRotate{0.0, 0.0, 0.0};
    sead::Vector3f mGravity{0.0, -1.0, 0.0};
    sead::Vector3f mScale{1.0, 1.0, 1.0};
    sead::Vector3f mVelocity{0.0, 0.0, 0.0};
    sead::Matrix34f mMtx;

public:
    ActorPoseKeeperTRGMSV();

    const sead::Vector3f& getRotate() const override;
    sead::Vector3f* getRotatePtr() override;
    const sead::Vector3f& getGravity() const override;
    sead::Vector3f* getGravityPtr() override;
    const sead::Matrix34f& getMtx() const override;
    sead::Matrix34f* getMtxPtr() override;
    const sead::Vector3f& getScale() const override;
    sead::Vector3f* getScalePtr() override;
    const sead::Vector3f& getVelocity() const override;
    sead::Vector3f* getVelocityPtr() override;
    void updatePoseTrans(const sead::Vector3f& trans) override;
    void updatePoseRotate(const sead::Vector3f& rot) override;
    void updatePoseQuat(const sead::Quatf& quat) override;
    void updatePoseMtx(const sead::Matrix34f* mtx) override;
    void calcBaseMtx(sead::Matrix34f* mtx) const override;
};

class LiveActor;

void initActorPoseT(al::LiveActor* actor, const sead::Vector3f&);
void setTrans(al::LiveActor* actor, const sead::Vector3f&);
void initActorPoseTR(al::LiveActor* actor, const sead::Vector3f&, const sead::Vector3f&);
void setRotate(al::LiveActor* actor, const sead::Vector3f&);
void makeMtxSRT(sead::Matrix34f*, const al::LiveActor* actor);
void makeMtxRT(sead::Matrix34f*, const al::LiveActor* actor);
void makeMtxR(sead::Matrix34f*, const al::LiveActor* actor);
void calcAnimFrontGravityPos(al::LiveActor* actor, const sead::Vector3f&);
sead::Vector3f& getGravity(const al::LiveActor* actor);
sead::Vector3f& getTrans(const al::LiveActor* actor);
sead::Vector3f& getScale(const al::LiveActor* actor);
void copyPose(al::LiveActor* actor, const al::LiveActor* target);
void updatePoseTrans(al::LiveActor* actor, const sead::Vector3f&);
void updatePoseRotate(al::LiveActor* actor, const sead::Vector3f&);
void updatePoseQuat(al::LiveActor* actor, const sead::Quatf&);
void updatePoseMtx(al::LiveActor* actor, const sead::Matrix34f*);
void calcSideDir(sead::Vector3f*, const al::LiveActor* actor);
void calcLeftDir(sead::Vector3f*, const al::LiveActor* actor);
void calcRightDir(sead::Vector3f*, const al::LiveActor* actor);
void calcUpDir(sead::Vector3f*, const al::LiveActor* actor);
void calcDownDir(sead::Vector3f*, const al::LiveActor* actor);
void calcFrontDir(sead::Vector3f*, const al::LiveActor* actor);
void calcBackDir(sead::Vector3f*, const al::LiveActor* actor);
void calcPoseDir(sead::Vector3f*, sead::Vector3f*, sead::Vector3f*, const al::LiveActor* actor);
void calcQuat(sead::Quatf*, const al::LiveActor* actor);
void calcDistanceSignLocalXDir(const al::LiveActor* actor, const sead::Vector3f&);
void calcDistanceSignLocalYDir(const al::LiveActor* actor, const sead::Vector3f&);
void calcDistanceSignLocalZDir(const al::LiveActor* actor, const sead::Vector3f&);
void calcDistanceLocalXDir(const al::LiveActor* actor, const sead::Vector3f&);
void calcDistanceLocalYDir(const al::LiveActor* actor, const sead::Vector3f&);
void calcDistanceLocalZDir(const al::LiveActor* actor, const sead::Vector3f&);
sead::Vector3f* getTransPtr(al::LiveActor* actor);
void setTrans(al::LiveActor* actor, f32, f32, f32);
void setTransX(al::LiveActor* actor, f32);
void setTransY(al::LiveActor* actor, f32);
void setTransZ(al::LiveActor* actor, f32);
const sead::Vector3f& getRotate(const al::LiveActor* actor);
void getRotatePtr(al::LiveActor* actor);
void setRotate(al::LiveActor* actor, f32, f32, f32);
void setRotateX(al::LiveActor* actor, f32);
void setRotateY(al::LiveActor* actor, f32);
void setRotateZ(al::LiveActor* actor, f32);
void getScalePtr(al::LiveActor* actor);
bool tryGetScalePtr(al::LiveActor* actor);
void getScaleX(const al::LiveActor* actor);
void getScaleY(const al::LiveActor* actor);
void getScaleZ(const al::LiveActor* actor);
void setScale(al::LiveActor* actor, const sead::Vector3f&);
void setScale(al::LiveActor* actor, f32, f32, f32);
void setScaleAll(al::LiveActor* actor, f32);
void setScaleX(al::LiveActor* actor, f32);
void setScaleY(al::LiveActor* actor, f32);
void setScaleZ(al::LiveActor* actor, f32);
bool isFrontTarget(const al::LiveActor* actor, const sead::Vector3f&);
bool isFrontDir(const al::LiveActor* actor, const sead::Vector3f&);
bool isBackTarget(const al::LiveActor* actor, const sead::Vector3f&);
bool isBackDir(const al::LiveActor* actor, const sead::Vector3f&);
bool isLeftTarget(const al::LiveActor* actor, const sead::Vector3f&);
bool isLeftDir(const al::LiveActor* actor, const sead::Vector3f&);
bool isRightTarget(const al::LiveActor* actor, const sead::Vector3f&);
bool isRightDir(const al::LiveActor* actor, const sead::Vector3f&);
bool isUpTarget(const al::LiveActor* actor, const sead::Vector3f&);
bool isUpDir(const al::LiveActor* actor, const sead::Vector3f&);
bool isDownTarget(const al::LiveActor* actor, const sead::Vector3f&);
bool isDownDir(const al::LiveActor* actor, const sead::Vector3f&);
void getQuat(const al::LiveActor* actor);
void getQuatPtr(al::LiveActor* actor);
bool tryGetQuatPtr(al::LiveActor* actor);
void setQuat(al::LiveActor* actor, const sead::Quatf&);
void getGravityPtr(const al::LiveActor* actor);
void setGravity(const al::LiveActor* actor, const sead::Vector3f&);
sead::Vector3f getFront(const al::LiveActor* actor);
sead::Vector3f* getFrontPtr(al::LiveActor* actor);
void setFront(al::LiveActor* actor, const sead::Vector3f&);
void getUp(const al::LiveActor* actor);
void getUpPtr(al::LiveActor* actor);
void setUp(al::LiveActor* actor, const sead::Vector3f&);
void multVecPoseNoTrans(sead::Vector3f*, const al::LiveActor* actor, const sead::Vector3f&);
void multVecPose(sead::Vector3f*, const al::LiveActor* actor, const sead::Vector3f&);
void multVecPoseAndScale(sead::Vector3f*, const al::LiveActor* actor, const sead::Vector3f&);
void multVecInvPose(sead::Vector3f*, const al::LiveActor* actor, const sead::Vector3f&);
void multVecInvQuat(sead::Vector3f*, const al::LiveActor* actor, const sead::Vector3f&);
void multMtxInvPose(sead::Matrix34f*, const al::LiveActor* actor, const sead::Matrix34f&);
void calcTransLocalOffset(sead::Vector3f*, const al::LiveActor* actor, const sead::Vector3f&);

}  // namespace al

class alActorPoseFunction {
    void calcBaseMtx(sead::Matrix34f* mtx, const al::LiveActor* actor);
    void updatePoseTRMSV(al::LiveActor* actor);
};
