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

    void initJointControllerKeeper(al::LiveActor const*,int);
    void isExistJointControllerKeeper(al::LiveActor const*);
    void registerJointController(al::LiveActor const*,al::JointControllerBase *);
    void registerJointController(al::LiveActor const*,al::JointControllerBase *,char const*);
    void initJointLocalRotator(al::LiveActor const*,sead::Vector3<float> *,char const*);
    void initJointLocalXRotator(al::LiveActor const*,float const*,char const*);
    void initJointLocalYRotator(al::LiveActor const*,float const*,char const*);
    void initJointLocalZRotator(al::LiveActor const*,float const*,char const*);
    void initJointLocalAxisRotator(al::LiveActor const*,sead::Vector3<float> const&,float const*,char const*,bool);
    void initJointLocalMinusXRotator(al::LiveActor const*,float const*,char const*);
    void initJointLocalMinusYRotator(al::LiveActor const*,float const*,char const*);
    void initJointLocalMinusZRotator(al::LiveActor const*,float const*,char const*);
    void initJointGlobalXRotator(al::LiveActor const*,float *,char const*);
    void initJointGlobalAxisRotator(al::LiveActor const*,sead::Vector3<float> const&,float *,char const*);
    void initJointGlobalYRotator(al::LiveActor const*,float *,char const*);
    void initJointGlobalZRotator(al::LiveActor const*,float *,char const*);
    void initJointGlobalMinusXRotator(al::LiveActor const*,float *,char const*);
    void initJointGlobalMinusYRotator(al::LiveActor const*,float *,char const*);
    void initJointGlobalMinusZRotator(al::LiveActor const*,float *,char const*);
    void initJointLocalTransControllerX(al::LiveActor const*,float const*,char const*);
    void initJointLocalTransControllerY(al::LiveActor const*,float const*,char const*);
    void initJointLocalTransControllerZ(al::LiveActor const*,float const*,char const*);
    void initJointLocalTransController(al::LiveActor const*,sead::Vector3<float> const*,char const*);
    void initJointLocalScaleControllerX(al::LiveActor const*,float const*,char const*);
    void initJointLocalScaleControllerY(al::LiveActor const*,float const*,char const*);
    void initJointLocalScaleControllerZ(al::LiveActor const*,float const*,char const*);
    void initJointLocalScaleController(al::LiveActor const*,sead::Vector3<float> const*,char const*);
    void initJointLocalMtxController(al::LiveActor const*,sead::Matrix34<float> const*,char const*);
    void initJointGlobalMtxController(al::LiveActor const*,sead::Matrix34<float> const*,char const*);
    void initJointGlobalQuatController(al::LiveActor const*,sead::Quat<float> const*,char const*);
    void initJointGlobalQuatTransController(al::LiveActor const*,sead::Quat<float> const*,sead::Vector3<float> const*,char const*);
    void initJointPostQuatController(al::LiveActor const*,sead::Quat<float> const*,char const*);
    void initJointLocalDirController(al::LiveActor const*,al::JointDirectionInfo const*,char const*);
    void initJointAimController(al::LiveActor const*,al::JointAimInfo const*,char const*);
    void initJointTranslateShaker(al::LiveActor const*,int);
    void appendJointTranslateShakerX(al::JointTranslateShaker *,char const*);
    void appendJointTranslateShakerY(al::JointTranslateShaker *,char const*);
    void appendJointTranslateShakerZ(al::JointTranslateShaker *,char const*);
    void initJointMasher(al::LiveActor const*,bool const*,int);
    void appendMashJoint(al::JointMasher *,char const*,float);
    void initJointRumbler(al::LiveActor const*,char const*,float,float,unsigned int,int);
    void initJointLocalQuatRotator(al::LiveActor const*,char const*,sead::Quat<float> const*);
    void initJointLookAtController(al::LiveActor const*,int);
    void appendJointLookAtController(al::JointLookAtController *,al::LiveActor const*,char const*,float,sead::Vector2<float> const&,sead::Vector2<float> const&,sead::Vector3<float> const&,sead::Vector3<float> const&);
    void appendJointLookAtControllerNoJudge(al::JointLookAtController *,al::LiveActor const*,char const*,float,sead::Vector2<float> const&,sead::Vector2<float> const&,sead::Vector3<float> const&,sead::Vector3<float> const&);
    void appendJointLookAtControllerNoJudgeNoOverLimitYaw(al::JointLookAtController *,al::LiveActor const*,char const*,float,sead::Vector2<float> const&,sead::Vector2<float> const&,sead::Vector3<float> const&,sead::Vector3<float> const&);
    void initJointGroundSmoothController(al::LiveActor const*,char const*);
    void initJointPosToPosController(al::LiveActor const*,char const*,sead::Vector3<float> const*,sead::Vector3<float> const*,float *,sead::Vector3<float> const&);
    void initJointSpringController(al::LiveActor const*,char const*);
    void initJointConstrainedSpringController(al::LiveActor const*,char const*);
    void initJointSpringTransController(al::LiveActor const*,char const*);
    void initJointSimpleIK(al::LiveActor const*,char const*);
}