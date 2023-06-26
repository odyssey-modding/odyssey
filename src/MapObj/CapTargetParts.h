#pragma once

#include "al/Library/Obj/PartsModel.h"

class CapTargetParts : public al::PartsModel {
    public:
    CapTargetParts(al::LiveActor *,al::ActorInitInfo const&);
    void startHack();
    void startNormal();
    void startSwoon();
};