/**
 * @file IUseLayout.h
 * @brief Interface for classes that are layouts.
 */

#pragma once

#include "al/iuse/IUseName.h"
#include "al/layout/LayoutKeeper.h"

namespace al {
class IUseLayout : virtual public al::IUseName {
public:
    virtual al::LayoutKeeper* getLayoutKeeper(void) const = 0;
};
}  // namespace al