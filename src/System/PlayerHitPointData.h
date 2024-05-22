#pragma once

#include <basis/seadTypes.h>

namespace al {
    class ByamlIter;
    class ByamlWriter;
}

class PlayerHitPointData {
private:
    bool mIsKidsMode = false;
    s32 mCurrentHit = 0;
    bool mIsHaveMaxUpItem = false;
    bool mIsForceNormalHealth = false;

public:
    PlayerHitPointData();
    void setKidsModeFlag(bool isKidsMode);
    void init();
    void recoverMax();
    s32 getCurrent() const;
    s32 getMaxCurrent() const;
    s32 getMaxWithItem() const;
    s32 getMaxWithoutItem() const;
    bool isMaxCurrent() const;
    bool isMaxWithItem() const;
    void getMaxUpItem();
    void recover();
    void recoverForDebug();
    void damage();
    void kill();
    void forceNormalMode();
    void endForceNormalMode();
    bool isForceNormalMode() const;
    virtual void write(al::ByamlWriter*);
    virtual void read(const al::ByamlIter&);
};