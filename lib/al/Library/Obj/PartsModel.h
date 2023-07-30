#pragma once

#include <al/Library/LiveActor/LiveActor.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {

class PartsModel : public al::LiveActor {
    al::LiveActor* mLiveActor;
    sead::Matrix34f* mMatrix;
    bool mUseLocalTransforms;
    sead::Vector3f mLocalTrans;
    sead::Vector3f mLocalRotate;
    sead::Vector3f mLocalScale;
    bool mUseFollowMtxScale;
    bool mUseLocalScale;
    bool mUpdate;

public:
    PartsModel(const char*);
    void initPartsDirect(al::LiveActor*, const al::ActorInitInfo&, const char*, const sead::Matrix34f*, const sead::Vector3f&, const sead::Vector3f&,
                         const sead::Vector3f&, bool);
    void initPartsSuffix(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const sead::Matrix34f*, bool);
    void initPartsMtx(al::LiveActor*, const al::ActorInitInfo&, const char*, const sead::Matrix34f*, bool);
    void initPartsFixFile(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const char*);
    void initPartsFixFileNoRegister(al::LiveActor*, const al::ActorInitInfo&, const char*, const char*, const char*);
    void endClipped() override;
    void updatePose();
    void calcAnim() override;
    void attackSensor(al::HitSensor*, al::HitSensor*) override;
    bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*) override;
    void offSyncAppearAndHide();
    void onSyncAppearAndHide();
};

}  // namespace al
