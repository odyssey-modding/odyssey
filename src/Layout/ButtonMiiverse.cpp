#include "ButtonMiiverse.h"
#include <al/Library/Controller/JoyPadUtil.h>
#include <al/Library/Layout/LayoutActionFunction.h>
#include <al/Library/Layout/LayoutActorUtil.h>
#include <al/Library/Layout/LayoutInitFunction.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Nerve/NerveUtil.h>

namespace {
NERVE_IMPL(ButtonMiiverse, Wait);
NERVE_IMPL(ButtonMiiverse, Decide);
NERVE_IMPL(ButtonMiiverse, OnWait);
NERVE_IMPL(ButtonMiiverse, Disable);
NERVE_IMPL(ButtonMiiverse, HoldOn);
NERVE_IMPL(ButtonMiiverse, HoldOff);

struct {
    NERVE_MAKE(ButtonMiiverse, Wait);
    NERVE_MAKE(ButtonMiiverse, Decide);
    NERVE_MAKE(ButtonMiiverse, OnWait);
    NERVE_MAKE(ButtonMiiverse, Disable);
    NERVE_MAKE(ButtonMiiverse, HoldOn);
    NERVE_MAKE(ButtonMiiverse, HoldOff);
} NrvButtonMiiverse;

}  // namespace

ButtonMiiverse::ButtonMiiverse() : al::LayoutActor("Miiverse") {}

void ButtonMiiverse::init(const al::LayoutInitInfo& info) {
    al::initLayoutActor(this, info, "ButtonMiiverse", 0);
    initNerve(&NrvButtonMiiverse.Wait, 0);
    appear();
}

bool ButtonMiiverse::isOn() const {
    return al::isNerve(this, &NrvButtonMiiverse.Decide) || al::isNerve(this, &NrvButtonMiiverse.OnWait);
}

void ButtonMiiverse::setOff() {
    al::setNerve(this, &NrvButtonMiiverse.Wait);
}

void ButtonMiiverse::validate() {
    if (al::isNerve(this, &NrvButtonMiiverse.Disable))
        setOff();
}

void ButtonMiiverse::forceValidate() {
    setOff();
}

void ButtonMiiverse::invalidate() {
    if (!al::isNerve(this, &NrvButtonMiiverse.Disable))
        al::setNerve(this, &NrvButtonMiiverse.Disable);
}

void ButtonMiiverse::exeWait() {
    if (al::isFirstStep(this))
        al::startAction(this, "Wait", 0);
    if (al::isHoldTouchPane(this, "Hit"))
        al::setNerve(this, &NrvButtonMiiverse.HoldOn);
}

void ButtonMiiverse::exeHoldOn() {
    if (al::isFirstStep(this))
        al::startAction(this, "Touch", 0);
    if (al::isReleaseTouchPane(this, "Hit"))
        al::setNerve(this, &NrvButtonMiiverse.Decide);
    else if (!al::isTouchPosInPane(this, "Hit"))
        al::setNerve(this, &NrvButtonMiiverse.HoldOff);
}

void ButtonMiiverse::exeHoldOff() {
    if (al::isFirstStep(this))
        al::startAction(this, "Touch", 0);
    if (al::isTouchPosInPane(this, "Hit"))
        al::setNerve(this, &NrvButtonMiiverse.HoldOn);
    else if (al::isPadReleaseTouch())
        setOff();
}

// NON_MATCHING
void ButtonMiiverse::exeDecide() {
    if (al::isFirstStep(this))
        al::startAction(this, "Decide", 0);
    al::setNerveAtActionEnd(this, &NrvButtonMiiverse.OnWait);
}

void ButtonMiiverse::exeOnWait() {
    if (al::isFirstStep(this))
        al::startAction(this, "Wait", 0);
}

void ButtonMiiverse::exeDisable() {
    if (al::isFirstStep(this))
        al::startAction(this, "Disable", 0);
}
