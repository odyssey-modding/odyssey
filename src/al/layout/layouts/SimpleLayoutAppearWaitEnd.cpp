#include "al/layout/layouts/SimpleLayoutAppearWaitEnd.h"
#include "al/util/LayoutActorUtil.h"

namespace al {
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

bool SimpleLayoutAppearWaitEnd::isAppearOrWait() const {
    return al::isNerve(this, &nrvSimpleLayoutAppearWaitEndWait) || al::isNerve(this, &nrvSimpleLayoutAppearWaitEndAppear);
}

bool SimpleLayoutAppearWaitEnd::isWait() const {
    return al::isNerve(this, &nrvSimpleLayoutAppearWaitEndWait);
}

void SimpleLayoutAppearWaitEnd::exeAppear() {}

namespace {
NERVE_IMPL(SimpleLayoutAppearWaitEnd, Appear)
NERVE_IMPL(SimpleLayoutAppearWaitEnd, Wait)
NERVE_IMPL(SimpleLayoutAppearWaitEnd, End)
}  // namespace
}  // namespace al
