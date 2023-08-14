#pragma once

#include <gfx/seadColor.h>
#include <math/seadBoundBox.h>
#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <nn/g3d/ResFile.h>
#include <nn/gfx/gfx_DescriptorSlot.h>
namespace agl {
class UniformBlock;
}
namespace nn::gfx {
class ResTexture;
}
namespace al {
class LayoutTextureRenderObj;
class LiveActor;
class ClippingDirector;
;
void updateMaterialCodeGround(al::LiveActor* actor, const char*);
void updateMaterialCodeAll(al::LiveActor* actor);
void updateMaterialCodeArea(al::LiveActor* actor);
void updateMaterialCodeWet(al::LiveActor* actor, bool);
void updateMaterialCodeWater(al::LiveActor* actor);
void updateMaterialCodeWater(al::LiveActor* actor, bool);
void updateMaterialCodePuddle(al::LiveActor* actor);
void updateMaterialCodePuddle(al::LiveActor* actor, bool);
void resetMaterialCode(al::LiveActor* actor);
void showModel(al::LiveActor* actor);
void showModelIfHide(al::LiveActor* actor);
bool isHideModel(const al::LiveActor* actor);
void hideModel(al::LiveActor* actor);
void hideModelIfShow(al::LiveActor* actor);
bool isExistModel(const al::LiveActor* actor);
void switchShowHideModelIfNearCamera(al::LiveActor* actor, f32);
void blinkModel(al::LiveActor* actor, s32, s32, s32);
void calcViewModelSystem(al::LiveActor* actor);
void calcViewModel(al::LiveActor* actor);
void showSilhouetteModel(al::LiveActor* actor);
void hideSilhouetteModel(al::LiveActor* actor);
bool isSilhouetteModelHidden(const al::LiveActor* actor);
void showSilhouetteModelIfHide(al::LiveActor* actor);
void hideSilhouetteModelIfShow(al::LiveActor* actor);
void setModelAlphaMask(al::LiveActor* actor, f32);
float getModelAlphaMask(const al::LiveActor* actor);
bool isModelAlphaMask(const al::LiveActor* actor);
void updateModelAlphaMaskCameraDistance(al::LiveActor* actor, f32, f32, f32, f32);
bool isExistZPrePass(const al::LiveActor* actor);
bool isEnableZPrePass(const al::LiveActor* actor);
void validateZPrePass(al::LiveActor* actor);
void invalidateZPrePass(al::LiveActor* actor);
void invalidateOcclusionQuery(al::LiveActor* actor);
void validateOcclusionQuery(al::LiveActor* actor);
bool isValidOcclusionQuery(const al::LiveActor* actor);
void setFixedModelFlag(al::LiveActor* actor);
void tryInitFixedModelGpuBuffer(al::LiveActor* actor);
void setIgnoreUpdateDrawClipping(al::LiveActor* actor, bool value);
void setNeedSetBaseMtxAndCalcAnimFlag(al::LiveActor* actor, bool value);
bool isViewDependentModel(const al::LiveActor* actor);
bool isNeedUpdateModel(const al::LiveActor* actor);
void setEnvTextureMirror(al::LiveActor* actor, s32);
void setEnvTextureProc3D(al::LiveActor* actor, s32);
void forceApplyCubeMap(al::LiveActor* actor, const char* cubeMapName);
void setMaterialProgrammable(al::LiveActor* actor);
bool isIncludePrepassCullingShape(al::LiveActor* actor);
void isExistJoint(const al::LiveActor* actor, const char*);
void getJointIndex(const al::LiveActor* actor, const char*);
sead::Matrix34f* getJointMtxPtr(const al::LiveActor* actor, const char*);
sead::Matrix34f* getJointMtxPtrByIndex(const al::LiveActor* actor, int);
void getJointLocalTrans(sead::Vector3f*, const al::LiveActor* actor, const char*);
void calcJointPos(sead::Vector3f*, const al::LiveActor* actor, const char*);
void calcJointOffsetPos(sead::Vector3f*, const al::LiveActor* actor, const char*, const sead::Vector3f&);
void calcJointPosByIndex(sead::Vector3f*, const al::LiveActor* actor, int);
void calcJointSideDir(sead::Vector3f*, const al::LiveActor* actor, const char*);
void calcJointUpDir(sead::Vector3f*, const al::LiveActor* actor, const char*);
void calcJointFrontDir(sead::Vector3f*, const al::LiveActor* actor, const char*);
void calcJointScale(sead::Vector3f*, const al::LiveActor* actor, const char*);
void calcJointQuat(sead::Quatf*, const al::LiveActor* actor, const char*);
void multVecJointMtx(sead::Vector3f*, const sead::Vector3f&, const al::LiveActor* actor, const char*);
void multVecJointInvMtx(sead::Vector3f*, const sead::Vector3f&, const al::LiveActor* actor, const char*);
void multMtxJointInvMtx(sead::Matrix34f*, const sead::Matrix34f&, const al::LiveActor* actor, const char*);
void setJointVisibility(al::LiveActor* actor, const char*, bool);
void isJointVisibility(const al::LiveActor* actor, const char*);
void isFaceJointXDirDegreeYZ(const al::LiveActor* actor, const char*, const sead::Vector3f&, f32, f32);
void isFaceJointYDirDegreeZX(const al::LiveActor* actor, const char*, const sead::Vector3f&, f32, f32);
void isFaceJointZDirDegreeXY(const al::LiveActor* actor, const char*, const sead::Vector3f&, f32, f32);
void calcJointAngleXDirToTargetOnYDir(const al::LiveActor* actor, const char*, const sead::Vector3f&);
void calcJointAngleXDirToTargetOnZDir(const al::LiveActor* actor, const char*, const sead::Vector3f&);
void calcJointAngleYDirToTargetOnXDir(const al::LiveActor* actor, const char*, const sead::Vector3f&);
void calcJointAngleYDirToTargetOnZDir(const al::LiveActor* actor, const char*, const sead::Vector3f&);
void calcJointAngleZDirToTargetOnXDir(const al::LiveActor* actor, const char*, const sead::Vector3f&);
void calcJointAngleZDirToTargetOnYDir(const al::LiveActor* actor, const char*, const sead::Vector3f&);
void getMaterialName(const al::LiveActor* actor, s32);
void getMaterialCount(const al::LiveActor* actor);
void isExistMaterial(const al::LiveActor* actor, const char*);
void getMaterialObj(const al::LiveActor* actor, s32);
void getMaterialObj(const al::LiveActor* actor, const char*);
void getMaterialIndex(const al::LiveActor* actor, const char*);
void isExistMaterialTexture(const al::LiveActor* actor, const char*, const char*);
void getMaterialCategory(const al::LiveActor* actor, s32);
void tryGetMaterialCategory(const al::LiveActor* actor, s32);
void isOnlyMaterialCategoryObject(const al::LiveActor* actor);
void showMaterial(al::LiveActor* actor, const char*);
void hideMaterial(al::LiveActor* actor, const char*);
void showMaterial(al::LiveActor* actor, s32);
void hideMaterial(al::LiveActor* actor, s32);
void showMaterialAll(al::LiveActor* actor);
void tryShowMaterial(al::LiveActor* actor, s32);
void tryHideMaterial(al::LiveActor* actor, s32);
void tryShowMaterialAll(al::LiveActor* actor);
void setModelMaterialParameterF32(const al::LiveActor* actor, s32, const char*, f32);
void setModelMaterialParameterF32(const al::LiveActor* actor, const char*, const char*, f32);
void setModelMaterialParameterV2F(const al::LiveActor* actor, s32, const char*, const sead::Vector2f&);
void setModelMaterialParameterV2F(const al::LiveActor* actor, const char*, const char*, const sead::Vector2f&);
void setModelMaterialParameterV3F(const al::LiveActor* actor, s32, const char*, const sead::Vector3f&);
void setModelMaterialParameterV3F(const al::LiveActor* actor, const char*, const char*, const sead::Vector3f&);
void setModelMaterialParameterV4F(const al::LiveActor* actor, s32, const char*, const sead::Vector4f&);
void setModelMaterialParameterV4F(const al::LiveActor* actor, const char*, const char*, const sead::Vector4f&);
void setModelMaterialParameterRgb(const al::LiveActor* actor, s32, const char*, const sead::Vector3f&);
void setModelMaterialParameterRgb(const al::LiveActor* actor, const char*, const char*, const sead::Vector3f&);
void setModelMaterialParameterRgb(const al::LiveActor* actor, s32, const char*, const sead::Color4f&);
void setModelMaterialParameterRgb(const al::LiveActor* actor, const char*, const char*, const sead::Color4f&);
void setModelMaterialParameterRgba(const al::LiveActor* actor, s32, const char*, const sead::Color4f&);
void setModelMaterialParameterRgba(const al::LiveActor* actor, const char*, const char*, const sead::Color4f&);
void setModelMaterialParameterAlpha(const al::LiveActor* actor, s32, const char*, f32);
void setModelMaterialParameterAlpha(const al::LiveActor* actor, const char*, const char*, f32);
void setModelMaterialParameterTextureTrans(const al::LiveActor* actor, const char*, s32, const sead::Vector2f&);
void getModelMaterialParameterDisplacementScale(const al::LiveActor* actor, const char*, s32);
void setModelMaterialParameterDisplacementScale(const al::LiveActor* actor, const char*, s32, f32);
void getModelUniformBlock(const al::LiveActor* actor, const char*);
void findModelUniformBlock(const al::LiveActor* actor, const char*);
void swapModelUniformBlock(agl::UniformBlock*);
void flushModelUniformBlock(agl::UniformBlock*);
void getModelDrawCategoryFromShaderAssign(bool*, bool*, bool*, bool*, const al::LiveActor* actor);
void trySetOcclusionQueryBox(al::LiveActor* actor, f32);
void trySetOcclusionQueryBox(al::LiveActor* actor, const sead::BoundBox3f&);
void trySetOcclusionQueryCenter(al::LiveActor* actor, const sead::Vector3f*);
void getModelName(const al::LiveActor* actor);
void isModelName(const al::LiveActor* actor, const char*);
void calcModelBoundingSphereRadius(const al::LiveActor* actor);
void getBoundingSphereCenterAndRadius(sead::Vector3f*, f32*, const al::LiveActor* actor);
void calcModelBoundingBox(sead::BoundBox3f*, const al::LiveActor* actor);
void calcModelBoundingBoxMtx(sead::Matrix34f*, const al::LiveActor* actor);
void submitViewModel(const al::LiveActor* actor, const sead::Matrix34f&);
void replaceMaterialTextureRef(al::LiveActor* actor, nn::g3d::TextureRef*, const char*, const char*);
void replaceMaterialResTexture(al::LiveActor* actor, nn::gfx::ResTexture*, const char*, const char*);
void replaceMaterialResTexture(al::LiveActor*, const char*, const char*, const nn::gfx::DescriptorSlot, nn::gfx::TextureView*);
void replaceMaterialLayoutTexture(al::LiveActor* actor, const al::LayoutTextureRenderObj*, const char*, const char*);
void recreateModelDisplayList(const al::LiveActor* actor);
void calcPolygonNum(const al::LiveActor* actor, s32);
void calcPolygonNumCurrentLod(const al::LiveActor* actor);
void calcPolygonNumCurrentLodWithoutVisAnim(const al::LiveActor* actor);
void getLodLevel(const al::LiveActor* actor);
void getMaterialLodLevel(const al::LiveActor* actor);
void getLodLevelNoClamp(const al::LiveActor* actor);
void getLodModelCount(const al::LiveActor* actor);
void forceLodLevel(al::LiveActor* actor, s32);
void unforceLodLevel(al::LiveActor* actor);
void isExistLodModel(const al::LiveActor* actor);
void isEnableMaterialLod(const al::LiveActor* actor);
void validateLodModel(al::LiveActor* actor);
void invalidateLodModel(al::LiveActor* actor);
void isValidateLodModel(const al::LiveActor* actor);
void isExistDitherAnimator(const al::LiveActor* actor);
void isValidNearDitherAnim(const al::LiveActor* actor);
void stopDitherAnimAutoCtrl(al::LiveActor* actor);
void restartDitherAnimAutoCtrl(al::LiveActor* actor);
void validateDitherAnim(al::LiveActor* actor);
void invalidateDitherAnim(al::LiveActor* actor);
void validateFarDitherIfInvalidateClipping(al::LiveActor* actor);
void setDitherAnimSphereRadius(al::LiveActor* actor, f32);
void setDitherAnimBoundingBox(al::LiveActor* actor, const sead::Vector3f&);
void setDitherAnimMaxAlpha(al::LiveActor* actor, f32);
void setDitherAnimClippingJudgeLocalOffset(al::LiveActor* actor, const sead::Vector3f&);
void setDitherAnimClippingJudgeParam(al::LiveActor* actor, const char*);
void resetDitherAnimClippingJudgeParam(al::LiveActor* actor);
void getDitherAnimMinNearDitherAlpha(const al::LiveActor* actor);
void getDitherAnimNearClipStartDistance(const al::LiveActor* actor);
void getDitherAnimNearClipEndDistance(const al::LiveActor* actor);
void calcDitherAnimJudgeDistance(const al::LiveActor* actor);
void createUniqueShader(al::LiveActor* actor);
void isJudgedToClipFrustum(const al::ClippingDirector*, const sead::Vector3f&, f32, f32);
void isJudgedToClipFrustum(const al::LiveActor* actor, const sead::Vector3f&, f32, f32);
void isJudgedToClipFrustum(const al::LiveActor* actor, f32, f32);
void isJudgedToClipFrustumWithoutFar(const al::ClippingDirector*, const sead::Vector3f&, f32, f32);
void isJudgedToClipFrustumWithoutFar(const al::LiveActor* actor, const sead::Vector3f&, f32, f32);
void isJudgedToClipFrustumWithoutFar(const al::LiveActor* actor, f32, f32);
}  // namespace al
