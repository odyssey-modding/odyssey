#pragma once

#include <basis/seadTypes.h>
#include <cstdarg>

namespace al {
s32 calcHashCode(const char*);
s32 calcHashCodeLower(const char*);
s32 calcHashCodeFmt(const char*, std::va_list);
s32 calcHashCodeFmt(const char*, ...);
}  // namespace al