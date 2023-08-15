#pragma once

namespace al {
class LiveActor;
}

class AnimSequencer;

namespace AnimSeqFunc {
AnimSequencer* createActorAnimSequencer(al::LiveActor*);
};