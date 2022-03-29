#pragma once

#include "al/layout/LayoutActor.h"
#include "al/layout/LayoutInitInfo.h"
#include "al/util/NerveUtil.h"

namespace al {
class SimpleLayoutAppearWaitEnd : public al::LayoutActor {
public:
    SimpleLayoutAppearWaitEnd(char const*, char const*, al::LayoutInitInfo const&, char const*,
                              bool);
    SimpleLayoutAppearWaitEnd(al::LayoutActor*, char const*, char const*, al::LayoutInitInfo const&,
                              char const*);

    void appear() override;
    void end();
    void startWait();

    bool isAppearOrWait() const;
    bool isWait() const;

    void exeAppear();
    void exeWait();
    void exeEnd();

    int mWaitMaxStep;
};

static_assert(sizeof(SimpleLayoutAppearWaitEnd) == 0x130);

namespace {
NERVE_HEADER(SimpleLayoutAppearWaitEnd, Appear)
NERVE_HEADER(SimpleLayoutAppearWaitEnd, Wait)
NERVE_HEADER(SimpleLayoutAppearWaitEnd, End)
}  // namespace
}  // namespace al