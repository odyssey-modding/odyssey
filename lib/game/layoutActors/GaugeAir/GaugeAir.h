#pragma once

#include "al/layout/LayoutActor.h"
#include "al/layout/LayoutInitInfo.h"
#include "al/util/NerveUtil.h"

class GaugeAir : public al::LayoutActor {
public:
    GaugeAir(const char*, const al::LayoutInitInfo& initInfo);

    bool isWait() const;
    void start();
    void updateStateAnim();
    void fastEnd();
    void endMax();
    void setRate(float rate);

    void exeAppear();
    void exeWait();
    void exeEnd();
    void exeFastEnd();
private:
    bool isDecreasing;
    float mLevel;
};

namespace {
NERVE_HEADER(GaugeAir, Appear)
NERVE_HEADER(GaugeAir, Wait)
NERVE_HEADER(GaugeAir, End)
NERVE_HEADER(GaugeAir, FastEnd)
}

static_assert(sizeof(GaugeAir) == 0x130);