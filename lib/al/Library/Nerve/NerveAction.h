#pragma once

#include <al/Library/Nerve/Nerve.h>
#include <al/Library/Nerve/NerveUtil.h>
#include <basis/seadTypes.h>

namespace al {
class NerveAction : public al::Nerve {
    friend class alNerveFunction::NerveActionCollector;

private:
    al::NerveAction* mNextAction = nullptr;

public:
    NerveAction();
    virtual const char* getActionName() const = 0;
};
}  // namespace al
