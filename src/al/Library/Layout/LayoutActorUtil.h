#pragma once

#include <math/seadVector.h>

namespace al {
class LayoutActor;
class IUseLayout;

bool isActive(al::LayoutActor* actor);
bool isDead(al::LayoutActor* actor);

void killLayoutIfActive(al::LayoutActor* actor);
void appearLayoutIfDead(al::LayoutActor* actor);

void calcTrans(sead::Vector3f* trans, const al::IUseLayout*);
const sead::Vector3f& getLocalTrans(const al::IUseLayout*);

void updateLayoutPaneRecursive(al::LayoutActor* actor);
}  // namespace al
