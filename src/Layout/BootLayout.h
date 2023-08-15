#pragma once

#include <al/Library/Layout/LayoutActor.h>
#include <al/Library/Layout/LayoutInitFunction.h>

class BootLayout : public al::LayoutActor {
private:
    al::LayoutActor* mParBg = nullptr;

public:
    BootLayout(const al::LayoutInitInfo&);
    void appear();
    void kill();
    void startWipe();
    void endWipe();
    void end();
    void endImmidiate();
    bool isEndWipe() const;
    f32 getBgFrame() const;

    void exeAppear();
    void exeWait();
    void exeStartWipe();
    void exeEndWipe();
    void exeEnd();
};