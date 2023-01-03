#pragma once

#include <gfx/seadColor.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class ActorInitInfo;
class AreaInitInfo;
class PlacementInfo;
class PlacementId;

bool isValidInfo(const al::PlacementInfo& placementInfo);
bool isPlaced(const al::PlacementInfo& placementInfo);

void getObjectName(const char** name, const al::ActorInitInfo& initInfo);
void getObjectName(const char** name, const al::PlacementInfo& placementInfo);
bool tryGetObjectName(const char** name, const al::ActorInitInfo& initInfo);
bool tryGetObjectName(const char** name, const al::PlacementInfo& placementInfo);
bool isObjectName(const al::ActorInitInfo& initInfo, const char* name);
bool isObjectName(const al::PlacementInfo& placementInfo, const char* name);
bool isObjectNameSubStr(const al::ActorInitInfo& initInfo, const char* name);
bool isObjectNameSubStr(const al::PlacementInfo& placementInfo, const char* name);

void getClassName(const char** name, const al::ActorInitInfo& initInfo);
void getClassName(const char** name, const al::PlacementInfo& placementInfo);
bool tryGetClassName(const char** name, const al::ActorInitInfo& initInfo);
bool tryGetClassName(const char** name, const al::PlacementInfo& placementInfo);

void getDisplayName(const char** name, const al::ActorInitInfo& initInfo);
void getDisplayName(const char** name, const al::PlacementInfo& placementInfo);
bool tryGetDisplayName(const char** name, const al::ActorInitInfo& initInfo);
bool tryGetDisplayName(const char** name, const al::PlacementInfo& placementInfo);

bool tryGetPlacementInfoByKey(al::PlacementInfo* outPlacementInfo,
                              const al::PlacementInfo& placementInfo, const char* key);

void getPlacementTargetFile(const char** targetFile, const al::PlacementInfo& placementInfo);

void getTrans(sead::Vector3f* trans, const al::ActorInitInfo& initInfo);
void getTrans(sead::Vector3f* trans, const al::PlacementInfo& placementInfo);
void multZoneMtx(sead::Vector3f* trans, const al::PlacementInfo& placementInfo);
bool tryGetTrans(sead::Vector3f* trans, const al::ActorInitInfo& initInfo);
bool tryGetTrans(sead::Vector3f* trans, const al::PlacementInfo& placementInfo);

void getRotate(sead::Vector3f* rotate, const al::ActorInitInfo& initInfo);
void getRotate(sead::Vector3f* rotate, const al::PlacementInfo& placementInfo);
bool tryGetRotate(sead::Vector3f* rotate, const al::ActorInitInfo& initInfo);
bool tryGetRotate(sead::Vector3f* rotate, const al::PlacementInfo& placementInfo);
void tryGetZoneMatrixTR(sead::Matrix34f* matrix, const al::PlacementInfo& placementInfo);

void getQuat(sead::Quatf* quat, const al::ActorInitInfo& initInfo);
void getQuat(sead::Quatf* quat, const al::PlacementInfo& placementInfo);
bool tryGetQuat(sead::Quatf* quat, const al::ActorInitInfo& initInfo);
bool tryGetQuat(sead::Quatf* quat, const al::PlacementInfo& placementInfo);

void getScale(sead::Vector3f* scale, const al::ActorInitInfo& initInfo);
void getScale(sead::Vector3f* scale, const al::PlacementInfo& placementInfo);
bool tryGetScale(sead::Vector3f* scale, const al::ActorInitInfo& initInfo);
bool tryGetScale(sead::Vector3f* scale, const al::PlacementInfo& placementInfo);

void getSide(sead::Vector3f* side, const al::ActorInitInfo& initInfo);
void getSide(sead::Vector3f* side, const al::PlacementInfo& placementInfo);
bool tryGetSide(sead::Vector3f* side, const al::ActorInitInfo& initInfo);
bool tryGetSide(sead::Vector3f* side, const al::PlacementInfo& placementInfo);

void getUp(sead::Vector3f* up, const al::ActorInitInfo& initInfo);
void getUp(sead::Vector3f* up, const al::PlacementInfo& placementInfo);
bool tryGetUp(sead::Vector3f* up, const al::ActorInitInfo& initInfo);
bool tryGetUp(sead::Vector3f* up, const al::PlacementInfo& placementInfo);

void getFront(sead::Vector3f* front, const al::ActorInitInfo& initInfo);
void getFront(sead::Vector3f* front, const al::PlacementInfo& placementInfo);
bool tryGetFront(sead::Vector3f* front, const al::ActorInitInfo& initInfo);
bool tryGetFront(sead::Vector3f* front, const al::PlacementInfo& placementInfo);

