#include "Hash.h"

namespace al {
s32 calcHashCode(const char* str) {
    s32 hash = 0;

    while (*str) {
        hash = (hash * 31) + static_cast<s32>(*str);
        str++;
    }

    return hash;
}

}  // namespace al