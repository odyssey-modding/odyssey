#pragma once

#include <al/Library/Name/IUseName.h>
#include "nn/ui2d/Layout.h"

namespace eui {
class Screen;
}

namespace al {
class LayoutResource;

class LayoutKeeper {
private:
public:
    LayoutKeeper();

    void initScreen(nn::ui2d::Layout* layout, al::LayoutResource* resource);
};

class IUseLayout : virtual public al::IUseName {
public:
    virtual al::LayoutKeeper* getLayoutKeeper() const = 0;
};
}  // namespace al
