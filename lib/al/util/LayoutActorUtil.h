#pragma once
#include "al/layout/LayoutActor.h"

namespace al {
class LayoutInitInfo;

void initLayoutActor(al::LayoutActor*, const al::LayoutInitInfo&, const char*, const char*);
void initLayoutActorLocalized(al::LayoutActor*, const al::LayoutInitInfo&, const char*,
                              const char*);
void initLayoutPartsActor(al::LayoutActor*, al::LayoutActor*, const al::LayoutInitInfo&,
                          const char*, const char*);

    void startAction(al::IUseLayoutAction* layoutActor, const char* actionName,
                     const char* paneName);
bool isActionEnd(al::IUseLayoutAction* layoutActor, const char* paneName);

void updateLayoutPaneRecursive(al::LayoutActor* layoutActor);
}  // namespace al