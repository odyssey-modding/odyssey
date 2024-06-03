#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>
#include "al/Library/Area/AreaObjGroup.h"

namespace al {
class AreaObjFactory;
class AreaObjMtxConnecterHolder;
class AreaObj;
class AreaInitInfo;

class AreaObjDirector {
private:
    const al::AreaObjFactory* mFactory = nullptr;
    al::AreaObjMtxConnecterHolder* mMtxConnecterHolder = nullptr;
    al::AreaObjGroup** mAreaGroups = nullptr;
    s32 mAreaGroupCount = 0;

    al::AreaObjGroup* _getAreaObjGroup(const char* name) const {
        s32 lower = 0;
        s32 upper = mAreaGroupCount;
        while (lower < upper) {
            s32 i = (lower + upper) / 2;
            s32 equalString = strcmp(name, mAreaGroups[i]->getName());
            if (equalString == 0) {
                return mAreaGroups[i];
            } else if (equalString > 0) {
                lower = i + 1;
            } else
                upper = i;
        }
        return nullptr;
    }

public:
    AreaObjDirector();
    void init(const al::AreaObjFactory* factory);
    void endInit();
    void update();
    void placement(const al::AreaInitInfo& initInfo);
    void placement(const al::AreaInitInfo* initInfoArray, s32 initInfoCount);
    void createAreaObjGroup(const al::AreaInitInfo& initInfo);
    void createAreaObjGroupBuffer();
    void placementAreaObj(const al::AreaInitInfo& initInfo);
    al::AreaObjGroup* getAreaObjGroup(const char* name) const;
    bool isExistAreaGroup(const char* name) const;
    al::AreaObj* getInVolumeAreaObj(const char* name, const sead::Vector3f& position);
    al::AreaObjMtxConnecterHolder* getMtxConnecterHolder() const;
};

class IUseAreaObj {
public:
    virtual AreaObjDirector* getAreaObjDirector() const = 0;
};

}  // namespace al
