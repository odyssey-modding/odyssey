#include "game/layoutActors/BootLayout/BootLayout.h"
#include "al/util/LayoutActorUtil.h"

BootLayout::BootLayout(const al::LayoutInitInfo& initInfo) : al::LayoutActor("[起動]BootLoading"), mLoadingLayout(nullptr) {
    al::initLayoutActor(this, initInfo, "BootLayout", nullptr);
    mLoadingLayout = new al::LayoutActor("[起動]BG");
    al::initLayoutPartsActor(mLoadingLayout, this, initInfo, "ParBG", nullptr);
    al::LayoutActor::initNerve(&nrvBootLayoutAppear, 0);
}

void BootLayout::appear() {
    al::startAction(this, "Appear", nullptr);
    al::startAction(mLoadingLayout, "Hide", nullptr);
    al::LayoutActor::appear();
    al::setNerve(this, &nrvBootLayoutAppear);
}

void BootLayout::kill() {
    al::LayoutActor::kill();
}

void BootLayout::startWipe() {
    al::startAction(this, "Wait", nullptr);
    al::startAction(mLoadingLayout, "Hide", nullptr);
    al::LayoutActor::appear();
    al::setNerve(this, &nrvBootLayoutStartWipe);
}

void BootLayout::end() {
    al::startAction(this, "End", "Main");
    al::LayoutActor::appear();
    al::setNerve(this, &nrvBootLayoutEnd);
}

void BootLayout::endImmidiate() {
    al::startFreezeActionEnd(this, "End", "Main");
    al::LayoutActor::appear();
    al::setNerve(this, &nrvBootLayoutEnd);
}

void BootLayout::endWipe() {
    al::startAction(mLoadingLayout, "Wait", "Main");
    al::LayoutActor::appear();
    al::setNerve(this, &nrvBootLayoutEndWipe);
}

bool BootLayout::isEndWipe() const {
    return al::isNerve(this, &nrvBootLayoutEndWipe);
}
int BootLayout::getBgFrame() const {
    return al::getActionFrame(mLoadingLayout, nullptr);
}
void BootLayout::exeAppear() {
    if (al::isActionEnd(this, nullptr)) {
        al::setNerve(this, &nrvBootLayoutWait);
    }
}
void BootLayout::exeWait() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Wait", "Main");
    }
}
void BootLayout::exeStartWipe() {
    if (al::isFirstStep(this)) {
        al::startAction(mLoadingLayout, "Appear", "Main");
    }
    if (al::isActionEnd(mLoadingLayout, nullptr)) {
        al::startAction(mLoadingLayout, "Wait", "Main");
        al::setNerve(this, &nrvBootLayoutEndWipe);
    }
}
void BootLayout::exeEnd() {}
void BootLayout::exeEndWipe() {}

namespace {
NERVE_IMPL(BootLayout, Appear)
NERVE_IMPL(BootLayout, Wait)
NERVE_IMPL(BootLayout, End)
NERVE_IMPL(BootLayout, EndWipe)
NERVE_IMPL(BootLayout, StartWipe)
}  // namespace