#pragma once

#include <al/Library/Name/IUseName.h>
#include <basis/seadTypes.h>

namespace al {
class StageSwitchAccesser;
class StageSwitchDirector;
class PlacementInfo;
class StageSwitchKeeper {
private:
    al::StageSwitchAccesser* mStageSwitchAccessers;
    s32 mAccesserNum;
    void* field_10;

public:
    StageSwitchKeeper();
    void init(al::StageSwitchDirector*, const al::PlacementInfo&);
    al::StageSwitchAccesser* tryGetStageSwitchAccesser(const char* name);
};
class IUseStageSwitch : public virtual al::IUseName {
public:
    virtual al::StageSwitchKeeper* getStageSwitchKeeper() const = 0;
    virtual void initStageSwitchKeeper() = 0;
};
}  // namespace al
