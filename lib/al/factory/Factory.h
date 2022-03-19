#pragma once

namespace al {
class LiveActor;

template <class T>
struct NameToCreator {
    const char* mName;
    T mCreationFunction;
};

template <typename T>
class Factory {
public:
    inline Factory(const char* factory_name)
        : mFactoryName(factory_name), mFactoryEntries(nullptr), mNumFactoryEntries(0) {}
    template <int N>
    inline Factory(const char* factory_name, al::NameToCreator<T> (&entries)[N])
        : mFactoryName(factory_name) {
        initFactory(entries);
    }
    template <int N>
    inline void initFactory(al::NameToCreator<T> (&entries)[N]) {
        mFactoryEntries = entries;
        mNumFactoryEntries = N;
    }

    virtual const char* convertName(const char*) const;

private:
    const char* mFactoryName;
    al::NameToCreator<T>* mFactoryEntries;
    int mNumFactoryEntries;
};

class ActorFactory : public al::Factory<al::LiveActor* (*)(char const*)> {
public:
    ActorFactory(const char*);
};
}  // namespace al
