#pragma once

#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {
void makeQuatFromTwoAxis(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&, s32, s32);
void makeQuatFrontUp(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&);
void makeQuatFrontSide(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&);
void makeQuatFrontNoSupport(sead::Quatf*, const sead::Vector3f&);
void makeQuatUpFront(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&);
void makeQuatUpSide(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&);
void makeQuatUpNoSupport(sead::Quatf*, const sead::Vector3f&);
void makeQuatSideUp(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&);
void makeQuatSideFront(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&);
void makeQuatSideNoSupport(sead::Quatf*, const sead::Vector3f&);
void makeQuatFromToQuat(sead::Quatf*, const sead::Quatf&, const sead::Quatf&);
void makeQuatRotationRate(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&, f32);
void makeQuatRotationLimit(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&, f32);
void makeQuatAxisRotation(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32);
void makeQuatRotateDegree(sead::Quatf*, const sead::Vector3f&, f32);
void slerpQuat(sead::Quatf*, const sead::Quatf&, const sead::Quatf&, f32);
void calcQuatSide(sead::Vector3f*, const sead::Quatf&);
void calcQuatUp(sead::Vector3f*, const sead::Quatf&);
void calcQuatGravity(sead::Vector3f*, const sead::Quatf&);
void calcQuatFront(sead::Vector3f*, const sead::Quatf&);
void calcQuatUpY(const sead::Quatf&);
void calcQuatFrontY(const sead::Quatf&);
void calcQuatLocalAxis(sead::Vector3f*, const sead::Quatf&, s32);
void calcQuatLocalSignAxis(sead::Vector3f*, const sead::Quatf&, s32);
void calcQuatRotateDegree(sead::Vector3f*, const sead::Quatf&);
void calcQuatRotateRadian(sead::Vector3f*, const sead::Quatf&);
void calcQuatRotateAxisAndDegree(sead::Vector3f*, f32*, const sead::Quatf&);
void calcQuatRotateAxisAndDegree(sead::Vector3f*, f32*, const sead::Quatf&, const sead::Quatf&);
void rotateQuatRadian(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void makeQuatXDegree(sead::Quatf*, f32);
void makeQuatYDegree(sead::Quatf*, f32);
void makeQuatZDegree(sead::Quatf*, f32);
void rotateQuatXDirDegree(sead::Quatf*, const sead::Quatf&, f32);
void rotateQuatYDirDegree(sead::Quatf*, const sead::Quatf&, f32);
void rotateQuatZDirDegree(sead::Quatf*, const sead::Quatf&, f32);
void rotateQuatLocalDirDegree(sead::Quatf*, const sead::Quatf&, s32, f32);
void rotateQuatMoment(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&);
void rotateQuatMomentDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&);
void rotateQuatRollBall(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, const sead::Vector3f&, f32);
void calcMomentRollBall(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
void turnQuat(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, const sead::Vector3f&, f32);
void turnQuatXDirRadian(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatYDirRadian(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatZDirRadian(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatXDirRate(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatYDirRate(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatZDirRate(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void tiltQuatDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, const sead::Vector3f&, f32);
void tiltQuatXDirDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void tiltQuatYDirDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void tiltQuatZDirDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatWithAxisDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32);
void turnQuatXDirWithYDirDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatXDirWithZDirDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatYDirWithZDirDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatYDirWithXDirDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatZDirWithXDirDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatZDirWithYDirDegree(sead::Quatf*, const sead::Quatf&, const sead::Vector3f&, f32);
void turnQuatZDirToTargetWithAxis(sead::Quatf*, const sead::Vector3f&, const sead::Vector3f&, f32);
void turnQuatFrontToDirDegreeH(sead::Quatf*, const sead::Vector3f&, f32);
void rotateQuatAndTransDegree(sead::Quatf*, sead::Vector3f*, const sead::Quatf&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&,
                              f32);
void turnVecToVecDegree(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
void turnVecToVecRate(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
void turnVecToVecCos(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32, const sead::Vector3f&, f32);
void turnVecToVecCosOnPlane(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32);
void turnVecToVecCosOnPlane(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
void rotateVectorCenterDegree(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32);
void rotateVectorDegreeX(sead::Vector3f*, f32);
void rotateVectorDegreeY(sead::Vector3f*, f32);
void rotateVectorDegreeZ(sead::Vector3f*, f32);
void rotateVectorQuat(sead::Vector3f*, const sead::Quatf&);
}  // namespace al