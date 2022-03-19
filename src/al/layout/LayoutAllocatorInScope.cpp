#include "al/layout/LayoutAllocatorInScope.h"
#include "al/util/OtherUtil.h"
#include "eui/euiNwAllocator.h"

namespace al {
LayoutAllocatorInScope::LayoutAllocatorInScope() {
    eui::NwAllocator::initialize(al::getCurrentHeap());
}
#ifdef NON_MATCHING
LayoutAllocatorInScope::~LayoutAllocatorInScope() {
    eui::NwAllocator::finalize();
}
#endif  // NON_MATCHING
}  // namespace al