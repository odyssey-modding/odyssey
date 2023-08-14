#pragma once

#include <al/Library/LiveActor/LiveActor.h>

class AnimSequencer;

namespace AnimSeqFunc {
AnimSequencer* createActorAnimSequencer(al::LiveActor*);
};