#pragma once

#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {
void separateScalarAndDirection(f32*, sead::Vector2f*, sead::Vector2f const&);
void separateScalarAndDirection(f32*, sead::Vector3f*, sead::Vector3f const&);
void limitVectorSeparateHV(sead::Vector3f*, sead::Vector3f const&, f32, f32);
void parallelizeVec(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
void calcVectorSeparateHV(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, f32, f32);
void limitVectorParallelVertical(sead::Vector3f*, sead::Vector3f const&, f32, f32);
void separateVectorParallelVertical(sead::Vector3f*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
void addVectorLimit(sead::Vector3f*, sead::Vector3f const&, f32);
void alongVectorNormalH(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void calcDistanceVecToPlane(sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void limitPlanePos(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void limitCylinderInPos(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, f32);
void limitCylinderInDir(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void limitCylinderInPos(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, f32);
void limitCylinderInDir(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void roundOffVec(sead::Vector3f*, sead::Vector3f const&);
void roundOffVec(sead::Vector3f*);
void roundOffVec(sead::Vector2f*, sead::Vector2f const&);
void roundOffVec(sead::Vector2f*);
void snapToGrid(f32, f32, f32);
void snapVecToGrid(sead::Vector3f*, sead::Vector3f const&, f32, sead::Vector3f const&);
void snapVecToGrid(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void limitVectorOppositeDir(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, f32);
void scaleVectorDirection(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, f32);
void scaleVectorExceptDirection(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, f32);
void snapVecToDirAxisY(sead::Vector3f*, sead::Vector3f const&, int);
void calcDir(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
void calcDirH(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
void calcDirOnPlane(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void mapRangeLogarithmic(f32, f32, f32, f32, f32, f32);
void calcDirFromLongitudeLatitude(sead::Vector3f*, f32, f32);
void calcLongitudeLatitudeFromDir(f32*, f32*, sead::Vector3f const&);
void getMaxAbsElementIndex(sead::Vector3<int> const&);
void getMaxAbsElementValue(sead::Vector3f const&);
void getMaxAbsElementValue(sead::Vector3<int> const&);
void getMinAbsElementIndex(sead::Vector3f const&);
void getMinAbsElementIndex(sead::Vector3<int> const&);
void getMinAbsElementValue(sead::Vector3f const&);
void getMinAbsElementValue(sead::Vector3<int> const&);
void calcNearVecFromAxis2(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void calcNearVecFromAxis3(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
void calcDirVerticalAny(sead::Vector3f*, sead::Vector3f const&);
void calcDirSlide(sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
void calcNearVecFromAxis3(sead::Vector3f*, sead::Vector3f const&, sead::Quatf const&);
void calcQuatLocalAxisAll(sead::Quatf const&, sead::Vector3f*, sead::Vector3f*, sead::Vector3f*);
void addRandomVector(sead::Vector3f*, sead::Vector3f const&, f32);
void turnRandomVector(sead::Vector3f*, sead::Vector3f const&, f32);
void makeAxisFrontUp(sead::Vector3f*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
void makeAxisFrontSide(sead::Vector3f*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
void makeAxisUpFront(sead::Vector3f*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
void makeAxisUpSide(sead::Vector3f*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&);
}  // namespace al