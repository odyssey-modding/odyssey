#pragma once

#include <basis/seadTypes.h>
#include <al/Library/HostIO/HioNode.h>

namespace al {
class LiveActor;

class LiveActorGroup : public al::HioNode {
private:
    const char* mGroupName;
    s32 mMaxActorCount;
    s32 mActorCount = 0;
    al::LiveActor** mActors;

public:
    LiveActorGroup(const char*, s32);

    virtual s32 registerActor(al::LiveActor*);

    void removeActor(const al::LiveActor*);
    void removeActorAll();
    bool isExistActor(const al::LiveActor*) const;
    bool isFull() const;
    s32 calcAliveActorNum() const;
    al::LiveActor* getDeadActor() const;
    al::LiveActor* tryFindDeadActor() const;
    void appearAll();
    void killAll();
    void makeActorAliveAll();
    void makeActorDeadAll();
};

template <class T>
class DeriveActorGroup : al::LiveActorGroup {
public:
    s32 registerActor(T* actor) { al::LiveActorGroup::registerActor(actor); }
    void removeActor(const T* actor) { al::LiveActorGroup::removeActor(actor); }
    void removeActorAll() { al::LiveActorGroup::removeActorAll(); }
    bool isExistActor(const T* actor) const { return al::LiveActorGroup::isExistActor(actor); }
    bool isFull() const { return al::LiveActorGroup::isFull(); }
    s32 calcAliveActorNum() const { return al::LiveActorGroup::calcAliveActorNum(); }
    T* getDeadActor() const { return al::LiveActorGroup::getDeadActor(); }
    T* tryFindDeadActor() const { return al::LiveActorGroup::tryFindDeadActor(); }
    void appearAll() { al::LiveActorGroup::appearAll(); }
    void killAll() { al::LiveActorGroup::killAll(); }
    void makeActorAliveAll() { al::LiveActorGroup::makeActorAliveAll(); }
    void makeActorDeadAll() { al::LiveActorGroup::makeActorDeadAll(); }
};

}  // namespace al
