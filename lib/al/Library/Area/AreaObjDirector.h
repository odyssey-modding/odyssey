#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

namespace al {
class AreaObjFactory;
class AreaObjMtxConnecterHolder;
class AreaObjGroup;
class AreaObj;
class AreaInitInfo;

class AreaObjDirector {
private:
    const al::AreaObjFactory* mFactory = nullptr;
    al::AreaObjMtxConnecterHolder* mMtxConnecterHolder = nullptr;
    al::AreaObjGroup** mAreaGroups = nullptr;
    u32 mAreaGroupCount = 0;

public:
    AreaObjDirector();
    void init(const al::AreaObjFactory* factory);
    void endInit();
    void update();
    void placement(const al::AreaInitInfo& initInfo);
    void placement(const al::AreaInitInfo& initInfo, s32);
    void createAreaObjGroup(const al::AreaInitInfo& initInfo);
    void createAreaObjGroupBuffer();
    void placementAreaObj(const al::AreaInitInfo& initInfo);
    al::AreaObjGroup* getAreaObjGroup(const char* name);
    bool isExistAreaGroup(const char* name);
    al::AreaObj* getInVolumeAreaObj(const char* name, const sead::Vector3f& position);
    al::AreaObjMtxConnecterHolder* getMtxConnecterHolder();
};

class IUseAreaObj {
public:
    virtual AreaObjDirector* getAreaObjDirector() const = 0;
};
}  // namespace al
