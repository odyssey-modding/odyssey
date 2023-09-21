#pragma once

#include "al/Library/Area/AreaShape.h"

namespace al {

class AreaShapeCube : public al::AreaShape {
public:
    enum class OriginType { Center, Base, Top };

private:
    AreaShapeCube::OriginType mOriginType;

public:
    AreaShapeCube(al::AreaShapeCube::OriginType);

    bool isInVolume(const sead::Vector3f&) const override;
    bool isInVolumeOffset(const sead::Vector3f&, f32) const override;
    bool calcNearestEdgePoint(sead::Vector3f*, const sead::Vector3f&) const override;
    bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&) const override;
    bool calcLocalBoundingBox(sead::BoundBox3f*) const override;

    bool isInLocalVolume(const sead::Vector3f&) const;
};

class AreaShapeCubeBase : public al::AreaShapeCube {
public:
    AreaShapeCubeBase() : AreaShapeCube(AreaShapeCube::OriginType::Base) {}
};

class AreaShapeCubeCenter : public al::AreaShapeCube {
public:
    AreaShapeCubeCenter() : AreaShapeCube(AreaShapeCube::OriginType::Center) {}
};

class AreaShapeCubeTop : public al::AreaShapeCube {
public:
    AreaShapeCubeTop() : AreaShapeCube(AreaShapeCube::OriginType::Top) {}
};

}  // namespace al
