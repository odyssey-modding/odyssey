#pragma once

#include "al/nerve/NerveExecutor.h"
#include "al/iuse/IUseAudioKeeper.h"
#include "al/iuse/IUseSceneCreator.h"

namespace al {
class GameSystemInfo;
class SequenceInitInfo;
class AudioSystemInfo;
class Scene;

class Sequence : public al::NerveExecutor, public al::IUseAudioKeeper, public al::IUseSceneCreator {
public:
    Sequence(const char* name);
    ~Sequence() override;
    void update();
    void kill();
    void initAudio(const al::GameSystemInfo&, const char*, int, int, int, const char*);
    void initAudioKeeper(const char*);
    void initDrawSystemInfo(const al::SequenceInitInfo&);
    al::AudioSystemInfo* getAudioSystemInfo();

    void drawMain();
    void drawSub();
    void init(const al::SequenceInitInfo&);
    bool isDisposable() { return true; }
    al::Scene* getCurrentScene();

private:

};
}  // namespace al