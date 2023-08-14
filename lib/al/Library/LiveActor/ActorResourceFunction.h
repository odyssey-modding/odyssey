#pragma once

#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/Resource/Resource.h>
#include <al/Library/Yaml/ByamlIter.h>
#include <prim/seadSafeString.h>

namespace al {
class ParameterIo;
class ActorResource;

bool isExistModelResource(al::LiveActor const*);
bool isExistAnimResource(al::LiveActor const*);
bool tryGetAnimResource(al::LiveActor const*);
bool isExistModelResourceYaml(al::LiveActor const*, char const*, char const*);
void getModelResource(al::LiveActor const*);
bool isExistAnimResourceYaml(al::LiveActor const*, char const*, char const*);
void getAnimResource(al::LiveActor const*);
bool isExistModelOrAnimResourceYaml(al::LiveActor const*, char const*, char const*);
u8* getModelResourceYaml(al::LiveActor const*, char const*, char const*);
u8* getAnimResourceYaml(al::LiveActor const*, char const*, char const*);
u8* getModelOrAnimResourceYaml(al::LiveActor const*, char const*, char const*);
u8* getMapPartsResourceYaml(al::ActorInitInfo const&, char const*);
bool tryGetMapPartsResourceYaml(al::ActorInitInfo const&, char const*);
bool tryMakeInitFileName(sead::BufferedSafeStringBase<char>*, al::Resource const*, char const*, char const*, char const*);
bool tryGetSuffixIter(al::ByamlIter*, al::Resource const*, char const*, char const*);
bool tryGetInitFileIterAndName(al::ByamlIter*, sead::BufferedSafeStringBase<char>*, al::Resource const*, char const*, char const*, char const*);
bool tryGetActorInitFileIterAndName(al::ByamlIter*, sead::BufferedSafeStringBase<char>*, al::Resource const*, char const*, char const*);
bool tryGetActorInitFileIter(al::ByamlIter*, al::Resource const*, char const*, char const*);
bool tryGetActorInitFileIterAndName(al::ByamlIter*, sead::BufferedSafeStringBase<char>*, al::LiveActor const*, char const*, char const*);
bool tryGetActorInitFileIter(al::ByamlIter*, al::LiveActor const*, char const*, char const*);
bool tryGetActorInitFileName(sead::BufferedSafeStringBase<char>*, al::Resource const*, char const*, char const*);
bool tryGetActorInitFileName(sead::BufferedSafeStringBase<char>*, al::ActorResource const*, char const*, char const*);
bool tryGetActorInitFileName(sead::BufferedSafeStringBase<char>*, al::LiveActor const*, char const*, char const*);
bool tryGetActorInitFileSuffixName(sead::BufferedSafeStringBase<char>*, al::Resource const*, char const*, char const*);
bool tryGetActorInitFileSuffixName(sead::BufferedSafeStringBase<char>*, al::LiveActor const*, char const*, char const*);
bool tryGetActorInitFileSuffixName(al::LiveActor const*, char const*, char const*);
bool tryGetActorInitFileSuffixName(al::Resource const*, char const*, char const*);
void initParameterIoAsActorInfo(al::ParameterIo*, al::LiveActor const*, char const*, char const*);
void initParameterIoAndLoad(al::ParameterIo*, al::LiveActor const*, char const*, char const*);
}  // namespace al