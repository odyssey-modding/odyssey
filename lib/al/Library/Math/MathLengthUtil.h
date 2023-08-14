#pragma once

#include <cmath>
#include <gfx/seadColor.h>
#include <math/seadMathCalcCommon.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
bool isNear(f32, f32, f32);
bool isNear(const sead::Vector2f&, const sead::Vector2f&, f32);
bool isNear(const sead::Vector3f&, const sead::Vector3f&, f32);
bool isNear(const sead::Color4f&, const sead::Color4f&, f32);
bool isNearZero(f32, f32);
bool isNearZero(const sead::Matrix34<f32>&, f32);
bool isNearZeroOrGreater(f32, f32);
bool isNearZeroOrLess(f32, f32);
bool isExistNearZeroVal(const sead::Vector3f&, f32);
bool isNormalize(const sead::Vector3f&, f32);
bool isNormalize(const sead::Matrix34<f32>&);
bool isParallelDirection(const sead::Vector2f&, const sead::Vector2f&, f32);
bool isReverseDirection(const sead::Vector3f&, const sead::Vector3f&, f32);
bool isNearDirection(const sead::Vector2f&, const sead::Vector2f&, f32);
bool isNearDirection(const sead::Vector3f&, const sead::Vector3f&, f32);
bool isInRange(s32, s32, s32);
bool isInRange(f32, f32, f32);
void normalize(sead::Vector2f*);
void normalize(sead::Vector3f*);
void normalize(sead::Matrix33<f32>*);
void normalize(sead::Matrix34<f32>*);
bool tryNormalizeOrZero(sead::Vector2f*);
bool tryNormalizeOrZero(sead::Vector2f*, const sead::Vector2f&);
bool tryNormalizeOrDirZ(sead::Vector3f*);
bool tryNormalizeOrDirZ(sead::Vector3f*, const sead::Vector3f&);
void normalizeComplement(sead::Matrix34<f32>*);
s32 getMaxAbsElementIndex(const sead::Vector3f&);
void setLength(sead::Vector3f*, f32);
void setProjectionLength(sead::Vector3f*, const sead::Vector3f&, f32);
void limitLength(sead::Vector2f*, const sead::Vector2f&, f32);
void limitLength(sead::Vector3f*, const sead::Vector3f&, f32);
f32 normalizeAbs(f32, f32, f32);
f32 normalize(f32, f32, f32);
f32 normalize(s32, s32, s32);
f32 sign(f32);
s32 sign(s32);
void cubeRoot(f32);
void clampV3f(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void clampV2f(sead::Vector2f*, const sead::Vector2f&, const sead::Vector2f&);
}  // namespace al