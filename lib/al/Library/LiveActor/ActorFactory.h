#pragma once

#include <al/Library/Factory/Factory.h>

namespace al {
class LiveActor;

using ActorCreatorFunction = LiveActor* (*)(const char* actorName);

class ActorFactory : public al::Factory<ActorCreatorFunction> {
public:
    ActorFactory(const char* factoryName);
};
}  // namespace al
