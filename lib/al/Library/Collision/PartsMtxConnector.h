#pragma once

#include <math/seadMatrix.h>

namespace al {
class MtxConnector {
private:
    sead::Matrix34f mBaseMtx;
    sead::Matrix34f* mTargetMtx;
    sead::Quatf mBaseQuat;
    sead::Vector3f mBasePos;

public:
    MtxConnector();
    MtxConnector(sead::Quatf const&, sead::Vector3f const&);
    void init(sead::Matrix34f const*, sead::Matrix34f const&);
    void init(sead::Matrix34f const*);
    virtual bool isConnecting() const;
    virtual void clear();
    void multVec(sead::Vector3f*, sead::Vector3f const&) const;
    void multTrans(sead::Vector3f*, sead::Vector3f const&) const;
    void multMtx(sead::Matrix34f*, sead::Matrix34f const&) const;
    void multQT(sead::Quatf*, sead::Vector3f*, sead::Vector3f*) const;
    void multQT(sead::Quatf*, sead::Vector3f*, sead::Vector3f*, sead::Quatf const&, sead::Vector3f const&) const;
    void multQT(sead::Quatf*, sead::Vector3f*, sead::Quatf const&, sead::Vector3f const&) const;
    void getBaseQuat() const;
    void getBaseTrans() const;
    void setBaseQuatTrans(sead::Quatf const&, sead::Vector3f const&);
    void calcConnectInfo(sead::Vector3f*, sead::Quatf*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&) const;
    void calcMtxWithOffset(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&) const;
    bool tryGetParentTrans(sead::Vector3f*) const;
};
}  // namespace al