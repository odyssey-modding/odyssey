#pragma once

#include <al/Library/HostIO/HioNode.h>
#include <al/Library/Nerve/NerveKeeper.h>
#include <math/seadVector.h>

namespace al {
class Nerve;
class NerveKeeper;

class NerveExecutor : public al::IUseNerve, public al::HioNode {
private:
    al::NerveKeeper* mNerveKeeper = nullptr;

public:
    NerveExecutor(const char* name);
    virtual ~NerveExecutor();
    al::NerveKeeper* getNerveKeeper() const override;
    void initNerve(const al::Nerve* nerve, s32 stateCount);
    void updateNerve();
};

}  // namespace al
