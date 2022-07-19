#pragma once

namespace al {
class EffectSystem;
class LayoutSystem;
class MessageSystem;
class NetworkSystem;
class AudioSystem;
class GamePadSystem;
class GameDrawInfo;

class GameSystemInfo {
    al::EffectSystem *mEffectSys;                  // 0x08
    al::LayoutSystem *mLayoutSys;                  // 0x10
    al::MessageSystem *mMessageSys;                // 0x18
    al::NetworkSystem *mNetworkSys;                // 0x20
    al::AudioSystem *mAudioSys;                    // 0x28
    al::GamePadSystem *mGamePadSys;                // 0x30
    al::GameDrawInfo *mDrawInfo;                   // 0x38 from Application::sInstance + 0x30
    void* *mProjNfpDirector;          // 0x48
    al::HtmlViewer *mHtmlViewer;                   // 0x50
    void* *mMessageReciever;  // 0x58
    al::WaveVibrationHolder *mWaveVibrationHolder; // 0x60
};

}