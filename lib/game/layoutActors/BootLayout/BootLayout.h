#pragma once

#include "al/layout/LayoutActor.h"
#include "al/layout/LayoutInitInfo.h"
#include "al/util/NerveUtil.h"

class BootLayout : public al::LayoutActor {
public:
    BootLayout(const al::LayoutInitInfo& initInfo);

    void appear() override;
    void kill() override;
    void startWipe();
    void end();
    void endImmidiate();
    void endWipe();
    bool isEndWipe() const;
    int getBgFrame() const;

    void exeAppear();
    void exeWait();
    void exeEnd();
    void exeEndWipe();
    void exeStartWipe();
private:
    al::LayoutActor* mLoadingLayout;
};

namespace {
NERVE_HEADER(BootLayout, Appear)
NERVE_HEADER(BootLayout, Wait)
NERVE_HEADER(BootLayout, End)
NERVE_HEADER(BootLayout, EndWipe)
NERVE_HEADER(BootLayout, StartWipe)
}