#pragma once

#include <al/Library/Yaml/ByamlIter.h>

namespace al {
class ByamlIter;

class PlacementInfo {
public:
    PlacementInfo();

    void set(const al::ByamlIter& placement_iter, const al::ByamlIter& zone_iter);

    const al::ByamlIter& getPlacementIter() const { return mPlacementIter; }
    const al::ByamlIter& getZoneIter() const { return mZoneIter; }

private:
    al::ByamlIter mPlacementIter;
    al::ByamlIter mZoneIter;
};
}
