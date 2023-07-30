#pragma once

#include <container/seadPtrArray.h>
#include <container/seadStrTreeMap.h>

namespace sead {
class MessageProject;
}
namespace al {
class MessageProjectEx;
class MessageHolder;
class MessageSystem {
    using MessageTreeMap = sead::StrTreeMap<256, al::MessageHolder*>;

private:
    MessageProjectEx* mMessageProject;
    sead::PtrArray<MessageTreeMap> mTreeMaps;
    sead::Heap* mMessageHeap;

public:
    MessageSystem();
    void initMessageForChangeLanguage();
    bool tryInitMessageHolder(MessageTreeMap*, const char*, const char*, const char*);

    sead::MessageProject* getMessageProject();
    al::MessageHolder* getMessageHolderCore(const char*, s32);
    al::MessageHolder* getMessageHolderCore(const char*, s32, const char*);
    al::MessageHolder* getSystemMessageHolder(const char*);
    al::MessageHolder* getSystemMessageHolder(const char*, const char*);
    al::MessageHolder* getLayoutMessageHolder(const char*);
    al::MessageHolder* getStageMessageHolder(const char*);
};
class IUseMessageSystem {
public:
    virtual const al::MessageSystem* getMessageSystem() const;
};
}  // namespace al
