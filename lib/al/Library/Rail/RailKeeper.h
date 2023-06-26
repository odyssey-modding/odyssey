#pragma once

#include <al/Library/IUse/IUseRail.h>

namespace al {
class RailRider;

class RailKeeper {
private:
    al::RailRider* mRailRider;

public:
    virtual al::RailRider* getRailRider() const;
};
};  // namespace al
