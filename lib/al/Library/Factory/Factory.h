#pragma once

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
    int mNumFactoryEntries;

public:
    inline Factory(const char* factoryName) : mFactoryName(factoryName), mFactoryEntries(nullptr), mNumFactoryEntries(0) {}

    template <int N>
    inline Factory(const char* factoryName, al::NameToCreator<T> (&entries)[N]) : mFactoryName(factoryName) {
        initFactory(entries);
    }
    template <int N>
    inline void initFactory(al::NameToCreator<T> (&entries)[N]) {
        mFactoryEntries = entries;
        mNumFactoryEntries = N;
    }

    virtual const char* convertName(const char* name) const { return name; }
    al::NameToCreator<T>* getFactoryEntries() const { return mFactoryEntries; }
};

}  // namespace al