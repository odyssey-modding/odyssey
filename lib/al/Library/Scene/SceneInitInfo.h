#pragma once

#include <prim/seadSafeString.h>

namespace al {
    class GameSystemInfo;
    class GameDataHolderBase;
    class ScreenCaptureExecutor;
    class AudioDirector;

    class SceneInitInfo {
        const al::GameSystemInfo* mGameSystemInfo;
        al::GameDataHolderBase* mGameDataHolder;
        al::ScreenCaptureExecutor* mScreenCaptureExecutor;
        const char* field_18;
        int mScenarioNo; // guess
        sead::FixedSafeString<512> mName;
        al::AudioDirector* mAudioDirector;

    public:
        SceneInitInfo(const al::GameSystemInfo* gameSystemInfo, al::GameDataHolderBase* gameDataHolder,
                      al::ScreenCaptureExecutor* screenCaptureExecutor, const char*, int scenarioNo, const char* name,
                      al::AudioDirector* audioDirector);
    };
}
