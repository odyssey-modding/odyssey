#include "al/Library/Area/AreaObjDirector.h"

#include "al/Library/Area/AreaInitInfo.h"
#include "al/Library/Area/AreaObj.h"
#include "al/Library/Area/AreaObjGroup.h"
#include "al/Library/Area/AreaObjMtxConnecterHolder.h"
#include "al/Library/Placement/PlacementFunction.h"
#include "al/Library/Placement/PlacementInfo.h"
#include "al/Library/String/StringUtil.h"

namespace al {

AreaObjDirector::AreaObjDirector() {}

void AreaObjDirector::init(const al::AreaObjFactory* factory) {}

void AreaObjDirector::endInit() {}

void AreaObjDirector::update() {
    if (mMtxConnecterHolder == nullptr)
        return;
    mMtxConnecterHolder->update();
}

void AreaObjDirector::placement(const al::AreaInitInfo& initInfo) {
    createAreaObjGroup(initInfo);
    createAreaObjGroupBuffer();
    placementAreaObj(initInfo);
}

void AreaObjDirector::placement(const al::AreaInitInfo& initInfo, s32 someNum) {
    if (someNum < 1) {
        createAreaObjGroupBuffer();
        return;
    }
    // TODO do this after createAreaObjGroup
}

void AreaObjDirector::createAreaObjGroup(const al::AreaInitInfo& initInfo) {
    al::PlacementInfo placementInfo(initInfo);

    s32 pInfoCount = al::getCountPlacementInfo(placementInfo);
    for (s32 i = 0; i < pInfoCount; i++) {
        al::PlacementInfo placementInfo2;
        al::tryGetPlacementInfoByIndex(&placementInfo2, placementInfo, i);
        const char* pInfoName = nullptr;
        al::tryGetObjectName(&pInfoName, placementInfo2);
        const char* entryName = mFactory->convertName(pInfoName);  // some issues here

        // unneccessary
        // if (mFactory->getNumFactoryEntries() <= 0)
        //     continue;

        for (int j = 0; j < mFactory->getNumFactoryEntries(); j++) {
            // al::AreaObj* (*)() creatorFunc = mFactory->getFactoryEntries()[j].mCreationFunction;
            al::NameToCreator<al::AreaObj* (*)()> factoryEntry = mFactory->getFactoryEntries()[j];
            if (!isEqualString(entryName, factoryEntry.mName)) {  // TODO try referencing entry name by adding negative offset to
                                                                  // NameToEntry thingy like in the asm
                continue;
            }
            if (factoryEntry.mCreationFunction != nullptr) {
                if (mAreaGroups[j] == nullptr) {
                    s32 size = mFactory->tryFindAddBufferSize(pInfoName);
                    mAreaGroups[j] = new AreaObjGroup(pInfoName, size);
                }
                mAreaGroups[j]->incrementCount();
            }
            break;
        }
    }
}

void AreaObjDirector::createAreaObjGroupBuffer() {
    for (s32 i = 0; i < mFactory->getNumBuffers(); i++) {
        AddBuffer* addBuffer = mFactory->getBuffer();
        s32 entryIndex = mFactory->getEntryIndex(addBuffer[i].name);
        if (entryIndex > -1)
            continue;
        // this is generating instructions out of order -- might be inlined?
        mAreaGroups[entryIndex] = new AreaObjGroup(addBuffer->name, addBuffer->size);
    }

    s32 areaGroupCount = 0;
    s32 j = 1;
    for (s32 i = 0; i < mFactory->getNumFactoryEntries(); i++) {
        if (mAreaGroups[i] == nullptr)
            continue;
        mAreaGroups[i]->createBuffer();
        areaGroupCount++;
        s32 k = j;
        
        // sorting alphabetically?
        while (k > 0) {
            AreaObjGroup* prevAreaObjGroup = mAreaGroups[k-1];
            AreaObjGroup* areaObjGroup;
            if (prevAreaObjGroup == nullptr) 
                areaObjGroup = mAreaGroups[k];
            else {
                areaObjGroup = mAreaGroups[k];
                if (strcmp(areaObjGroup->getName(), prevAreaObjGroup->getName()) > -1)
                    break;
            }
            mAreaGroups[k-1] = areaObjGroup;
            mAreaGroups[k] = prevAreaObjGroup;
            k--;
        }
        j++;
    }
    mAreaGroupCount = areaGroupCount;
}

}  // namespace al