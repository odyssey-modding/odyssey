#pragma once

#include "System/GameDataHolderWriter.h"

namespace al {
    class IUseSceneObjHolder;
    class SceneObjHolder;
} // namespace al

class GameDataHolderAccessor : public GameDataHolderWriter
{
public:
    GameDataHolderAccessor(const al::IUseSceneObjHolder* iUseSceneObjHolder);
    GameDataHolderAccessor(const al::SceneObjHolder* objHolder);
};