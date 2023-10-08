#include <al/Library/Nerve/NerveExecutor.h>
#include <al/Library/Nerve/NerveKeeper.h>

namespace al {
NerveExecutor::NerveExecutor(const char* name) {
    mNerveKeeper = nullptr;
};
NerveExecutor::~NerveExecutor() {
    delete mNerveKeeper;
}
al::NerveKeeper* NerveExecutor::getNerveKeeper() const {
    return mNerveKeeper;
}
void NerveExecutor::initNerve(const al::Nerve* nerve, s32 stateCount) {
    mNerveKeeper = new NerveKeeper(this, nerve, stateCount);
}
void NerveExecutor::updateNerve() {
    if (mNerveKeeper)
        mNerveKeeper->update();
}
}  // namespace al
