#pragma once

#include <basis/seadTypes.h>
#include <container/seadBuffer.h>
#include <prim/seadSafeString.h>

namespace al {
class AudioSystem;
class GamePadSystem {
private:
    int mMinControllerCount;
    int mMaxControllerCount;
    int mDisconnectTimer;
    int mDisconnectFrame;
    int mInvalidateDisconnectFrame;
    sead::Buffer<sead::WFixedSafeString<256>> mControllerNames;
    al::AudioSystem* mAudioSystem;

    bool isDisconnectPlayableImpl();

public:
    GamePadSystem();
    void changeSinglePlayMode();
    void changeMultiPlayMode(s32 minControllers, s32 maxControllers);
    bool isDisconnectPlayable();
    void update();
    void setDisconnectFrame(s32 frame);
    void setInvalidateDisconnectFrame(s32 frame);
    void setPadName(u8, const sead::WSafeString&);
    const sead::WSafeString& getPadName(u8);
    u32 getPadPlayStyle(u8);
};
}  // namespace al
