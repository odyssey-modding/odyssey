#include "al/layout/LayoutPartsActorKeeper.h"
#include "al/layout/LayoutActor.h"

namespace al {

void LayoutPartsActorKeeper::appear() {
    for (auto &item : mPartsActors) {
        item.appear();
    }
}
}  // namespace al