#pragma once

#include <math/seadQuat.h>

namespace al {
void makeQuatFromTwoAxis(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&, s32, s32);
void makeQuatFrontUp(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&);
void makeQuatFrontSide(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&);
void makeQuatFrontNoSupport(sead::Quatf*, sead::Vector3f const&);
void makeQuatUpFront(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&);
void makeQuatUpSide(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&);
void makeQuatUpNoSupport(sead::Quatf*, sead::Vector3f const&);
void makeQuatSideUp(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&);
void makeQuatSideFront(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&);
void makeQuatSideNoSupport(sead::Quatf*, sead::Vector3f const&);
void makeQuatFromToQuat(sead::Quatf*, sead::Quatf const&, sead::Quatf const&);
void makeQuatRotationRate(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&, f32);
void makeQuatRotationLimit(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&, f32);
void makeQuatAxisRotation(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, f32);
void makeQuatRotateDegree(sead::Quatf*, sead::Vector3f const&, f32);
void slerpQuat(sead::Quatf*, sead::Quatf const&, sead::Quatf const&, f32);
void calcQuatSide(sead::Vector3f*, sead::Quatf const&);
void calcQuatUp(sead::Vector3f*, sead::Quatf const&);
void calcQuatGravity(sead::Vector3f*, sead::Quatf const&);
void calcQuatFront(sead::Vector3f*, sead::Quatf const&);
void calcQuatUpY(sead::Quatf const&);
void calcQuatFrontY(sead::Quatf const&);
void calcQuatLocalAxis(sead::Vector3f*, sead::Quatf const&, s32);
void calcQuatLocalSignAxis(sead::Vector3f*, sead::Quatf const&, s32);
void calcQuatRotateDegree(sead::Vector3f*, sead::Quatf const&);
void calcQuatRotateRadian(sead::Vector3f*, sead::Quatf const&);
void calcQuatRotateAxisAndDegree(sead::Vector3f*, f32*, sead::Quatf const&);
void calcQuatRotateAxisAndDegree(sead::Vector3f*, f32*, sead::Quatf const&, sead::Quatf const&);
void rotateQuatRadian(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void makeQuatXDegree(sead::Quatf*, f32);
void makeQuatYDegree(sead::Quatf*, f32);
void makeQuatZDegree(sead::Quatf*, f32);
void rotateQuatXDirDegree(sead::Quatf*, sead::Quatf const&, f32);
void rotateQuatYDirDegree(sead::Quatf*, sead::Quatf const&, f32);
void rotateQuatZDirDegree(sead::Quatf*, sead::Quatf const&, f32);
void rotateQuatLocalDirDegree(sead::Quatf*, sead::Quatf const&, s32, f32);
void rotateQuatMoment(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&);
void rotateQuatMomentDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&);
void rotateQuatRollBall(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, sead::Vector3f const&, f32);
void calcMomentRollBall(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, f32);
void turnQuat(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, sead::Vector3f const&, f32);
void turnQuatXDirRadian(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatYDirRadian(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatZDirRadian(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatXDirRate(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatYDirRate(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatZDirRate(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void tiltQuatDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, sead::Vector3f const&, f32);
void tiltQuatXDirDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void tiltQuatYDirDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void tiltQuatZDirDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatWithAxisDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, f32);
void turnQuatXDirWithYDirDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatXDirWithZDirDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatYDirWithZDirDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatYDirWithXDirDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatZDirWithXDirDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatZDirWithYDirDegree(sead::Quatf*, sead::Quatf const&, sead::Vector3f const&, f32);
void turnQuatZDirToTargetWithAxis(sead::Quatf*, sead::Vector3f const&, sead::Vector3f const&, f32);
void turnQuatFrontToDirDegreeH(sead::Quatf*, sead::Vector3f const&, f32);
void rotateQuatAndTransDegree(sead::Quatf*, sead::Vector3f*, sead::Quatf const&, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&,
                              f32);
void turnVecToVecDegree(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, f32);
void turnVecToVecRate(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, f32);
void turnVecToVecCos(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, f32, sead::Vector3f const&, f32);
void turnVecToVecCosOnPlane(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, f32);
void turnVecToVecCosOnPlane(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, f32);
void rotateVectorCenterDegree(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, f32);
void rotateVectorDegreeX(sead::Vector3f*, f32);
void rotateVectorDegreeY(sead::Vector3f*, f32);
void rotateVectorDegreeZ(sead::Vector3f*, f32);
void rotateVectorQuat(sead::Vector3f*, sead::Quatf const&);
}  // namespace al