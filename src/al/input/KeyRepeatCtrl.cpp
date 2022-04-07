#include "al/input/KeyRepeatCtrl.h"

namespace al {
KeyRepeatCtrl::KeyRepeatCtrl()
    : mInitialMaxWait(0), mMaxWait(0), mUpCounter(0), mDownCounter(0) {
    mCounter = 1;
}
void KeyRepeatCtrl::init(int initialMaxWait, int maxWait) {
    mInitialMaxWait = initialMaxWait;
    mMaxWait = maxWait;
}
void KeyRepeatCtrl::reset() {
    mUpCounter = 0;
    mDownCounter = 0;
    mCounter = 1;
}
void KeyRepeatCtrl::update(bool up, bool down) {
    int iVar1;

    if (((up & 1U) == 0) && ((down & 1U) == 0)) {
        this->mCounter = 0;
    }
    else if (this->mCounter != 0) {
        return;
    }
    if ((up & 1U) == 0) {
        iVar1 = 0;
    }
    else {
        iVar1 = this->mUpCounter + 1;
    }
    this->mUpCounter = iVar1;
    if ((down & 1U) == 0) {
        this->mDownCounter = 0;
        return;
    }
    this->mDownCounter = this->mDownCounter + 1;
    return;
}
}  // namespace al
