#pragma once

#include <basis/seadTypes.h>

namespace al {
class LiveActor;
class Resource;

class ActorParamHolder {
private:
public:
    static const char* getYamlName();
    static ActorParamHolder* tryCreate(al::LiveActor* actor, const al::Resource* resource, const char* suffix);

    f32 findParamF32(const char* );
private:
    ActorParamHolder(al::LiveActor* actor, const al::Resource* resource, const char* suffix);
};
}  // namespace al
