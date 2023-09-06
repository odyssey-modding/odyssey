#include "al/Library/Area/AreaObj.h"

#include "al/Library/Area/AreaInitInfo.h"
#include "al/Library/Area/AreaObjGroup.h"
#include "al/Library/Area/AreaShape.h"
#include "al/Library/Factory/Factory.h"
#include "al/Library/LiveActor/ActorInitFunction.h"
#include "al/Library/Placement/PlacementFunction.h"
#include "al/Library/Placement/PlacementInfo.h"
#include "al/Library/Stage/ListenStageSwitch.h"
#include "al/Library/Stage/StageSwitchUtil.h"
#include "al/Library/String/StringUtil.h"
#include "al/Library/Thread/FunctorV0M.h"

namespace al {

AreaObj::AreaObj(const char* name) : mName(name) {}

const char* AreaObj::getName() const {
    return mName;
}

al::StageSwitchKeeper* AreaObj::getStageSwitchKeeper() const {
    return mStageSwitchKeeper;
}

void AreaObj::initStageSwitchKeeper() {
    mStageSwitchKeeper = new al::StageSwitchKeeper();
}

// NOT MATCHING -- 1 instruction out of order for `const char* entryName = areaShapeFactory.convertName(modelName);`
void AreaObj::init(const al::AreaInitInfo& initInfo) {
    mPlacementInfo = new al::PlacementInfo(initInfo);
    mSceneObjHolder = initInfo.getSceneObjHolder();
    al::tryGetMatrixTR(&mMatrixTR, *mPlacementInfo);
    al::tryGetArg(&mPriority, *mPlacementInfo, "Priority");

    const char* modelName = nullptr;
    alPlacementFunction::tryGetModelName(&modelName, *mPlacementInfo);

    al::AreaShapeFactory areaShapeFactory("エリアシェイプファクトリー");
    mAreaShape = areaShapeFactory.getCreationFunction(modelName)();

    mAreaShape->setBaseMtxPtr(&mMatrixTR);
    sead::Vector3f scale({1.0, 1.0, 1.0});
    al::tryGetScale(&scale, *mPlacementInfo);
    mAreaShape->setScale(scale);

    al::initStageSwitch(this, initInfo.getStageSwitchDirector(), initInfo);
    if (al::listenStageSwitchOnOffAppear(this, al::FunctorV0M<al::AreaObj*, void (AreaObj::*)()>(this, &AreaObj::invalidate),
                                         al::FunctorV0M<al::AreaObj*, void (AreaObj::*)()>(this, &AreaObj::validate)))
        invalidate();

    if (al::listenStageSwitchOnKill(this, al::FunctorV0M<al::AreaObj*, void (AreaObj::*)()>(this, &AreaObj::validate)))
        validate();
}

bool AreaObj::isInVolume(const sead::Vector3f& position) const {
    if (!isValid)
        return false;
    return mAreaShape->isInVolume(position);
}

bool AreaObj::isInVolumeOffset(const sead::Vector3f& position, f32 offset) const {
    if (!isValid)
        return false;
    return mAreaShape->isInVolumeOffset(position, offset);
}

al::SceneObjHolder* AreaObj::getSceneObjHolder() const {
    return mSceneObjHolder;
}

void AreaObj::validate() {
    isValid = true;
}

void AreaObj::invalidate() {
    isValid = false;
}

// not even CLOSE to matching
AreaObj* createAreaObj(const al::ActorInitInfo& actorInitInfo, const char* name) {
    al::AreaInitInfo areaInitInfo;
    areaInitInfo.set(actorInitInfo.getPlacementInfo(), actorInitInfo.getStageSwitchDirector(), actorInitInfo.getSceneObjHolder());
    AreaObj* areaObj = new AreaObj(name);
    areaObj->init(areaInitInfo);
    return areaObj;
}

template <typename T>
AreaObj* createAreaObjFunction(const char* name) {
    return new T(name);
}

AreaObjFactory::AreaObjFactory(const char* factoryName) : Factory<al::AreaObj* (*)()>(factoryName) {}

s32 AreaObjFactory::tryFindAddBufferSize(const char* bufferName) const {
    if (mAddBuffer == nullptr || mNumBuffers < 1)
        return 0;
    
    s32 offset = 0;
    while (!isEqualString(bufferName, mAddBuffer[offset].name)) {
        if (++offset >= mNumBuffers)
            return 0;        
    }
    return mAddBuffer[offset].size;
}

}  // namespace al