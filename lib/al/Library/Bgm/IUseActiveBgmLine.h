#pragma once

namespace al {
class BgmLine;

class IUseActiveBgmLine {
    virtual al::BgmLine* getActiveBgmLine() const = 0;
};
}  // namespace al
