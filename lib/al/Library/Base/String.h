#pragma once

#include <prim/seadSafeString.h>
#include <prim/seadStringUtil.h>
#include <strings.h>

namespace al {
template <s32 L>
class StringTmp : public sead::FixedSafeString<L> {  // equal to WFormatFixedSafeString
public:
    StringTmp(const char* format, ...) : sead::FixedSafeString<L>() {
        std::va_list args;
        va_start(args, format);
        this->formatV(format, args);
        va_end(args);
    }
    ~StringTmp() = default;
};
class MatchStr;

const char* getBaseName(const char*);
const char* createStringIfInStack(const char*);
const char* createConcatString(const char*, const char*);
al::StringTmp<128> createFileNameBySuffix(sead::BufferedSafeStringBase<char>*, const char*, const char*);
void outputValueWithComma(char*, u32, unsigned long, bool, bool);
void extractString(char*, const char*, u32, u32);

const char* searchSubString(const char*, const char*);
const char* searchSubString(const char*, const char*, s32);

typedef void (*callback_str)(const char*, const char*, void*);
const char* getSubStringUnmatched(const char**, const char*, const al::MatchStr&, callback_str, void*);
const char* getSubStringUnmatched(const char*, const al::MatchStr&);

s32 extractBaseNameW(sead::BufferedSafeStringBase<char16_t>*, const sead::SafeStringBase<char16_t>&);
void removeExtensionString(char*, u32, const char*);
void removeStringFromEnd(char*, u32, const char*, const char*);
void translateCharacters(char*, const char*, const char*);

bool tryReplaceString(sead::BufferedSafeStringBase<char>*, const char*, const char*);
bool tryReplaceString(sead::BufferedSafeStringBase<char>*, const char*, const char*, const char*);
bool tryReplaceStringNoRecursive(sead::BufferedSafeStringBase<char>*, const char*, const char*, const char*);

bool isEqualString(const char16_t*, const char16_t*);
bool isEqualSubString(const char*, const char*);
bool isEqualSubString(const sead::SafeStringBase<char>&, const sead::SafeStringBase<char>&);
bool isStartWithString(const char*, const char*);
bool isEndWithString(const char*, const char*);
bool isMatchString(const char*, const al::MatchStr&);

s32 compareStringIgnoreCase(const char*, const char*);
void makeUrlEncodeString(char*, u32, const char*);
void makeUrlDecodeString(char*, u32, const char*);
void copyString(char*, const char*, u32);
void copyStringW(char16_t*, const char16_t*, u32);

bool isInStack(const void*);

bool isEqualString(const char*, const char*);
bool isEqualString(const sead::SafeStringBase<char>&, const sead::SafeStringBase<char>&);
bool isEqualStringCase(const char*, const char*);
bool isEqualStringCase(const sead::SafeStringBase<char>&, const sead::SafeStringBase<char>&);
};  // namespace al