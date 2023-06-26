#pragma once

#include <heap/seadHeap.h>

namespace al {
class FileLoader;
class MemorySystem;
class ResourceSystem;
class SaveDataDirector;
class SystemKit {
    friend class alProjectInterface;
private:
    al::MemorySystem* mMemorySystem;
    al::FileLoader* mFileLoader;
    al::ResourceSystem* mResourceSystem;
    al::SaveDataDirector* mSaveDataDirector;
public:
    SystemKit();

    void createFileLoader(s32 threadPriority);
    void createMemorySystem(sead::Heap* heap);
    void createResourceSystem(const char* archivePath, s32, s32, bool);
    void createSaveDataSystem();

    al::MemorySystem* getMemorySystem() { return mMemorySystem; }
    al::FileLoader* getFileLoader() { return mFileLoader; }
    al::ResourceSystem* getResourceSystem() { return mResourceSystem; }
    al::SaveDataDirector* getSaveDataDirector() { return mSaveDataDirector; }
};
}

class alProjectInterface {
    static al::SystemKit* getSystemKit();
};
