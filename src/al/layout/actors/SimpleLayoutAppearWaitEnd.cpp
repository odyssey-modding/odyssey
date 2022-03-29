#include "al/layout/actors/SimpleLayoutAppearWaitEnd.h"
#include "al/util/LayoutActorUtil.h"

namespace al {
SimpleLayoutAppearWaitEnd::SimpleLayoutAppearWaitEnd(const char* name, const char* archiveName,
                                                     const al::LayoutInitInfo& initInfo,
                                                     const char* suffix, bool localized)
    : al::LayoutActor(name), mWaitMaxStep(-1) {
    if (localized) {
        al::initLayoutActorLocalized(this, initInfo, archiveName, suffix);
    } else {
        al::initLayoutActor(this, initInfo, archiveName, suffix);
    }
    LayoutActor::initNerve(&nrvSimpleLayoutAppearWaitEndAppear, 0);
}

SimpleLayoutAppearWaitEnd::SimpleLayoutAppearWaitEnd(al::LayoutActor* parentActor, const char* name,
                                                     const char* archiveName,
                                                     const al::LayoutInitInfo& initInfo,
                                                     const char* suffix)
    : al::LayoutActor(name), mWaitMaxStep(-1) {
    al::initLayoutPartsActor(this, parentActor, initInfo, archiveName, suffix);
    LayoutActor::initNerve(&nrvSimpleLayoutAppearWaitEndAppear, 0);
}

void SimpleLayoutAppearWaitEnd::appear() {
    al::startAction(this, "Appear", nullptr);
    LayoutActor::appear();
    setNerve(this, &nrvSimpleLayoutAppearWaitEndAppear);
}

void SimpleLayoutAppearWaitEnd::end() {
    if (al::isNerve(this, &nrvSimpleLayoutAppearWaitEndEnd))
        return;
    al::setNerve(this, &nrvSimpleLayoutAppearWaitEndEnd);
}

void SimpleLayoutAppearWaitEnd::startWait() {
    al::startAction(this, "Wait", nullptr);
    LayoutActor::appear();
    al::setNerve(this, &nrvSimpleLayoutAppearWaitEndWait);
}

bool SimpleLayoutAppearWaitEnd::isAppearOrWait() const {
    return al::isNerve(this, &nrvSimpleLayoutAppearWaitEndWait) ||
           al::isNerve(this, &nrvSimpleLayoutAppearWaitEndAppear);
}

bool SimpleLayoutAppearWaitEnd::isWait() const {
    return al::isNerve(this, &nrvSimpleLayoutAppearWaitEndWait);
}

void SimpleLayoutAppearWaitEnd::exeAppear() {
    if (al::isActionEnd(this, nullptr)) {
        al::setNerve(this, &nrvSimpleLayoutAppearWaitEndWait);
    }
}

void SimpleLayoutAppearWaitEnd::exeWait() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Wait", nullptr);
    }

    if (mWaitMaxStep > -1 && al::isGreaterEqualStep(this, mWaitMaxStep)) {
        al::setNerve(this, &nrvSimpleLayoutAppearWaitEndEnd);
    }
}

void SimpleLayoutAppearWaitEnd::exeEnd() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "End", nullptr);
    }
    if (al::isActionEnd(this, nullptr)) {
        this->kill();
    }
}

namespace {
NERVE_IMPL(SimpleLayoutAppearWaitEnd, Appear)
NERVE_IMPL(SimpleLayoutAppearWaitEnd, Wait)
NERVE_IMPL(SimpleLayoutAppearWaitEnd, End)
}  // namespace
}  // namespace al
