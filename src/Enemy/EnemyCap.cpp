#include "Enemy/EnemyCap.h"
#include <al/Library/Base/String.h>
#include <al/Library/LiveActor/ActorActionFunction.h>
#include <al/Library/LiveActor/ActorFlagFunction.h>
#include <al/Library/LiveActor/ActorInitFunction.h>
#include <al/Library/LiveActor/ActorModelFunction.h>
#include <al/Library/LiveActor/ActorMovementFunction.h>
#include <al/Library/LiveActor/ActorResourceFunction.h>
#include <al/Library/LiveActor/LiveActorFunction.h>
#include <al/Library/Math/MathAngleUtil.h>
#include <al/Library/Movement/EnemyStateBlowDown.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Nerve/NerveUtil.h>
#include <al/Library/Obj/PartsFunction.h>
#include <al/Library/Placement/PlacementFunction.h>
#include <al/Library/Yaml/ByamlUtil.h>

namespace {
NERVE_IMPL(EnemyCap, Wait);
NERVE_IMPL(EnemyCap, BlowDown);

struct {
    NERVE_MAKE(EnemyCap, Wait);
    NERVE_MAKE(EnemyCap, BlowDown);
} NrvEnemyCap;

}  // namespace

EnemyCap* EnemyCap::createEnemyCap(const char* name) {
    return new EnemyCap(name);
}

EnemyCap::EnemyCap(const char* name) : al::LiveActor(name) {}

static al::EnemyStateBlowDownParam* fallbackStateBlowDownParam = new al::EnemyStateBlowDownParam();

// NON_MATCHING: Unsure how the al::StringTmp here works
void EnemyCap::initPartsFixFile(al::LiveActor* actor, const al::ActorInitInfo& initInfo, const char* archiveName, const char* suffix) {
    mCap = actor;
    mCapBaseMtx = mCap->getBaseMtx();
    al::initChildActorWithArchiveNameNoPlacementInfo(this, initInfo, archiveName, 0);
    al::initNerve(this, &NrvEnemyCap.Wait, 1);
    mStateBlowDown = new al::EnemyStateBlowDown(this, fallbackStateBlowDownParam, "吹き飛び状態");
    al::initNerveState(this, mStateBlowDown, &NrvEnemyCap.BlowDown, "吹き飛び");

    al::StringTmp<128> test("");

    al::createFileNameBySuffix(&test, "InitPartsFixInfo", suffix);
    if (!al::isExistModelResourceYaml(mCap, test.cstr(), 0))
        return makeActorAlive();
    al::ByamlIter resourceYaml = al::getModelResourceYaml(mCap, test.cstr(), 0);
    const char* jointName = 0;
    resourceYaml.tryGetStringByKey(&jointName, "JointName");
    if (jointName)
        mCapBaseMtx = al::getJointMtxPtr(mCap, jointName);
    al::tryGetByamlV3f(&mLocalTrans, resourceYaml, "LocalTrans");
    al::tryGetByamlV3f(&mLocalRotate, resourceYaml, "LocalRotate");
    al::tryGetByamlV3f(&mLocalScale, resourceYaml, "LocalScale");
    if (!al::isNearZero(mLocalTrans, 0.001f) || !al::isNearZero(mLocalRotate, 0.001f))
        mIsAtOrigin = true;
    mUseFollowMtxScale = al::tryGetByamlKeyBoolOrFalse(resourceYaml, "UseFollowMtxScale");
    mUseLocalScale = al::tryGetByamlKeyBoolOrFalse(resourceYaml, "UseLocalScale");
    makeActorAlive();
}

void EnemyCap::makeActorAlive() {
    al::invalidateClipping(this);
    al::offCollide(this);
    al::setVelocityZero(this);
    updatePose();
    al::LiveActor::makeActorAlive();
    this->mCapVisible = 0;
    al::setNerve(this, &NrvEnemyCap.Wait);
}

void EnemyCap::calcAnim() {
    if (al::isNerve(this, &NrvEnemyCap.Wait)) {
        updatePose();
    }
    al::LiveActor::calcAnim();
}

