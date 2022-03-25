#pragma once
#include "al/layout/LayoutActor.h"

namespace al {
void startAction(al::IUseLayoutAction* layoutAction, const char* actionName, const char* paneName);
void updateLayoutPaneRecursive(al::LayoutActor* layoutActor);
}