#pragma once

#include "math/seadMatrix.h"
#include "math/seadVector.h"
namespace al {
class LiveActor;
class JointControllerBase;
class JointDirectionInfo;
class JointAimInfo;
class JointTranslateShaker;
class JointMasher;
class JointLookAtController;

void initJointControllerKeeper(const al::LiveActor*, int);
void isExistJointControllerKeeper(const al::LiveActor*);
void registerJointController(const al::LiveActor*, al::JointControllerBase*);
void registerJointController(const al::LiveActor*, al::JointControllerBase*, const char*);
void initJointLocalRotator(const al::LiveActor*, sead::Vector3f*, const char*);
void initJointLocalXRotator(const al::LiveActor*, const float*, const char*);
void initJointLocalYRotator(const al::LiveActor*, const float*, const char*);
void initJointLocalZRotator(const al::LiveActor*, const float*, const char*);
void initJointLocalAxisRotator(const al::LiveActor*, const sead::Vector3f&, const float*, const char*, bool);
void initJointLocalMinusXRotator(const al::LiveActor*, const float*, const char*);
void initJointLocalMinusYRotator(const al::LiveActor*, const float*, const char*);
void initJointLocalMinusZRotator(const al::LiveActor*, const float*, const char*);
void initJointGlobalXRotator(const al::LiveActor*, float*, const char*);
void initJointGlobalAxisRotator(const al::LiveActor*, const sead::Vector3f&, float*, const char*);
void initJointGlobalYRotator(const al::LiveActor*, float*, const char*);
void initJointGlobalZRotator(const al::LiveActor*, float*, const char*);
void initJointGlobalMinusXRotator(const al::LiveActor*, float*, const char*);
void initJointGlobalMinusYRotator(const al::LiveActor*, float*, const char*);
void initJointGlobalMinusZRotator(const al::LiveActor*, float*, const char*);
void initJointLocalTransControllerX(const al::LiveActor*, const float*, const char*);
void initJointLocalTransControllerY(const al::LiveActor*, const float*, const char*);
void initJointLocalTransControllerZ(const al::LiveActor*, const float*, const char*);
void initJointLocalTransController(const al::LiveActor*, const sead::Vector3f*, const char*);
void initJointLocalScaleControllerX(const al::LiveActor*, const float*, const char*);
void initJointLocalScaleControllerY(const al::LiveActor*, const float*, const char*);
void initJointLocalScaleControllerZ(const al::LiveActor*, const float*, const char*);
void initJointLocalScaleController(const al::LiveActor*, const sead::Vector3f*, const char*);
void initJointLocalMtxController(const al::LiveActor*, const sead::Matrix34f*, const char*);
void initJointGlobalMtxController(const al::LiveActor*, const sead::Matrix34f*, const char*);
void initJointGlobalQuatController(const al::LiveActor*, const sead::Quatf*, const char*);
void initJointGlobalQuatTransController(const al::LiveActor*, const sead::Quatf*, const sead::Vector3f*, const char*);
void initJointPostQuatController(const al::LiveActor*, const sead::Quatf*, const char*);
void initJointLocalDirController(const al::LiveActor*, const al::JointDirectionInfo*, const char*);
void initJointAimController(const al::LiveActor*, const al::JointAimInfo*, const char*);
void initJointTranslateShaker(const al::LiveActor*, int);
void appendJointTranslateShakerX(al::JointTranslateShaker*, const char*);
void appendJointTranslateShakerY(al::JointTranslateShaker*, const char*);
void appendJointTranslateShakerZ(al::JointTranslateShaker*, const char*);
void initJointMasher(const al::LiveActor*, const bool*, int);
void appendMashJoint(al::JointMasher*, const char*, float);
void initJointRumbler(const al::LiveActor*, const char*, float, float, unsigned int, int);
void initJointLocalQuatRotator(const al::LiveActor*, const char*, const sead::Quatf*);
void initJointLookAtController(const al::LiveActor*, int);
void appendJointLookAtController(al::JointLookAtController*, const al::LiveActor*, const char*, float, const sead::Vector2f&, const sead::Vector2f&,
                                 const sead::Vector3f&, const sead::Vector3f&);
void appendJointLookAtControllerNoJudge(al::JointLookAtController*, const al::LiveActor*, const char*, float, const sead::Vector2f&,
                                        const sead::Vector2f&, const sead::Vector3f&, const sead::Vector3f&);
void appendJointLookAtControllerNoJudgeNoOverLimitYaw(al::JointLookAtController*, const al::LiveActor*, const char*, float, const sead::Vector2f&,
                                                      const sead::Vector2f&, const sead::Vector3f&, const sead::Vector3f&);
void initJointGroundSmoothController(const al::LiveActor*, const char*);
void initJointPosToPosController(const al::LiveActor*, const char*, const sead::Vector3f*, const sead::Vector3f*, float*, const sead::Vector3f&);
void initJointSpringController(const al::LiveActor*, const char*);
void initJointConstrainedSpringController(const al::LiveActor*, const char*);
void initJointSpringTransController(const al::LiveActor*, const char*);
void initJointSimpleIK(const al::LiveActor*, const char*);
}  // namespace al
