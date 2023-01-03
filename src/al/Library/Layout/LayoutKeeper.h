#pragma once

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
}