bool tryGetLocalAxis(sead::Vector3f* front, const al::ActorInitInfo& initInfo, s32 axis);
bool tryGetLocalAxis(sead::Vector3f* front, const al::PlacementInfo& placementInfo, s32 axis);
bool tryGetLocalSignAxis(sead::Vector3f* front, const al::ActorInitInfo& initInfo, s32 axis);
bool tryGetLocalSignAxis(sead::Vector3f* front, const al::PlacementInfo& placementInfo, s32 axis);

bool tryGetMatrixTR(sead::Matrix34f* matrix, const al::ActorInitInfo& initInfo);
bool tryGetMatrixTR(sead::Matrix34f* matrix, const al::PlacementInfo& placementInfo);
bool tryGetMatrixTRS(sead::Matrix34f* matrix, const al::ActorInitInfo& initInfo);
bool tryGetMatrixTRS(sead::Matrix34f* matrix, const al::PlacementInfo& placementInfo);
bool tryGetInvertMatrixTR(sead::Matrix34f* matrix, const al::ActorInitInfo& initInfo);
bool tryGetInvertMatrixTR(sead::Matrix34f* matrix, const al::PlacementInfo& placementInfo);

void calcMatrixMultParent(sead::Matrix34f* matrix, const al::ActorInitInfo& initInfo);
void calcMatrixMultParent(sead::Matrix34f* matrix, const al::PlacementInfo& placementInfo);

bool getArg(s32* arg, const al::ActorInitInfo& initInfo, const char* key);
bool getArg(s32* arg, const al::PlacementInfo& placementInfo, const char* key);
bool tryGetArg(s32* arg, const al::ActorInitInfo& initInfo, const char* key);
bool tryGetArg(s32* arg, const al::PlacementInfo& placementInfo, const char* key);
bool getArg(f32* arg, const al::ActorInitInfo& initInfo, const char* key);
bool getArg(f32* arg, const al::PlacementInfo& placementInfo, const char* key);
bool tryGetArg(f32* arg, const al::ActorInitInfo& initInfo, const char* key);
bool tryGetArg(f32* arg, const al::PlacementInfo& placementInfo, const char* key);
bool getArg(bool* arg, const al::ActorInitInfo& initInfo, const char* key);
bool getArg(bool* arg, const al::PlacementInfo& placementInfo, const char* key);
bool tryGetArg(bool* arg, const al::ActorInitInfo& initInfo, const char* key);
bool tryGetArg(bool* arg, const al::PlacementInfo& placementInfo, const char* key);

s32 getArgS32(const al::ActorInitInfo& actorInitInfo, const char* key);
f32 getArgF32(const al::ActorInitInfo& actorInitInfo, const char* key);
bool getArgV3f(sead::Vector3f* arg, const al::ActorInitInfo& actorInitInfo, const char* key);
bool getArgV3f(sead::Vector3f* arg, const al::PlacementInfo& placementInfo, const char* key);
bool tryGetArgV3f(sead::Vector3f* arg, const al::ActorInitInfo& actorInitInfo, const char* key);
bool tryGetArgV3f(sead::Vector3f* arg, const al::PlacementInfo& placementInfo, const char* key);

bool isArgBool(const al::ActorInitInfo& initInfo, const char* key);
bool isArgBool(const al::PlacementInfo& placementInfo, const char* key);
bool isArgString(const al::ActorInitInfo& initInfo, const char* arg, const char* key);
bool isArgString(const al::PlacementInfo& placementInfo, const char* arg, const char* key);

void getStringArg(const char** arg, const al::ActorInitInfo& initInfo, const char* key);
void getStringArg(const char** arg, const al::PlacementInfo& placementInfo, const char* key);
void getStringArg(const char** arg, const al::AreaInitInfo& initInfo, const char* key);
void getStringArg(const al::ActorInitInfo& initInfo, const char* key);
void getStringArg(const al::PlacementInfo& placementInfo, const char* key);
void getStringArg(const al::AreaInitInfo& initInfo, const char* key);
bool tryGetStringArg(const char** arg, const al::ActorInitInfo& initInfo, const char* key);
bool tryGetStringArg(const char** arg, const al::AreaInitInfo& initInfo, const char* key);
bool tryGetArgV2f(sead::Vector2f* arg, const al::ActorInitInfo& initInfo, const char* key);
bool tryGetArgV2f(sead::Vector2f* arg, const al::PlacementInfo& initInfo, const char* key);
bool tryGetArgColor(sead::Color4f* arg, const al::ActorInitInfo& initInfo, const char* key);
bool tryGetArgColor(sead::Color4f* arg, const al::PlacementInfo& initInfo, const char* key);

