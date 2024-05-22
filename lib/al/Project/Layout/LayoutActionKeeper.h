#pragma once

#include <al/Library/Name/IUseName.h>
#include <basis/seadTypes.h>


namespace al {
class LayoutPaneGroup;
class LayoutKeeper;
class IUseAudioKeeper;
class IUseEffectKeeper;
class LayoutActionKeeper {
private:
    bool mHasStartedAction;
    al::LayoutPaneGroup* mLayoutPaneGroups;
    u32 mPaneGroupNum;
    const char* mMainGroupName;

public:
    LayoutActionKeeper(al::LayoutKeeper*, al::IUseAudioKeeper*, al::IUseEffectKeeper*);
    void startAction(const char* actionName, const char* groupName);
    void findPaneGroupInfo(const char* groupName);
    void update();
    void setMainGroupName(const char* groupName);
    void getLayoutPaneGroup(const char* groupName);
};

class IUseLayoutAction : virtual public al::IUseName {
public:
    virtual al::LayoutActionKeeper* getLayoutActionKeeper() const = 0;
};
}  // namespace al
