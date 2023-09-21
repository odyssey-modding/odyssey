#pragma once

#include <prim/seadSafeString.h>

namespace al {
class ActorInitInfo;
class ActorResource;
class ByamlIter;
class LiveActor;
class ParameterIo;
class Resource;

bool isExistModelResource(const al::LiveActor*);
bool isExistAnimResource(const al::LiveActor*);
bool tryGetAnimResource(const al::LiveActor*);
bool isExistModelResourceYaml(const al::LiveActor*, const char*, const char*);
void getModelResource(const al::LiveActor*);
bool isExistAnimResourceYaml(const al::LiveActor*, const char*, const char*);
void getAnimResource(const al::LiveActor*);
bool isExistModelOrAnimResourceYaml(const al::LiveActor*, const char*, const char*);
u8* getModelResourceYaml(const al::LiveActor*, const char*, const char*);
u8* getAnimResourceYaml(const al::LiveActor*, const char*, const char*);
u8* getModelOrAnimResourceYaml(const al::LiveActor*, const char*, const char*);
u8* getMapPartsResourceYaml(const al::ActorInitInfo&, const char*);
bool tryGetMapPartsResourceYaml(const al::ActorInitInfo&, const char*);
bool tryMakeInitFileName(sead::BufferedSafeString*, const al::Resource*, const char*, const char*, const char*);
bool tryGetSuffixIter(al::ByamlIter*, const al::Resource*, const char*, const char*);
bool tryGetInitFileIterAndName(al::ByamlIter*, sead::BufferedSafeString*, const al::Resource*, const char*, const char*, const char*);
bool tryGetActorInitFileIterAndName(al::ByamlIter*, sead::BufferedSafeString*, const al::Resource*, const char*, const char*);
bool tryGetActorInitFileIter(al::ByamlIter*, const al::Resource*, const char*, const char*);
bool tryGetActorInitFileIterAndName(al::ByamlIter*, sead::BufferedSafeString*, const al::LiveActor*, const char*, const char*);
bool tryGetActorInitFileIter(al::ByamlIter*, const al::LiveActor*, const char*, const char*);
bool tryGetActorInitFileName(sead::BufferedSafeString*, const al::Resource*, const char*, const char*);
bool tryGetActorInitFileName(sead::BufferedSafeString*, al::ActorResource const*, const char*, const char*);
bool tryGetActorInitFileName(sead::BufferedSafeString*, const al::LiveActor*, const char*, const char*);
bool tryGetActorInitFileSuffixName(sead::BufferedSafeString*, const al::Resource*, const char*, const char*);
bool tryGetActorInitFileSuffixName(sead::BufferedSafeString*, const al::LiveActor*, const char*, const char*);
bool tryGetActorInitFileSuffixName(const al::LiveActor*, const char*, const char*);
bool tryGetActorInitFileSuffixName(const al::Resource*, const char*, const char*);
void initParameterIoAsActorInfo(al::ParameterIo*, const al::LiveActor*, const char*, const char*);
void initParameterIoAndLoad(al::ParameterIo*, const al::LiveActor*, const char*, const char*);
}  // namespace al