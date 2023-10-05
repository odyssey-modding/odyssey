#include <al/Library/Nerve/NerveStateBase.h>

namespace al {
NerveStateBase::NerveStateBase(const char* stateName) : al::NerveExecutor(stateName) {}
NerveStateBase::~NerveStateBase() = default;

void NerveStateBase::init() {}

void NerveStateBase::appear() {
    setDead(false);
}

void NerveStateBase::kill() {
    setDead(true);
}

bool NerveStateBase::update() {
    updateNerve();

    if (isDead()) {
        return true;
    }

    control();

    return isDead();
}

void NerveStateBase::control() {}

ActorStateBase::ActorStateBase(const char* name, al::LiveActor* actor) : al::NerveStateBase(name), mActor(actor) {}
}  // namespace al
