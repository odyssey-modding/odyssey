#pragma once

#include <al/Library/Layout/LayoutActor.h>
#include <al/Library/Layout/LayoutInitFunction.h>

class ButtonMiiverse : public al::LayoutActor {
public:
    ButtonMiiverse();
    void init(al::LayoutInitInfo const&);
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