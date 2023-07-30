#pragma once

#include <al/Library/Audio/AudioKeeper.h>
#include <al/Library/Nerve/NerveExecutor.h>
#include <al/Library/System/GameSystemInfo.h>
#include <al/Project/Scene/SceneCreator.h>
#include <prim/seadSafeString.h>

namespace al {
class GameSystemInfo;
class SequenceInitInfo;
class AudioSystemInfo;
class AudioDirector;
class Scene;

class Sequence : public al::NerveExecutor, public al::IUseAudioKeeper, public al::IUseSceneCreator {
    sead::FixedSafeString<0x40> mName;
    al::Scene* mNextScene;
    al::Scene* mCurrentScene;
    al::SceneCreator* mSceneCreator;
    al::AudioDirector* mAudioDirector;
    al::AudioKeeper* mAudioKeeper;
    al::GameDrawInfo* mGameDrawInfo;
    bool mIsAlive;

public:
    Sequence(const char* name);
    virtual ~Sequence() override;
    virtual void init(const al::SequenceInitInfo& initInfo);
    virtual void update();
    virtual void kill();
    virtual void drawMain() const;
    virtual void drawSub() const;
    virtual bool isDisposable() { return false; }
    virtual al::Scene* getCurrentScene() const;
    virtual al::SceneCreator* getSceneCreator() const override;
    virtual void setSceneCreator(al::SceneCreator* sceneCreator) override;

    void initAudio(const al::GameSystemInfo&, const char*, s32, s32, s32, const char*);
    void initAudioKeeper(const char*);
    void initDrawSystemInfo(const al::SequenceInitInfo& initInfo);

    al::AudioKeeper* getAudioKeeper() const override;
    al::AudioSystemInfo* getAudioSystemInfo();

protected:
    al::GameDrawInfo* getDrawInfo() const { return mGameDrawInfo; }
};
}  // namespace al
