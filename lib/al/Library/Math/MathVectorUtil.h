#pragma once

#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {
void separateScalarAndDirection(f32*, sead::Vector2f*, const sead::Vector2f &);
void separateScalarAndDirection(f32*, sead::Vector3f*, const sead::Vector3f&);
void limitVectorSeparateHV(sead::Vector3f*, const sead::Vector3f&, f32, f32);
void parallelizeVec(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void calcVectorSeparateHV(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32, f32);
void limitVectorParallelVertical(sead::Vector3f*, const sead::Vector3f&, f32, f32);
void separateVectorParallelVertical(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void addVectorLimit(sead::Vector3f*, const sead::Vector3f&, f32);
void alongVectorNormalH(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void calcDistanceVecToPlane(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void limitPlanePos(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void limitCylinderInPos(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32);
void limitCylinderInDir(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void limitCylinderInPos(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
void limitCylinderInDir(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void roundOffVec(sead::Vector3f*, const sead::Vector3f&);
void roundOffVec(sead::Vector3f*);
void roundOffVec(sead::Vector2f*, const sead::Vector2f &);
void roundOffVec(sead::Vector2f*);
void snapToGrid(f32, f32, f32);
void snapVecToGrid(sead::Vector3f*, const sead::Vector3f&, f32, const sead::Vector3f&);
void snapVecToGrid(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void limitVectorOppositeDir(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
void scaleVectorDirection(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
void scaleVectorExceptDirection(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
void snapVecToDirAxisY(sead::Vector3f*, const sead::Vector3f&, s32);
void calcDir(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void calcDirH(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void calcDirOnPlane(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void mapRangeLogarithmic(f32, f32, f32, f32, f32, f32);
void calcDirFromLongitudeLatitude(sead::Vector3f*, f32, f32);
void calcLongitudeLatitudeFromDir(f32*, f32*, const sead::Vector3f&);
void getMaxAbsElementIndex(const sead::Vector3i&);
void getMaxAbsElementValue(const sead::Vector3f&);
void getMaxAbsElementValue(const sead::Vector3i&);
void getMinAbsElementIndex(const sead::Vector3f&);
void getMinAbsElementIndex(const sead::Vector3i&);
void getMinAbsElementValue(const sead::Vector3f&);
void getMinAbsElementValue(const sead::Vector3i&);
void calcNearVecFromAxis2(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void calcNearVecFromAxis3(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void calcDirVerticalAny(sead::Vector3f*, const sead::Vector3f&);
void calcDirSlide(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void calcNearVecFromAxis3(sead::Vector3f*, const sead::Vector3f&, const sead::Quatf&);
void calcQuatLocalAxisAll(const sead::Quatf&, sead::Vector3f*, sead::Vector3f*, sead::Vector3f*);
void addRandomVector(sead::Vector3f*, const sead::Vector3f&, f32);
void turnRandomVector(sead::Vector3f*, const sead::Vector3f&, f32);
void makeAxisFrontUp(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void makeAxisFrontSide(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void makeAxisUpFront(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void makeAxisUpSide(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
}  // namespace al