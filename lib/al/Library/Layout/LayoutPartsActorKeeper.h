#pragma once

#include <container/seadPtrArray.h>

namespace al {
class LayoutActor;

class LayoutPartsActorKeeper {
private:
    al::LayoutActor** mPartsActors = nullptr;
    s32 mNumActors = 0;
    s32 mMaxActors = 0;

public:
    LayoutPartsActorKeeper(s32 maxActors);

    void resisterPartsActor(al::LayoutActor* actor);
    void appear();
    void kill();
    void update();
    void calcAnim(bool recursive);
};
}  // namespace al
