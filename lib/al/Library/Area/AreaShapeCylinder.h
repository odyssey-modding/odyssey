#pragma once

#include "al/Library/Area/AreaShape.h"

namespace al {

class AreaShapeCylinder : public al::AreaShape {
public:
    enum class OriginType { Center, Base, Top };

private:
    AreaShapeCylinder::OriginType mOriginType;

public:
    AreaShapeCylinder(al::AreaShapeCylinder::OriginType);

    bool isInVolume(const sead::Vector3f&) const override;
    bool isInVolumeOffset(const sead::Vector3f&, f32) const override;
    bool calcNearestEdgePoint(sead::Vector3f*, const sead::Vector3f&) const override;
    bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&) const override;
    bool calcLocalBoundingBox(sead::BoundBox3f*) const override;
};

class AreaShapeCylinderBase : public al::AreaShapeCylinder {
public:
    AreaShapeCylinderBase() : AreaShapeCylinder(AreaShapeCylinder::OriginType::Base) {}
};

class AreaShapeCylinderCenter : public al::AreaShapeCylinder {
public:
    AreaShapeCylinderCenter() : AreaShapeCylinder(AreaShapeCylinder::OriginType::Center) {}
};

class AreaShapeCylinderTop : public al::AreaShapeCylinder {
public:
    AreaShapeCylinderTop() : AreaShapeCylinder(AreaShapeCylinder::OriginType::Top) {}
};

}  // namespace al
