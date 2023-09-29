#pragma once

#include <container/seadPtrArray.h>

namespace al {
class IAudioSystemPause {
    virtual void pauseSystem(bool, const char*, bool, f32, bool, bool, bool) = 0;
};

class AudioSystemPauseController {
private:
    sead::PtrArray<al::IAudioSystemPause> mPauseHandlers;

public:
    enum class AudioSystemPauseType {
        cWarning,
        cSystemPause,
        cDebugPause,
        cControllerSupportApplet,
        cErrorWindow,
        cSoundSyncPause,
    };

    static const char* getAudioSystemPauseTypeName(AudioSystemPauseType);
    static AudioSystemPauseType getAudioSystemPauseType(const char* typeName);

    AudioSystemPauseController();
    void regist(al::IAudioSystemPause*);
    void unregist(al::IAudioSystemPause*);
    void pauseSystem(bool, const char*, bool, f32);
};
}  // namespace al
