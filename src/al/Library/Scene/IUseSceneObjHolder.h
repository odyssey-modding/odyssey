#pragma once

namespace al {
class SceneObjHolder;

class IUseSceneObjHolder {
private:
    static const char* sSceneObjName;

public:
    virtual al::SceneObjHolder* getSceneObjHolder() const = 0;
};
}
