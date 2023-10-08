#pragma once

#include <math/seadVector.h>

namespace al {
f32 calcAngleRadian(const sead::Vector3f&, const sead::Vector3f&);
f32 calcAngleDegree(const sead::Vector3f&, const sead::Vector3f&);
f32 calcAngleDegree(const sead::Vector2f&, const sead::Vector2f&);
bool isNearZero(const sead::Vector2f&, f32);
bool tryCalcAngleDegree(f32*, const sead::Vector3f&, const sead::Vector3f&);
bool isNearZero(const sead::Vector3f&, f32);
void calcAngleOnPlaneRadian(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void verticalizeVec(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
void calcAngleOnPlaneDegree(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
void calcAngleOnPlaneDegreeOrZero(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
bool tryCalcAngleOnPlaneDegree(f32*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
bool isParallelDirection(const sead::Vector3f&, const sead::Vector3f&, f32);
void calcAngleSignOnPlane(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
bool isNearAngleRadian(const sead::Vector2f&, const sead::Vector2f&, f32);
void normalize(sead::Vector2f*, const sead::Vector2f&);
bool isNearAngleRadian(const sead::Vector3f&, const sead::Vector3f&, f32);
void normalize(sead::Vector3f*, const sead::Vector3f&);
bool isNearAngleDegree(const sead::Vector2f&, const sead::Vector2f&, f32);
bool isNearAngleDegree(const sead::Vector3f&, const sead::Vector3f&, f32);
bool isNearAngleRadianHV(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32, f32);
bool tryNormalizeOrZero(sead::Vector3f*, const sead::Vector3f&);
bool tryNormalizeOrZero(sead::Vector3f*);
bool isNearAngleDegreeHV(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32, f32);
bool isInAngleOnPlaneDegreeHV(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32, f32, f32, f32);
}  // namespace al
