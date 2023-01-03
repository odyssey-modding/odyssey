#pragma once

#include <al/Library/HostIO/IUseName.h>

namespace al {
class LayoutKeeper;

class IUseLayout : virtual public al::IUseName {
public:
    virtual al::LayoutKeeper* getLayoutKeeper() const = 0;
};
}
