#include <al/Library/Sequence/Sequence.h>
namespace al {
void Sequence::init(const al::SequenceInitInfo& initInfo) {}
void Sequence::kill() {
    mIsAlive = false;
}
}  // namespace al
