#pragma once

#include "al/Library/Base/String.h"

namespace al {
template <typename T>
struct NameToCreator {
    const char* mName;
    T mCreationFunction;
};

template <typename T>
class Factory {
private:
    const char* mFactoryName;
    al::NameToCreator<T>* mFactoryEntries;
    s32 mNumFactoryEntries;

public:
    inline Factory(const char* factoryName) : mFactoryName(factoryName), mFactoryEntries(nullptr), mNumFactoryEntries(0) {}

    template <s32 N>
    inline Factory(const char* factoryName, al::NameToCreator<T> (&entries)[N]) : mFactoryName(factoryName) {
        initFactory(entries);
    }
    template <s32 N>
    inline void initFactory(al::NameToCreator<T> (&entries)[N]) {
        mFactoryEntries = entries;
        mNumFactoryEntries = N;
    }

    virtual const char* convertName(const char* name) const { return name; }
    
    s32 getNumFactoryEntries() const { return mNumFactoryEntries; }

    s32 getEntryIndex(const char* entryName, T* creationPtr) const {
        const char* name = convertName(entryName);
        s32 nFactoryEntries = mNumFactoryEntries;
        const al::NameToCreator<T>* entries = mFactoryEntries;
        for (s32 i = 0; i < nFactoryEntries; i++) {
            if (al::isEqualString(name, entries[i].mName)) {
                *creationPtr = entries[i].mCreationFunction;
                return i;
            }
        }
        return -1;
    }
};

}  // namespace al