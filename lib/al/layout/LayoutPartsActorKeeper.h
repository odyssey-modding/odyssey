#pragma once

#include <container/seadPtrArray.h>
namespace al {
class LayoutActor;

class LayoutPartsActorKeeper {
public:
    LayoutPartsActorKeeper(int);
    void registerPartsActor(al::LayoutActor);
    void appear();
    void kill();
    void update();
    void calcAnim(bool);
private:
    sead::PtrArray<al::LayoutActor> mPartsActors;
};
}