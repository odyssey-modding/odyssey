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

void AreaObjDirector::init(const al::AreaObjFactory* factory) {
    mFactory = factory;
    mMtxConnecterHolder = new AreaObjMtxConnecterHolder(0x100);
    s32 nFactoryEntries = mFactory->getNumFactoryEntries();
    s32 areaGroupsSize = nFactoryEntries;
    mAreaGroups = new AreaObjGroup*[areaGroupsSize];

    for (s32 i=0; i<nFactoryEntries; i++) {
        mAreaGroups[i] = nullptr;
    }
}

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

// not matching
void AreaObjDirector::placement(const al::AreaInitInfo& initInfo, s32 someNum) {
    if (someNum < 1) {
        createAreaObjGroupBuffer();
        return;
    }
    // TODO do this after createAreaObjGroup
}

// not matching
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
            al::NameToCreator<al::AreaObj* (*)(const char*)> factoryEntry = mFactory->getFactoryEntries()[j];
            if (!isEqualString(entryName, factoryEntry.mName)) {  // TODO try referencing entry name by adding negative offset to NameToEntry thingy like in the asm
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

// not matching
void AreaObjDirector::createAreaObjGroupBuffer() {

    for (s32 i = 0; i < mFactory->getNumBuffers(); i++) {
        AddBuffer* addBuffer = mFactory->getBuffer();
        s32 entryIndex = mFactory->getEntryIndex(addBuffer[i].name);
        // if (entryIndex > -1)
        //     continue;
        mAreaGroups[entryIndex] = new AreaObjGroup(addBuffer->name, addBuffer->size);
    }

    s32 areaGroupCount = 0;
    s32 areaGroupCount2 = 1;
    
    for (s32 i = 0; i < mFactory->getNumFactoryEntries(); i++) {
        if (mAreaGroups[i] == nullptr)
            continue;
        mAreaGroups[i]->createBuffer();
        areaGroupCount++;
        s32 k = i;
        for (s32 j=areaGroupCount2; j>0; j--) {
            AreaObjGroup* prevAreaObjGroup = mAreaGroups[k-1];
            if (prevAreaObjGroup == nullptr)
                break;
            AreaObjGroup* areaObjGroup = mAreaGroups[k];
            if (strcmp(areaObjGroup->getName(), prevAreaObjGroup->getName()) >= 0) {
                mAreaGroups[k-1] = areaObjGroup;
                mAreaGroups[k] = prevAreaObjGroup;
            }
            else break;
            k--;
        }
        areaGroupCount2++;
    }
    mAreaGroupCount = areaGroupCount;
}


void AreaObjDirector::placementAreaObj(const al::AreaInitInfo& initInfo) {
    PlacementInfo pInfo(initInfo);
    s32 pInfoCount = getCountPlacementInfo(pInfo);
    for (s32 j = 0; j < pInfoCount; j++) {
        PlacementInfo pInfo2;
        tryGetPlacementInfoByIndex(&pInfo2, pInfo, j);
        const char* pInfoName = nullptr;
        tryGetObjectName(&pInfoName, pInfo2);

        AreaObj* (*creatorFunc)(const char*) = mFactory->getCreationFunction(pInfoName);
        if (creatorFunc == nullptr) continue;

        const char* displayName;
        getDisplayName(&displayName, pInfo2);
        AreaObj* areaObj = creatorFunc(displayName);

        AreaInitInfo initInfo2(pInfo2, initInfo);

        areaObj->init(initInfo2);
        AreaObjGroup* areaGroup = nullptr;
        s32 upper = mAreaGroupCount;
        s32 lower = 0;
        while (lower < upper) {
            s32 i = (lower + upper)/2;
            s32 equalString = strcmp(pInfoName, mAreaGroups[i]->getName());
            if (equalString==0) {
                areaGroup = mAreaGroups[i];
                break;
            }
            else if (equalString>0) {
                lower = i + 1;
            }
            else upper = i;
        }

        areaGroup->registerAreaObj(areaObj);
        mMtxConnecterHolder->tryAddArea(areaObj, pInfo2);
    }
}

}  // namespace al