#pragma once

#include <al/Library/HostIO/IUseName.h>

namespace al {
class LayoutActionKeeper;

class IUseLayoutAction : virtual public al::IUseName {
public:
    virtual al::LayoutActionKeeper* getLayoutActionKeeper() const = 0;
};
}
