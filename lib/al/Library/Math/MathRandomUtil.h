#pragma once

#include <math/seadVector.h>

namespace al {
f32 getRandom();
f32 getRandom(f32);
f32 getRandom(f32, f32);
s32 getRandom(s32);
s32 getRandom(s32, s32);
f32 getRandomDegree();
f32 getRandomRadian();
sead::Vector3f getRandomVector(sead::Vector3f*, f32);
sead::Vector3f getRandomDir(sead::Vector3f*);
sead::Vector3f getRandomDirH(sead::Vector3f*, const sead::Vector3f&);
void rotateVectorDegree(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
sead::Vector2f getRandomOnCircle(sead::Vector2f*, f32);
sead::Vector2f getRandomInCircle(sead::Vector2f*, f32);
sead::Vector2f getRandomInCircleMinMaxRadius(sead::Vector2f*, f32, f32);
sead::Vector2f getRandomInCircle(sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&, f32);
sead::Vector3f getRandomOnSphere(sead::Vector3f*, f32);
sead::Vector3f getRandomInSphere(sead::Vector3f*, f32);
void calcRandomDirInCone(sead::Vector3f*, const sead::Vector3f&, f32);
void getRandomInSphereMinMaxRadius(sead::Vector3f*, f32, f32);
void initRandomSeed(u32);
void initRandomSeedByTick();
void initRandomSeedByString(const char*);
bool isHalfProbability();
bool isPercentProbability(f32);
void getRandomContext(u32*, u32*, u32*, u32*);
void setRandomContext(u32, u32, u32, u32);
void makeRandomDirXZ(sead::Vector3f*);
void calcBoxMullerRandomGauss();
void makeBoxMullerRandomGauss(sead::Vector2f*, f32, f32);
}  // namespace al