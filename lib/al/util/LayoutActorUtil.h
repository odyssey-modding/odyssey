#pragma once
#include "al/layout/LayoutActor.h"

namespace al {
void startAction(al::IUseLayoutAction* layoutActor, const char* actionName, const char* paneName);
bool isActionEnd(al::IUseLayoutAction* layoutActor, const char* actionName);

void updateLayoutPaneRecursive(al::LayoutActor* layoutActor);
}