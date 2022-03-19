#pragma once

#include "al/nerve/NerveExecutor.h"
#include "al/iuse/IUseAudioKeeper.h"
#include "al/iuse/IUseSceneCreator.h"

namespace al {
class Sequence : public al::NerveExecutor, public al::IUseAudioKeeper, public al::IUseSceneCreator {
public:
    Sequence(const char* name);
};
}  // namespace al