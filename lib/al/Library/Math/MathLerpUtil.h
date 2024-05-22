#pragma once

#include <gfx/seadColor.h>
#include <math/seadVector.h>

namespace al {
f32 easeIn(f32);
f32 easeOut(f32);
f32 easeInOut(f32);
f32 squareIn(f32);
f32 squareOut(f32);
f32 powerIn(f32, f32);
f32 powerOut(f32, f32);
f32 logarithmIn(f32, f32);
f32 logarithmOut(f32, f32);
f32 exponentIn(f32, f32);
f32 exponentOut(f32, f32);
f32 hermiteRate(f32, f32, f32);
f32 calcFourthOrderRate(f32, f32);
f32 calcTriangleWave01(f32, f32);
f32 calcTriangleWave(f32, f32, f32, f32);
f32 lerpValue(f32, f32, f32);
f32 calcRate01(f32, f32, f32);
f32 easeByType(f32, s32);
f32 lerpValue(f32, f32, f32, f32, f32);
f32 lerpDegree(f32, f32, f32);
f32 lerpRadian(f32, f32, f32);
f32 lerpVec(sead::Vector2f*, const sead::Vector2f&, const sead::Vector2f&, f32);
f32 lerpVec(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
f32 lerpVecHV(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32, f32);
f32 separateVectorHV(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
f32 lerpColor(sead::Color4f*, const sead::Color4f&, const sead::Color4f&, f32);
f32 lerpLogValueEaseIn(f32, f32, f32, f32);
f32 lerpLogValueEaseOut(f32, f32, f32, f32);
f32 lerpLogVecEaseIn(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32, f32);
f32 lerpLogVecEaseOut(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32, f32);
f32 lerpExponentValueEaseIn(f32, f32, f32, f32);
f32 lerpExponentValueEaseOut(f32, f32, f32, f32);
f32 lerpExponentVecEaseIn(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32, f32);
f32 lerpExponentVecEaseOut(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32, f32);
f32 clampLeapMinAbs(f32, f32, f32, f32);
f32 hermite(f32, f32, f32, f32, f32);
f32 hermite(f32, f32, f32, f32, f32, f32);
f32 hermiteVec(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32);
f32 converge(s32, s32, s32);
f32 converge(f32, f32, f32);
f32 convergeDegree(f32, f32, f32);
f32 convergeRadian(f32, f32, f32);
f32 convergeVec(sead::Vector2f*, const sead::Vector2f&, const sead::Vector2f&, f32);
f32 convergeVec(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
f32 diffNearAngleDegree(f32, f32);
f32 isInRangeAngleDegree(f32, f32, f32);
f32 calcEyesAnimAngleInRange(f32*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32, f32, f32, f32);
f32 isSameSign(f32, f32);
f32 reverseBit8(u8);
f32 reverseBit16(u16);
f32 reverseBit32(u32);
f32 calcVanDerCorput(u32);
f32 calcHammersleyPoint(sead::Vector2f*, u32, u32);
f32 findMaxFromArray(const s32*, s32);
f32 separateMinMax(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&);
f32 findMinFromArray(const s32*, s32);
}  // namespace al