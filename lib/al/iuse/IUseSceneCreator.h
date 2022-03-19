#pragma once

#include "al/scene/SceneCreator.h"

namespace al {
class IUseSceneCreator {
public:
    virtual ~IUseSceneCreator();
    
    virtual void setSceneCreator(SceneCreator* creator) const = 0;
    virtual SceneCreator* getSceneCreator() const = 0;
};
}  // namespace al
