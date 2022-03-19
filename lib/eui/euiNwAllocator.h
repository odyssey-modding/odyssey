#pragma once

#include <heap/seadHeap.h>

namespace nn {
namespace ui2d {
typedef void* (AllocateFunc)(u64 size, u64 elements, void* userData);
typedef void (DeallocateFunc)(void* ptr, void* userData);
void Initialize(AllocateFunc* allocFunc, DeallocateFunc* freeFunc, void* userData);
}  // namespace ui2d
}  // namespace nn

namespace eui {
class NwAllocator {
public:
    static void initialize(sead::Heap* heap);
    static void finalize();
    static void* ui2dAllocateFunction(u64, u64, void* heap);
    static void ui2dDeallocateFunction(void* ptr, void* heap);
};
}  // namespace eui