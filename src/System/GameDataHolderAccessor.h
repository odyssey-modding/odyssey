#pragma once

#include "GameDataHolderWriter.h"

namespace al {
    class IUseSceneObjHolder;
    class SceneObjHolder;
} // namespace al

class GameDataHolderAccessor : public GameDataHolderWriter
{
public:
    GameDataHolderAccessor(const al::IUseSceneObjHolder* IUseObjHolder);
    GameDataHolderAccessor(const al::SceneObjHolder* objHolder);
};