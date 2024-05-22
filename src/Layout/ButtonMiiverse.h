#pragma once

#include <al/Library/Layout/LayoutActor.h>

namespace al {
struct LayoutInitInfo;
}

class ButtonMiiverse : public al::LayoutActor {
public:
    ButtonMiiverse();
    void init(const al::LayoutInitInfo&);
    bool isOn() const;
    void setOff();
    void validate();
    void forceValidate();
    void invalidate();

    void exeWait();
    void exeHoldOn();
    void exeHoldOff();
    void exeDecide();
    void exeOnWait();
    void exeDisable();
};