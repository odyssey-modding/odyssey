#include <al/Library/Nerve/NerveStateBase.h>

namespace al {
NerveStateBase::NerveStateBase(const char* stateName) : al::NerveExecutor(stateName) {}
NerveStateBase::~NerveStateBase() = default;

void NerveStateBase::init() {}

void NerveStateBase::appear() {
    mIsDead = false;
}

void NerveStateBase::kill() {
    mIsDead = true;
}

bool NerveStateBase::update() {
    updateNerve();

    if (mIsDead) {
        return true;
    }

    control();

    return mIsDead;
}

void NerveStateBase::control() {}

ActorStateBase::ActorStateBase(const char* name, al::LiveActor* parent) : al::NerveStateBase(name), mParent(parent) {}
}  // namespace al
