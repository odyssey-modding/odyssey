#pragma once

#include "NerveSetupUtil.h"

namespace al {
class NerveKeeper;

class Nerve {
public:
    virtual void execute(al::NerveKeeper* keeper) const = 0;
    virtual void executeOnEnd(al::NerveKeeper* keeper) const;
};
}  // namespace al
