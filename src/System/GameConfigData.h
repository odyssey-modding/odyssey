#pragma once

#include <al/Library/Layout/LayoutActor.h>
#include <al/Library/Yaml/ByamlIter.h>
#include <al/Library/Yaml/ByamlUtil.h>
#include "ByamlSave.h"

namespace al {
class Scene;
}

class GameConfigData : public ByamlSave {
    int mCameraStickSensitivityLevel = -1;
    bool mIsCameraReverseInputH = false;
    bool mIsCameraReverseInputV = false;
    bool mIsValidCameraGyro = true;
    int mCameraGyroSensitivityLevel = -1;
    bool mIsUseOpenListAdditionalButton = false;
    bool mIsValidPadRumble = true;
    int mPadRumbleLevel = 0;

public:
    GameConfigData();
    void init();
    bool isCameraReverseInputH() const;
    void onCameraReverseInputH();
    void offCameraReverseInputH();
    bool isCameraReverseInputV() const;
    void onCameraReverseInputV();
    void offCameraReverseInputV();
    int getCameraStickSensitivityLevel() const;
    void setCameraStickSensitivityLevel(int);
    bool isValidCameraGyro() const;
    void validateCameraGyro();
    void invalidateCameraGyro();
    int getCameraGyroSensitivityLevel() const;
    void setCameraGyroSensitivityLevel(int);
    bool isUseOpenListAdditionalButton() const;
    void onUseOpenListAdditionalButton();
    void offUseOpenListAdditionalButton();
    bool isValidPadRumble() const;
    void validatePadRumble();
    void invalidatePadRumble();
    int getPadRumbleLevel() const;
    void setPadRumbleLevel(int);
    void write(al::ByamlWriter*) override;
    void read(al::ByamlIter const&) override;
};

namespace rs {
GameConfigData* getGameConfigData(al::LayoutActor const*);
void saveGameConfigData(al::LayoutActor const*);
void applyGameConfigData(al::Scene*, GameConfigData const*);
bool isUseOpenListAdditionalButton(al::IUseSceneObjHolder const*);
}  // namespace rs