void EnemyCap::exeWait() {
    if (!al::updateSyncHostVisible(&mCapVisible, this, mCap, field_142))
        return;
    al::setModelAlphaMask(this, al::getModelAlphaMask(mCap));
}

void EnemyCap::syncHostVisible() {
    al::updateSyncHostVisible(&mCapVisible, this, mCap, field_142);
}

void EnemyCap::exeBlowDown() {
    if (al::isFirstStep(this)) {
        al::onCollide(this);
        al::offSyncClippingSubActor(mCap, this);
        al::offSyncAlphaMaskSubActor(mCap, this);
    }
    al::rotateQuatXDirDegree(this, -15.0f);
    if (!al::updateNerveState(this))
        return;
    al::offCollide(this);
    al::startHitReaction(this, "消滅");
    al::onSyncClippingSubActor(mCap, this);
    al::onSyncAlphaMaskSubActor(mCap, this);
    kill();
}

void EnemyCap::startBlowDown(const al::HitSensor* source) {
    if (al::isNerve(this, &NrvEnemyCap.BlowDown))
        return;
    mStateBlowDown->start(source);
    al::setNerve(this, &NrvEnemyCap.BlowDown);
}

void EnemyCap::startBlowDown() {
    if (al::isNerve(this, &NrvEnemyCap.BlowDown))
        return;
    mStateBlowDown->start(mCap);
    al::setNerve(this, &NrvEnemyCap.BlowDown);
}

bool EnemyCap::isBlowDown() const {
    return al::isNerve(this, &NrvEnemyCap.BlowDown);
}

void EnemyCap::setBlowDownParam(const al::EnemyStateBlowDownParam* param) {
    mStateBlowDown->setParam(param);
}

namespace rs {
EnemyCap* tryCreateEnemyCap(al::LiveActor* actor, const al::ActorInitInfo& info) {
    const char* str = 0;
    al::tryGetStringArg(&str, info, "CapName");
    return rs::tryCreateEnemyCapSuffix(actor, info, str, str);
}

EnemyCap* tryCreateEnemyCap(al::LiveActor* actor, const al::ActorInitInfo& info, const char* archiveName) {
    return rs::tryCreateEnemyCapSuffix(actor, info, archiveName, archiveName);
}

EnemyCap* tryCreateEnemyCapSuffix(al::LiveActor* actor, const al::ActorInitInfo& info, const char* archiveName, const char* suffix) {
    if (!archiveName)
        return 0;
    auto cap = new EnemyCap("帽子");
    if (!al::isExistSubActorKeeper(actor))
        al::initSubActorKeeperNoFile(actor, info, 1);
    cap->initPartsFixFile(actor, info, archiveName, suffix);
    al::registerSubActor(actor, cap);
    al::onSyncClippingSubActor(actor, cap);
    al::onSyncAlphaMaskSubActor(actor, cap);
    return cap;
}

bool tryStartEnemyCapBlowDown(EnemyCap* cap, const al::HitSensor* sensor) {
    if (!isOnEnemyCap(cap)) return false;
    if (al::isNerve(cap, &NrvEnemyCap.BlowDown))
        return true;
    cap->getStateBlowDown()->start(sensor);
    al::setNerve(cap, &NrvEnemyCap.BlowDown);
    return true;
}

bool tryStartEnemyCapBlowDown(EnemyCap* cap) {
    if (!isOnEnemyCap(cap)) return false;
    if (al::isNerve(cap, &NrvEnemyCap.BlowDown))
        return true;
    cap->getStateBlowDown()->start(cap->getCap());
    al::setNerve(cap, &NrvEnemyCap.BlowDown);
    return true;
}

bool tryAppearEnemyCap(EnemyCap* cap) {
    if (!cap)
        return false;
    cap->appear();
    return true;
}

bool isOnEnemyCap(EnemyCap* cap) {
    return cap && !al::isNerve(cap, &NrvEnemyCap.BlowDown);
}

}  // namespace rs