#include "ActorClippingFunction.h"
#include <al/Library/LiveActor/LiveActor.h>

namespace al {
bool isClipped(const al::LiveActor* actor) {
    return actor->getFlags()->isClipped;
}
bool isInvalidClipping(const al::LiveActor* actor) {
    return actor->getFlags()->isClippingInvalid;
}
}  // namespace al
namespace alActorFunction {
bool isDrawClipping(const al::LiveActor* actor) {
    actor->getFlags()->isDrawClipped;
}
};  // namespace alActorFunction
