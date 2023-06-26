#include <al/Library/Nerve/NerveAction.h>
#include "NerveUtil.h"

namespace al {
NerveAction::NerveAction() {
    alNerveFunction::NerveActionCollector* collector = alNerveFunction::NerveActionCollector::sCurrentCollector;
    if (!alNerveFunction::NerveActionCollector::sCurrentCollector->mHead)
        alNerveFunction::NerveActionCollector::sCurrentCollector->mHead = this;
    else
        alNerveFunction::NerveActionCollector::sCurrentCollector->mTail->mNextAction = this;
    collector->mTail = this;
    collector->mActionCount++;
}
}  // namespace al
alNerveFunction::NerveActionCollector::NerveActionCollector() {
    sCurrentCollector = this;
}
void alNerveFunction::NerveActionCollector::addNerve(al::NerveAction* action) {
    if (!mHead)
        mHead = action;
    else
        mTail->mNextAction = action;
    mTail = action;
    mActionCount++;
}
