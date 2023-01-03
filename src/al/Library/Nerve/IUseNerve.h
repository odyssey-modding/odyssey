#pragma once

namespace al {
class NerveKeeper;

class IUseNerve {
public:
    inline IUseNerve() {}

    virtual al::NerveKeeper* getNerveKeeper() const = 0;
};
}  // namespace al