void getLayerConfigName(const char** name, const al::ActorInitInfo& initInfo);
void getLayerConfigName(const char** name, const al::PlacementInfo& initInfo);
bool tryGetZoneNameIfExist(const char** name, const al::PlacementInfo& placementInfo);
void getPlacementId(al::PlacementId* placementId, const al::PlacementInfo& placementInfo);

bool tryGetBoolArgOrFalse(const al::ActorInitInfo& initInfo, const char* key);
s32 getCountPlacementInfo(const al::PlacementInfo& placementInfo);
void getPlacementInfoByKey(al::PlacementInfo* outPlacementInfo, const al::PlacementInfo&,
                           const char* key);
void getPlacementInfoByIndex(al::PlacementInfo* outPlacementInfo, const al::PlacementInfo&,
                             s32 index);
bool tryGetPlacementInfoByIndex(al::PlacementInfo* outPlacementInfo, const al::PlacementInfo&,
                                s32 index);
bool getPlacementInfoAndKeyNameByIndex(al::PlacementInfo* outPlacementInfo, const char** outKey,
                                       const al::PlacementInfo&, s32 index);
bool tryGetPlacementInfoAndKeyNameByIndex(al::PlacementInfo* outPlacementInfo, const char** outKey,
                                          const al::PlacementInfo&, s32 index);

al::PlacementId* createPlacementId(const al::ActorInitInfo& initInfo);
al::PlacementId* createPlacementId(const al::PlacementInfo& placementInfo);
bool tryGetPlacementId(al::PlacementId* placementId, const al::ActorInitInfo& initInfo);
bool tryGetPlacementId(al::PlacementId* placementId, const al::PlacementInfo& placementInfo);
void getPlacementId(al::PlacementId* placementId, const al::ActorInitInfo& initInfo);
bool isEqualPlacementId(al::PlacementId* placementId, const al::PlacementId& otherPlacementId);
bool isEqualPlacementId(al::PlacementId* placementId, const al::PlacementInfo& placementInfo);

bool isExistRail(const al::ActorInitInfo& initInfo, const char* linkName);

bool tryGetRailIter(al::PlacementInfo& railPlacementInfo, const al::PlacementInfo& placementInfo,
                    const char* linkName);
bool tryGetLinksInfo(al::PlacementInfo& railPlacementInfo, const al::PlacementInfo& placementInfo,
                     const char* linkName);
bool tryGetMoveParameterRailIter(al::PlacementInfo& railPlacementInfo,
                                 const al::PlacementInfo& placementInfo);
bool tryGetRailPointPos(sead::Vector3f* railPoint,
                        const al::PlacementInfo& placementInfo);
void getRailPointHandlePrev(sead::Vector3f* railPoint, const al::PlacementInfo& placementInfo);
void tryGetRailPointHandlePrev(sead::Vector3f* railPoint, const al::PlacementInfo& placementInfo);
void getRailPointHandleNext(sead::Vector3f* railPoint, const al::PlacementInfo& placementInfo);
void tryGetRailPointHandleNext(sead::Vector3f* railPoint, al::PlacementInfo const& placementInfo);

bool isExistGraphRider(const al::ActorInitInfo& initInfo);

s32 calcLinkChildNum(const al::ActorInitInfo& initInfo, const char* linkName);
s32 calcLinkChildNum(const al::PlacementInfo& placementInfo, const char* linkName);

bool isExistLinkChild(const al::ActorInitInfo& initInfo, const char* linkName, s32 index);
bool isExistLinkChild(const al::PlacementInfo& placementInfo, const char* linkName, s32 index);
bool isExistLinkChild(const al::PlacementInfo& placementInfo, const char* linkName, s32 index);

s32 calcLinkNestNum(const al::ActorInitInfo& initInfo, const char* linkName);
s32 calcLinkNestNum(const al::PlacementInfo& placementInfo, const char* linkName);

void getLinksInfo(al::PlacementInfo* linkPlacementInfo, const al::PlacementInfo& placementInfo,
                  const char* linkName);
void getLinksInfoByIndex(al::PlacementInfo* linkPlacementInfo,
                         const al::PlacementInfo& placementInfo, const char* linkName, s32);
void getLinksInfo(al::PlacementInfo* linkPlacementInfo, const al::ActorInitInfo& initInfo,
                  const char* linkName);
void getLinksInfoByIndex(al::PlacementInfo* linkPlacementInfo, const al::ActorInitInfo& initInfo,
                         const char* linkName, s32);
bool tryGetLinksInfo(al::PlacementInfo* linkPlacementInfo, const al::ActorInitInfo& initInfo,
                     const char* linkName);

void getLinksMatrix(sead::Matrix34f* matrix, const al::ActorInitInfo& initInfo,
                    const char* linkName);
void getLinksMatrixByIndex(sead::Matrix34f*, const al::ActorInitInfo& initInfo,
                           const char* linkName, s32);
