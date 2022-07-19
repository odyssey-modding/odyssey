#include "game/layoutActors/GaugeAir/GaugeAir.h"
#include "al/util/LayoutActorUtil.h"

GaugeAir::GaugeAir(const char* name, const al::LayoutInitInfo& initInfo)
    : al::LayoutActor(name), isDecreasing(false), mLevel(1) {
    al::initLayoutActor(this, initInfo, "GaugeAir", nullptr);
    initNerve(&nrvGaugeAirAppear, 0);
    this->kill();
}

bool GaugeAir::isWait() const {
    return mIsAlive && al::isNerve(this, &nrvGaugeAirWait);
}

void GaugeAir::start() {
    appear();
    isDecreasing = false;
    al::startFreezeAction(this, "Decrease",
                          al::getActionFrameMax(this, "Decrease", "Gauge") * (1.0f - mLevel),
                          "Gauge");
    updateStateAnim();
    al::setNerve(this, &nrvGaugeAirAppear);
}

namespace {
NERVE_IMPL(GaugeAir, Appear)
NERVE_IMPL(GaugeAir, Wait)
NERVE_IMPL(GaugeAir, End)
NERVE_IMPL(GaugeAir, FastEnd)
}  // namespace