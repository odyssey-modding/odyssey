#pragma once

#include <math/seadBoundBox.h>
#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {
void verticalizeVec(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void parallelizeVec(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);

bool normalize(f32 value);
bool normalize(sead::Vector2f* value);
bool normalize(sead::Vector3f* value);
bool normalize(sead::Matrix33f* value);
bool normalize(sead::Matrix34f* value);

bool isNear(f32 value, f32 target, f32 tolerance);
bool isNear(const sead::Vector2f& value, const sead::Vector2f& target, f32 tolerance);
bool isNear(const sead::Vector3f& value, const sead::Vector3f& target, f32 tolerance);
bool isNear(const sead::Matrix34f& value, const sead::Matrix34f& target, f32 tolerance);
bool isNearZero(f32 value, f32 tolerance);
bool isNearZero(const sead::Vector2f& value, f32 tolerance);
bool isNearZero(const sead::Vector3f& value, f32 tolerance);
bool isNearZero(const sead::Matrix34f& value, f32 tolerance);
bool isNearZeroOrGreater(f32 value, f32 tolerance);
bool isNearZeroOrLess(f32 value, f32 tolerance);
bool isParallelDirection(const sead::Vector3f& dir1, sead::Vector3f const& dir2, float tolerance);
bool isReverseDirection(const sead::Vector3f& dir1, sead::Vector3f const& dir2, float tolerance);

bool tryNormalizeOrZero(sead::Vector3f* out, const sead::Vector3f& in);
bool tryNormalizeOrZero(sead::Vector3f* out);

f32 modf(f32 a, f32 b);

void calcQuatSide(sead::Vector3f* out, const sead::Quatf& quat);
void calcQuatUp(sead::Vector3f* out, const sead::Quatf& quat);
void calcQuatGravity(sead::Vector3f* out, const sead::Quatf& quat);
void calcQuatFront(sead::Vector3f* out, const sead::Quatf& quat);

void makeMtxRotateTrans(sead::Matrix34f* out, const sead::Vector3f& rotate, const sead::Vector3f& trans);
void makeMtxFrontUpPos(sead::Matrix34f* out, const sead::Vector3f& front, const sead::Vector3f& up, const sead::Vector3f& pos);
void makeMtxUpFrontPos(sead::Matrix34f* out, const sead::Vector3f& up, const sead::Vector3f& front, const sead::Vector3f& pos);
void makeMtxSideFrontPos(sead::Matrix34f* out, const sead::Vector3f& side, const sead::Vector3f& front, const sead::Vector3f& pos);
void makeQuatAxisRotation(sead::Quatf* out, const sead::Vector3f& dir1, const sead::Vector3f& dir2, const sead::Vector3f& dir3, float);


void alongVectorNormalH(sead::Vector3f* out, const sead::Vector3f& param_2, const sead::Vector3f& param_3, const sead::Vector3f& param_4);

bool limitLength(sead::Vector3f* out, const sead::Vector3f& vector, float length);
void separateVectorHV(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);

void lerpVec(sead::Vector2f*, const sead::Vector2f&, const sead::Vector2f&, float);
void lerpVecHV(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, float, float);
void lerpVec(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, float);

}  // namespace al
