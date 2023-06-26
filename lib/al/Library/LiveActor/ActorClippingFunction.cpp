#include "ActorClippingFunction.h"

class alActorFunction {
    void invalidateFarClipping(al::LiveActor*) {

    }
    void validateFarClipping(al::LiveActor*);
    void getFarClipDistance(const al::LiveActor*);
    void isInvalidFarClipping(const al::LiveActor*);
    void isDrawClipping(const al::LiveActor*);
    void checkActiveViewGroupAny(const al::LiveActor*);
};
