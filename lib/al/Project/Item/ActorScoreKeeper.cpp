#include <al/Library/Yaml/ByamlIter.h>
#include <al/Project/Item/ActorScoreKeeper.h>

al::ActorScoreKeeper::ActorScoreKeeper() = default;

void al::ActorScoreKeeper::init(const al::ByamlIter& iter) {
    if (iter.isTypeArray()) {
        size = iter.getSize();
        allocArray();
        for (s32 i = 0; i < size; i++) {
            al::ByamlIter subIter;
            iter.tryGetIterByIndex(&subIter, i);
            putEntry(i, subIter);
        }
    } else {
        size = 1;
        allocArray();
        putEntry(0, iter);
    }
}

inline void al::ActorScoreKeeper::allocArray() {
    Entry* local_array = new Entry[size];
    if (size)
        memset(local_array, 0, sizeof(Entry) * size);
    array = local_array;
}

inline void al::ActorScoreKeeper::putEntry(s32 index, const al::ByamlIter& iter) {
    auto& entry = array[index];
    iter.tryGetStringByKey(&entry.factorName, "FactorName");
    iter.tryGetStringByKey(&entry.categoryName, "CategoryName");
}
