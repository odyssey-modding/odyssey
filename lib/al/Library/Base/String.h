#pragma once

#include <prim/seadSafeString.h>

namespace al {
bool isEqualString(const char16_t*, const char16_t*);
bool isEqualString(const char*, const char*);
bool isEqualString(const sead::SafeString&, const sead::SafeString&);
}  // namespace al