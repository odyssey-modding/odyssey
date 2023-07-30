#include <al/Library/LiveActor/ActorFlagFunction.h>
#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/LiveActor/LiveActorGroup.h>

namespace al {
LiveActorGroup::LiveActorGroup(const char* groupName, s32 maxActors)
    : mGroupName(groupName), mMaxActorCount(maxActors), mActors(new LiveActor*[maxActors]) {}

s32 LiveActorGroup::registerActor(al::LiveActor* pActor) {
    this->mActors[this->mActorCount] = pActor;
    auto count = this->mActorCount;
    this->mActorCount = count + 1;
    return count;
}

void LiveActorGroup::removeActor(const al::LiveActor* pActor) {
    for (s32 i = 0; i < mActorCount; i++) {
        if (mActors[i] == pActor) {
            mActors[i] = mActors[mActorCount - 1];
            mActorCount--;
            break;
        }
    }
}

void LiveActorGroup::removeActorAll() {
    mActorCount = 0;
}

bool LiveActorGroup::isExistActor(const al::LiveActor* pActor) const {
    if (mActorCount < 1) {
        return false;
    }

    for (s32 i = 0; i < mActorCount; i++) {
        if (mActors[i] == pActor) {
            return true;
        }
    }

    return false;
}

bool LiveActorGroup::isFull() const {
    return mActorCount >= mMaxActorCount;
}

s32 LiveActorGroup::calcAliveActorNum() const {
    s32 count = 0;

    for (s32 i = 0; i < mActorCount; i++) {
        if (!al::isDead(mActors[i])) {
            count++;
        }
    }

    return count;
}

al::LiveActor* LiveActorGroup::getDeadActor() const {
    for (s32 i = 0; i < mActorCount; i++) {
        if (al::isDead(mActors[i])) {
            return mActors[i];
        }
    }

    return nullptr;
}

al::LiveActor* LiveActorGroup::tryFindDeadActor() const {
    for (s32 i = 0; i < mActorCount; i++) {
        if (al::isDead(mActors[i])) {
            return mActors[i];
        }
    }

    return nullptr;
}

void LiveActorGroup::appearAll() {
    for (s32 i = 0; i < mActorCount; i++) {
        if (al::isDead(mActors[i])) {
            mActors[i]->appear();
        }
    }
}

void LiveActorGroup::killAll() {
    for (s32 i = 0; i < mActorCount; i++) {
        if (al::isAlive(mActors[i])) {
            mActors[i]->kill();
        }
    }
}

void LiveActorGroup::makeActorAliveAll() {
    for (s32 i = 0; i < mActorCount; i++) {
        mActors[i]->makeActorAlive();
    }
}

void LiveActorGroup::makeActorDeadAll() {
    for (s32 i = 0; i < mActorCount; i++) {
        mActors[i]->makeActorDead();
    }
}
};  // namespace al