void getLinkTR(sead::Vector3f* trans, sead::Vector3f* rotate,
               const al::PlacementInfo& placementInfo, const char* linkName);
void getLinkTR(sead::Vector3f* trans, sead::Vector3f* rotate, const al::ActorInitInfo& initInfo,
               const char* linkName);
void getLinkTR(sead::Vector3f* trans, sead::Vector3f* rotate, const al::AreaInitInfo& initInfo,
               const char* linkName);
void getLinksQT(sead::Quatf* quat, sead::Vector3f* trans, const al::ActorInitInfo& initInfo,
                const char* linkName);
void getLinksQT(sead::Quatf* quat, sead::Vector3f* trans, const al::PlacementInfo& placementInfo,
                const char* linkName);

bool tryGetLinksQT(sead::Quatf*, sead::Vector3f*, const al::ActorInitInfo& initInfo,
                   const char* linkName);
bool tryGetLinksQTS(sead::Quatf*, sead::Vector3f*, sead::Vector3f*,
                    const al::ActorInitInfo& initInfo, const char* linkName);
bool tryGetLinksMatrixTR(sead::Matrix34f* matrix, const al::ActorInitInfo& initInfo,
                         const char* linkName);
bool tryGetLinksMatrixTR(sead::Matrix34f* matrix, const al::AreaInitInfo& initInfo,
                         const char* linkName);
bool tryGetLinksMatrixTRS(sead::Matrix34f* matrix, const al::ActorInitInfo& initInfo,
                          const char* linkName);
bool tryGetLinksTrans(sead::Vector3f* trans, const al::ActorInitInfo& initInfo,
                      const char* linkName);
bool tryGetLinksTrans(sead::Vector3f* trans, const al::PlacementInfo& placementInfo,
                      const char* linkName);
bool tryGetLinksQuat(sead::Quatf* quat, const al::ActorInitInfo& initInfo, const char* linkName);
bool tryGetLinksTR(sead::Vector3f* trans, sead::Vector3f* rotate, const al::ActorInitInfo& initInfo,
                   const char* linkName);

void getChildTrans(sead::Vector3f* trans, const al::PlacementInfo& placementInfo,
                   const char* linkName);
void getChildTrans(sead::Vector3f* trans, const al::ActorInitInfo& initInfo, const char* linkName);
void getChildTrans(sead::Vector3f* trans, const al::AreaInitInfo& initInfo, const char* linkName);
void getChildLinkT(sead::Vector3f* trans, const al::ActorInitInfo& initInfo, const char* linkName,
                   s32 index);
void getChildLinkTR(sead::Vector3f* trans, sead::Vector3f* rotate,
                    const al::ActorInitInfo& initInfo, const char* linkName, s32 index);

s32 calcMatchNameLinkCount(const al::PlacementInfo& placementInfo, const char* linkName);
s32 calcLinkCountClassName(const al::PlacementInfo& placementInfo, const char* linkName);

bool tryGetZoneMatrixTR(sead::Matrix34f* matrix, const al::ActorInitInfo& initInfo);
bool tryGetDisplayOffset(sead::Vector3f* offset, const al::ActorInitInfo& initInfo);
bool tryGetDisplayOffset(sead::Vector3f* offset, const al::PlacementInfo& placementInfo);
bool tryGetChildDisplayOffset(sead::Vector3f* offset, const al::ActorInitInfo& initInfo,
                              const char* linkName);
bool tryGetDisplayRotate(sead::Vector3f* rotate, const al::ActorInitInfo& initInfo);
bool tryGetDisplayScale(sead::Vector3f* scale, const al::ActorInitInfo& initInfo);

}  // namespace al

class alPlacementFunction {
    s32 getCameraId(const al::ActorInitInfo& initInfo);
    void getLinkGroupId(al::PlacementId* groupId, const al::ActorInitInfo& initInfo, const char* linkName);
    bool isEnableLinkGroupId(const al::ActorInitInfo& initInfo, const char* linkName);
    bool isEnableGroupClipping(const al::ActorInitInfo& initInfo);
    void getClippingGroupId(al::PlacementId* groupId, const al::ActorInitInfo& initInfo);
    void createClippingViewId(const al::PlacementInfo& placementInfo);
    void getClippingViewId(al::PlacementId* viewId, const al::PlacementInfo& placementInfo);
    void getClippingViewId(al::PlacementId* viewId, const al::ActorInitInfo& initInfo);
    void getModelName(const char** modelName, const al::ActorInitInfo& initInfo);
    void getModelName(const char** modelName, const al::PlacementInfo& placementInfo);
    bool tryGetModelName(const char** modelName, const al::PlacementInfo& placementInfo);
    bool tryGetModelName(const char** modelName, const al::ActorInitInfo& initInfo);
};
