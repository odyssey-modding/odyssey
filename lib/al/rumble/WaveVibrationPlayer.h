#pragma once

namespace nn {
namespace hid {
struct VibrationMixer;
}
}  // namespace nn

namespace al {
class WaveVibrationData;
class WaveVibrationPlayer {
    WaveVibrationPlayer(nn::hid::VibrationMixer*, nn::hid::VibrationMixer*);
    void update();
    void startOneTime(al::WaveVibrationData const*, float, float, float, float, bool);
    void start(al::WaveVibrationData const*, float, float, float, float, bool);
    void startLoop(al::WaveVibrationData const*, float, float, float, float, bool);
    void stop();
    void pause();
    void endPause();
    void changeVolume(float, float);
    bool isPlaying() const;
    void changePitch(float, float);
    void changeVolumeAndPitch(float, float, float, float);
};
}  // namespace al