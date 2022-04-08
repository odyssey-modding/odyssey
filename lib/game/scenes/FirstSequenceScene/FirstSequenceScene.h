#pragma once

#include "al/scene/Scene.h"

class FirstSequenceScene : public al::Scene {
    FirstSequenceScene(const char* name);
    ~FirstSequenceScene();

    void init(const al::SceneInitInfo&) override;
    void appear() override;
    void control() override;
    void drawMain() override;

    void setNoWipe();
};
