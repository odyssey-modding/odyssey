#pragma once

#include <basis/seadTypes.h>

namespace al {
class AddDemoInfo;
class ActorInitInfo;
class DemoActorHolder;
class LiveActor;
class Scene;

void registDemoRequesterToAddDemoInfo(const al::LiveActor* actor, const al::ActorInitInfo& initInfo,
                                      s32 index);
void registActorToDemoInfo(al::LiveActor* actor, const al::ActorInitInfo& initInfo);
void addDemoActorFromAddDemoInfo(const al::LiveActor* actor, const al::AddDemoInfo* info);
void addDemoActorFromDemoActorHolder(const al::LiveActor* actor, const al::DemoActorHolder* holder);
void addDemoActorFromDemoActorHolder(const al::Scene* scene, const al::DemoActorHolder* holder);
void setDemoInfoDemoName(const al::LiveActor* actor, const char* name);
void killForceBeforeDemo(al::LiveActor* actor);
void prepareSkip(al::LiveActor* actor, s32);
void invalidateLODWithSubActor(al::LiveActor*);

}  // namespace al

namespace alDemoUtilTmp {
bool isActiveDemo(al::LiveActor const*);
}
