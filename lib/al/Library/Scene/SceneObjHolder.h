#pragma once

#include <basis/seadTypes.h>

namespace al {
struct ActorInitInfo;
class ISceneObj;

class SceneObjHolder {
private:
    al::ISceneObj* (*mCreator)(s32);
    al::ISceneObj** mSceneObjArray;
    s32 mArraySize;

public:
    SceneObjHolder(al::ISceneObj* (*)(s32), s32);
    al::ISceneObj* create(s32);
    al::ISceneObj* tryGetObj(s32) const;
    al::ISceneObj* getObj(s32) const;
    bool isExist(s32) const;
    void setSceneObj(al::ISceneObj*, s32);
    void initAfterPlacementSceneObj(const al::ActorInitInfo&);
};

class IUseSceneObjHolder {
public:
    virtual SceneObjHolder* getSceneObjHolder() const = 0;
};
}  // namespace al
