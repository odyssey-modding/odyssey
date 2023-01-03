#pragma once

#include <al/Library/Rail/IUseRail.h>

namespace al {
class RailRider;

class RailKeeper {
private:
    al::RailRider* mRailRider;

public:
    virtual al::RailRider* getRailRider() const;
};
};  // namespace al
