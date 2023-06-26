#pragma once

#include <basis/seadTypes.h>

namespace al {
class ByamlIter;

class ActorScoreKeeper {
    struct Entry {
        const char* factorName;
        const char* categoryName;
    };

private:
    inline void allocArray();
    inline void putEntry(s32 index, const al::ByamlIter& iter);

    Entry* array;
    s32 size;

public:
    ActorScoreKeeper();

    void init(const al::ByamlIter& iter);
    void getCategoryName();  // unknown return type
    const char* tryGetCategoryName(const char* a1);
};
}  // namespace al
