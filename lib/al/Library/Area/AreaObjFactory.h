#pragma once

#include "al/Library/Factory/Factory.h"

namespace al {

class AreaObj;

using AreaObjCreatorFunction = al::AreaObj* (*)(const char*);

struct AreaGroupInfo {
    const char* name;
    s32 size;
};

class AreaObjFactory : public al::Factory<AreaObjCreatorFunction> {
private:
    AreaGroupInfo* mAreaGroupInfo = nullptr;
    s32 mNumBuffers = 0;

public:
    AreaObjFactory(const char* factoryName);
    // inline AreaObjFactory(const char* factoryName, al::NameToCreator<AreaObjCreatorFunction> (&entries)[0x7e]) : Factory<AreaObjCreatorFunction>(factoryName){ initFactory(entries);}
    // inline AreaObjFactory(const char* factoryName, al::NameToCreator<AreaObjCreatorFunction> (&entries)[0x7e]) : Factory<AreaObjCreatorFunction>(factoryName, entries){}
    // inline AreaObjFactory(const char* factoryName, al::NameToCreator<AreaObjCreatorFunction> (&entries)[0x7e], AreaGroupInfo* areaGroupInfo) : Factory<AreaObjCreatorFunction>(factoryName, entries), mAreaGroupInfo(areaGroupInfo) {}
    // inline AreaObjFactory(const char* factoryName, al::NameToCreator<AreaObjCreatorFunction> (&entries)[0x7e], AreaGroupInfo* areaGroupInfo, s32 nBuffers) : Factory<AreaObjCreatorFunction>(factoryName, entries), mAreaGroupInfo(areaGroupInfo), mNumBuffers(nBuffers) {}
    s32 tryFindAddBufferSize(const char* bufferName) const;

    AreaGroupInfo* getAreaGroupInfo() const { return mAreaGroupInfo; };
    s32 getAreaGroupCount() const { return mNumBuffers; };

    template <s32 N>
    void setAreaGroupInfo(AreaGroupInfo (&areaInfo)[N]) {
        mNumBuffers = N;
        mAreaGroupInfo = areaInfo;
    }
};

} // namespace al