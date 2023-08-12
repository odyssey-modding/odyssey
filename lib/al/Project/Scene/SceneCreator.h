#pragma once

#include <heap/seadHeap.h>
namespace alSceneFunction {
class SceneFactory;
}
namespace al {
struct GameSystemInfo;
class GameDataHolderBase;
class ScreenCaptureExecutor;
class InitializeThread;
class AudioDirector;
class Scene;
class SceneCreator {
private:
    al::GameSystemInfo* mGameSystemInfo;
    al::GameDataHolderBase* mGameDataHolder;
    al::ScreenCaptureExecutor* mScreenCaptureExecutor;
    alSceneFunction::SceneFactory* mSceneFactory;
    al::InitializeThread* mInitializeThread;
    al::AudioDirector* mAudioDirector;

public:
    SceneCreator(const al::GameSystemInfo*, al::GameDataHolderBase*, al::ScreenCaptureExecutor*, alSceneFunction::SceneFactory*, al::AudioDirector*);
    void createScene(const char*, const char*, s32, const char*, bool, s32);
    void setSceneAndThreadInit(al::Scene*, const char*, s32, const char*, s32, sead::Heap*);
    void setSceneAndInit(al::Scene*, const char*, s32, const char*);
    bool tryEndInitThread();
    bool isExistInitThread();
};

class IUseSceneCreator {
public:
    virtual ~IUseSceneCreator();
    virtual SceneCreator* getSceneCreator() const = 0;
    virtual void setSceneCreator(SceneCreator*) = 0;
};
}  // namespace al
