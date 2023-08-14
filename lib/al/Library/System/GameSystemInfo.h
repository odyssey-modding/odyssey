#pragma once

#include <basis/seadTypes.h>
#include <common/aglRenderBuffer.h>

namespace al {
class EffectSystem;
class LayoutSystem;
class MessageSystem;
class NetworkSystem;
class AudioSystem;
class GamePadSystem;
class HtmlViewer;
class WaveVibrationHolder;
class FontHolder;
class NfpDirector;
class ApplicationMessageReceiver;

struct DrawSystemInfo {
    agl::RenderBuffer* mDockedRenderBuffer;
    agl::RenderBuffer* mHandheldRenderBuffer;
    bool isDocked;
    agl::DrawContext* mDrawContext;
};

struct GameSystemInfo {
    al::AudioSystem* audioSystem;
    al::EffectSystem* effectSystem;
    al::LayoutSystem* layoutSystem;
    al::MessageSystem* messageSystem;
    al::NetworkSystem* networkSystem;
    void* field_28;
    al::GamePadSystem* gamePadSystem;
    al::DrawSystemInfo* drawSystemInfo;
    al::FontHolder* fontHolder;
    al::NfpDirector* nfpDirector;
    al::HtmlViewer* htmlViewer;
    al::ApplicationMessageReceiver* applicationMessageReciever;
    al::WaveVibrationHolder* waveVibrationHolder;
};
}  // namespace al
