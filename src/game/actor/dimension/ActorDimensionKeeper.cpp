#include "game/actor/dimension/ActorDimensionKeeper.h"
#include "game/actor/dimension/In2DAreaMoveControl.h"

void ActorDimensionKeeper::validate() {
    isValid = true;
}

void ActorDimensionKeeper::invalidate() {
    isValid = false;

    if (is2D) {
        is2D = false;
        isIn2DArea = false;
        isCurrently2D = false;
        isCanChange3D = true;
    }
}
