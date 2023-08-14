#pragma once

#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/Movement/EnemyStateBlowDown.h>

class EnemyCap : public al::LiveActor {
private:
    al::LiveActor* mCap = nullptr;
    sead::Matrix34f* mCapBaseMtx = nullptr;
    bool mIsAtOrigin = true;
    sead::Vector3f mLocalTrans = sead::Vector3f(0.0f, 0.0f, 0.0f);
    sead::Vector3f mLocalRotate = sead::Vector3f(0.0f, 0.0f, 0.0f);
    sead::Vector3f mLocalScale = sead::Vector3f(1.0f, 1.0f, 1.0f);
    ;
    bool mCapVisible = false;
    bool mUseFollowMtxScale = false;
    bool field_142 = false;
    bool mUseLocalScale = true;
    al::EnemyStateBlowDown* mStateBlowDown = nullptr;

public:
    static EnemyCap* createEnemyCap(char const*);

    EnemyCap(char const*);
    void initPartsFixFile(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*);
    void makeActorAlive();
    void updatePose();
    void calcAnim();
    void exeWait();
    void syncHostVisible();
    void exeBlowDown();
    void startBlowDown(al::HitSensor const* source);
    void startBlowDown();
    bool isBlowDown() const;
    void setBlowDownParam(al::EnemyStateBlowDownParam const*);

    al::LiveActor* getCap() { return mCap; };
    al::EnemyStateBlowDown* getStateBlowDown() { return mStateBlowDown; };
};

namespace rs {
EnemyCap* tryCreateEnemyCap(al::LiveActor*, al::ActorInitInfo const&);
EnemyCap* tryCreateEnemyCap(al::LiveActor*, al::ActorInitInfo const&, char const*);
EnemyCap* tryCreateEnemyCapSuffix(al::LiveActor*, al::ActorInitInfo const&, char const*, char const*);
bool tryStartEnemyCapBlowDown(EnemyCap*, al::HitSensor const*);
bool tryStartEnemyCapBlowDown(EnemyCap*);
bool tryAppearEnemyCap(EnemyCap*);
bool isOnEnemyCap(EnemyCap*);
}  // namespace rs