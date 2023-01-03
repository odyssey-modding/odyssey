#include <al/Library/Resource/Resource.h>
#include <agl/g3d/aglNW4FToNN.h>
#include <heap/seadHeap.h>
#include <heap/seadHeapMgr.h>
#include <al/Library/File/FileUtil.h>

namespace al {
Resource::Resource(const sead::SafeString& path)
    : mArchive(nullptr), mDevice(nullptr), mName(path) {
    mHeap = sead::HeapMgr::sInstancePtr->getCurrentHeap();
    mData = nullptr;
    mResFile = nullptr;
    mArchive = al::loadArchive(path);
    mDevice = new sead::ArchiveFileDevice(mArchive);
}

Resource::Resource(const sead::SafeString& path, sead::ArchiveRes* archive)
    : mArchive(nullptr), mDevice(nullptr), mName(path) {
    mHeap = sead::HeapMgr::sInstancePtr->getCurrentHeap();
    mData = nullptr;
    mResFile = nullptr;
    mArchive = archive;
    mDevice = new sead::ArchiveFileDevice(mArchive);
}

bool Resource::isExistFile(const sead::SafeString& rFileName) const {
    bool ret = false;
    mDevice->tryIsExistFile(&ret, rFileName);
    return ret;
}

u32 Resource::getFileSize(const sead::SafeStringBase<char>& rFileName) const {
    auto device = mDevice;
    u32 ret = 0;
    device->tryGetFileSize(&ret, rFileName);
    return ret;
}

void Resource::cleanupResGraphicsFile() {
    if (!mResFile)
        return;

    mResFile->ReleaseTexture();
    mResFile->Reset();
    agl::g3d::ResFile::Cleanup(mResFile);
    mResFile = nullptr;
}
};  // namespace al
