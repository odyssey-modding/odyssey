#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {

void makeBayerMatrix(s32*, s32);
void f32ToF16(f32);
void f16ToF32(u16);
class MtxPtrHolder {
    MtxPtrHolder();
    void init(s32);
    void setMtxPtrAndName(s32, char const*, sead::Matrix34f const*);
    void setMtxPtr(char const*, sead::Matrix34f const*);
    void findIndex(char const*) const;
    void findMtxPtr(char const*) const;
    bool tryFindMtxPtr(char const*) const;
    bool tryFindIndex(char const*) const;
};

void makeMtxRotateTrans(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxFromTwoAxis(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&, s32, s32);
void makeMtxFrontUp(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxFrontSide(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxUpFront(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxUpSide(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxSideUp(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxSideFront(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxFrontNoSupport(sead::Matrix34f*, sead::Vector3f const&);
void makeMtxFrontNoSupportPos(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxUpNoSupport(sead::Matrix34f*, sead::Vector3f const&);
void makeMtxUpNoSupportPos(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxSideNoSupport(sead::Matrix34f*, sead::Vector3f const&);
void makeMtxSideNoSupportPos(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxQuatPos(sead::Matrix34f*, sead::Quatf const&, sead::Vector3f const&);
void makeMtxQuatScalePos(sead::Matrix34f*, sead::Quatf const&, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxQuatScalePos(sead::Matrix44f*, sead::Quatf const&, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxFrontUpPos(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxFrontSidePos(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxUpFrontPos(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxUpSidePos(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxSideUpPos(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxSideFrontPos(sead::Matrix34f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxFollowTarget(sead::Matrix34f*, sead::Matrix34f const&, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxProj(sead::Matrix44f*, sead::Vector2<f32> const&, sead::Vector3f const&, sead::Vector3f const&);
void makeMtxProjFromQuatPoseUp(sead::Matrix44f*, sead::Quatf const&, sead::Vector2<f32> const&, sead::Vector3f const&);
void makeMtxProjFromQuatPoseFront(sead::Matrix44f*, sead::Quatf const&, sead::Vector2<f32> const&, sead::Vector3f const&);
void makeMtxProjFromQuatPoseSide(sead::Matrix44f*, sead::Quatf const&, sead::Vector2<f32> const&, sead::Vector3f const&);
void makeMtxProjFromUp(sead::Matrix44f*, sead::Vector2<f32> const&, sead::Vector3f const&);
void rotateMtxXDirDegree(sead::Matrix34f*, sead::Matrix34f const&, f32);
void rotateMtxYDirDegree(sead::Matrix34f*, sead::Matrix34f const&, f32);
void rotateMtxZDirDegree(sead::Matrix34f*, sead::Matrix34f const&, f32);
void rotateMtxCenterPosXDirDegree(sead::Matrix34f*, sead::Matrix34f const&, sead::Vector3f const&, f32);
void rotateMtxCenterPosAxisDegree(sead::Matrix34f*, sead::Matrix34f const&, sead::Vector3f const&, sead::Vector3f const&, f32);
void rotateMtxCenterPosYDirDegree(sead::Matrix34f*, sead::Matrix34f const&, sead::Vector3f const&, f32);
void rotateMtxCenterPosZDirDegree(sead::Matrix34f*, sead::Matrix34f const&, sead::Vector3f const&, f32);
void rotateMtxCenterPosQuat(sead::Matrix34f*, sead::Matrix34f const&, sead::Vector3f const&, sead::Quatf const&);
void turnMtxXDirDegree(sead::Matrix34f*, sead::Matrix34f const&, sead::Vector3f const&, f32);
void turnMtxYDirDegree(sead::Matrix34f*, sead::Matrix34f const&, sead::Vector3f const&, f32);
void turnMtxZDirDegree(sead::Matrix34f*, sead::Matrix34f const&, sead::Vector3f const&, f32);
void calcCameraPosFromViewMtx(sead::Vector3f*, sead::Matrix34f const&);
void calcMtxMul(sead::Vector3f*, sead::Matrix34f const&, sead::Vector3f const&);
// void calcMtxMul(sead::Vector3f *,al::Matrix43<f32> const&,sead::Vector3f const&);
void calcMtxScale(sead::Vector3f*, sead::Matrix34f const&);
// void calcMtxScale(sead::Vector3f *,al::Matrix43<f32> const&);
void normalizeMtxScale(sead::Matrix34f*, sead::Matrix34f const&);
void tryNormalizeMtxScaleOrIdentity(sead::Matrix34f*, sead::Matrix34f const&);
void calcMtxLocalTrans(sead::Vector3f*, sead::Matrix34f const&, sead::Vector3f const&);
void calcTransLocalOffsetByMtx(sead::Vector3f*, sead::Matrix34f const&, sead::Vector3f const&);
void preScaleMtx(sead::Matrix34f*, sead::Vector3f const&);
void addTransMtxLocalOffset(sead::Matrix34f*, sead::Matrix34f const&, sead::Vector3f const&);
void blendMtx(sead::Matrix34f*, sead::Matrix34f const&, sead::Matrix34f const&, f32);
void blendMtxRotate(sead::Matrix34f*, sead::Matrix34f const&, sead::Matrix34f const&, f32);
void blendMtxTrans(sead::Matrix34f*, sead::Matrix34f const&, sead::Matrix34f const&, f32);
void calcMtxLocalDirAngleOnPlaneToTarget(sead::Matrix34f const*, sead::Vector3f const&, s32, s32);
void calcMtxLocalDirAngleOnPlaneToDir(sead::Matrix34f const*, sead::Vector3f const&, s32, s32);
void calcRotAxisOrZero(sead::Vector3f*, sead::Matrix34f const&);
void calcMxtInvertOrtho(sead::Matrix34f*, sead::Matrix34f const&);
void calcNearFarByInvProjection(f32*, f32*, sead::Matrix44f const&);
void calcMovedInertiaTensor(sead::Matrix33f*, sead::Matrix33f const&, sead::Vector3f const&, f32);
void calcInertiaTensorByMovedTensorAndCenter(sead::Matrix33f*, sead::Matrix33f const&, sead::Vector3f const&, f32);
void calcInertiaTensorSphere(sead::Matrix33f*, f32, f32);
void calcInertiaTensorBox(sead::Matrix33f*, sead::Vector3f const&, f32);
// void makeMtx34f(sead::Matrix34f *,nn::util::neon::MatrixColumnMajor4x3fType const&);
// void makeMtx44f(sead::Matrix44f *,nn::util::neon::MatrixColumnMajor4x4fType const&);

};  // namespace al