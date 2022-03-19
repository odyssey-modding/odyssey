#include "eui/euiNwAllocator.h"
namespace eui {
void NwAllocator::initialize(sead::Heap* heap) {
    nn::ui2d::Initialize(
        &NwAllocator::ui2dAllocateFunction, NwAllocator::ui2dDeallocateFunction, heap);
}
void NwAllocator::finalize() {
    nn::ui2d::Initialize(nullptr, nullptr, nullptr);
}
void* NwAllocator::ui2dAllocateFunction(u64 size, u64 alignment, void* heap) {
    return reinterpret_cast<sead::Heap*>(heap)->tryAlloc(size, (s32)alignment);
}
void NwAllocator::ui2dDeallocateFunction(void* ptr, void* heap) {
    return reinterpret_cast<sead::Heap*>(heap)->free(ptr);
}
}  // namespace eui
