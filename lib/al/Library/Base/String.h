#pragma once

#include <prim/seadSafeString.h>

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
    StringTmp() : sead::FixedSafeString<L>() {}
    ~StringTmp() = default;
};
class MatchStr;

const char* getBaseName(const char*);
const char* createStringIfInStack(const char*);
const char* createConcatString(const char*, const char*);
void createFileNameBySuffix(sead::BufferedSafeString*, const char*, const char*);
void outputValueWithComma(char*, u32, unsigned long, bool, bool);
void extractString(char*, const char*, u32, u32);

const char* searchSubString(const char*, const char*);
const char* searchSubString(const char*, const char*, s32);

typedef void (*callback_str)(const char*, const char*, void*);
const char* getSubStringUnmatched(const char**, const char*, const al::MatchStr&, callback_str, void*);
const char* getSubStringUnmatched(const char*, const al::MatchStr&);

s32 extractBaseNameW(sead::WBufferedSafeString*, const sead::WSafeString&);
void removeExtensionString(char*, u32, const char*);
void removeStringFromEnd(char*, u32, const char*, const char*);
void translateCharacters(char*, const char*, const char*);

bool tryReplaceString(sead::BufferedSafeString*, const char*, const char*);
bool tryReplaceString(sead::BufferedSafeString*, const char*, const char*, const char*);
bool tryReplaceStringNoRecursive(sead::BufferedSafeString*, const char*, const char*, const char*);

bool isEqualString(const char16_t*, const char16_t*);
bool isEqualSubString(const char*, const char*);
bool isEqualSubString(const sead::SafeString&, const sead::SafeString&);
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
bool isEqualString(const sead::SafeString&, const sead::SafeString&);
bool isEqualStringCase(const char*, const char*);
bool isEqualStringCase(const sead::SafeString&, const sead::SafeString&);
}  // namespace al