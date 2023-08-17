#include "al/Library/Area/AreaShape.h"
#include <math/seadVector.h>
#include "al/Library/Area/AreaShapeCube.h"
#include "al/Library/Area/AreaShapeCylinder.h"
#include "al/Library/Area/AreaShapeInfinite.h"
#include "al/Library/Area/AreaShapeSphere.h"
#include "al/Library/Math/MathAngleUtil.h"
#include "al/Library/Math/MathLengthUtil.h"
#include "al/Library/Matrix/MatrixUtil.h"

namespace al {
AreaShape::AreaShape() {}

void AreaShape::setBaseMtxPtr(const sead::Matrix34f* baseMtxPtr) {
    mBaseMtxPtr = baseMtxPtr;
}

void AreaShape::setScale(const sead::Vector3f& scale) {
    mScale = scale;
}

bool AreaShape::calcLocalPos(sead::Vector3f* localPos, const sead::Vector3f& trans) const {
    if (al::isNearZeroOrLess(mScale.x, 0.001))
        return false;
    if (al::isNearZeroOrLess(mScale.y, 0.001))
        return false;
    if (al::isNearZeroOrLess(mScale.z, 0.001))
        return false;

    if (mBaseMtxPtr)
        al::calcMtxLocalTrans(localPos, *mBaseMtxPtr, trans);
    else
        localPos->e = trans.e;

    auto localX = localPos->x;
    localPos->x = localX / mScale.x;
    auto localY = localPos->y;
    localPos->y = localY / mScale.y;
    auto localZ = localPos->z;
    localPos->z = localZ / mScale.z;

    return true;
}

bool AreaShape::calcWorldPos(sead::Vector3f* worldPos, const sead::Vector3f& trans) const {
    if (al::isNearZero(mScale.x, 0.001f))
        return false;
    if (al::isNearZero(mScale.y, 0.001f))
        return false;
    if (al::isNearZero(mScale.z, 0.001f))
        return false;

    worldPos->x = trans.x * mScale.x;
    worldPos->y = trans.y * mScale.y;
    worldPos->z = trans.z * mScale.z;

    if (mBaseMtxPtr)
        worldPos->setMul(*mBaseMtxPtr, *worldPos);

    return true;
}

bool AreaShape::calcWorldDir(sead::Vector3f* worldDir, const sead::Vector3f& trans) const {
    if (al::isNearZero(mScale.x, 0.001f))
        return false;
    if (al::isNearZero(mScale.y, 0.001f))
        return false;
    if (al::isNearZero(mScale.z, 0.001f))
        return false;

    worldDir->x = trans.x * mScale.x;
    worldDir->y = trans.y * mScale.y;
    worldDir->z = trans.z * mScale.z;

    if (mBaseMtxPtr)
        worldDir->setRotated(*mBaseMtxPtr, *worldDir);

    al::tryNormalizeOrZero(worldDir);

    return true;
}

void AreaShape::calcTrans(sead::Vector3f* trans) const {
    if (mBaseMtxPtr) {
        mBaseMtxPtr->getTranslation(*trans);
    } else {
        trans->e = sead::Vector3f::zero.e;
    }
}

template <typename T>
al::AreaShape* createAreaShapeFunction() {
    return new T;
}

static al::NameToCreator<AreaShapeCreatorFunction> sAreaShapeEntries[] = {
    {"AreaCubeBase", *al::createAreaShapeFunction<al::AreaShapeCubeBase>},
    {"AreaCubeCenter", al::createAreaShapeFunction<al::AreaShapeCubeCenter>},
    {"AreaCubeTop", al::createAreaShapeFunction<al::AreaShapeCubeTop>},
    {"AreaSphere", al::createAreaShapeFunction<al::AreaShapeSphere>},
    {"AreaCylinder", al::createAreaShapeFunction<al::AreaShapeCylinderBase>},
    {"AreaCylinderCenter", al::createAreaShapeFunction<al::AreaShapeCylinderCenter>},
    {"AreaCylinderTop", al::createAreaShapeFunction<al::AreaShapeCylinderTop>},
    {"AreaInfinite", al::createAreaShapeFunction<al::AreaShapeInfinite>},
};

AreaShapeFactory::AreaShapeFactory(const char* factoryName) : Factory<al::AreaShape* (*)()>(factoryName, sAreaShapeEntries) {}

}  // namespace al
