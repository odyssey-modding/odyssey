#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace nn::ui2d {
class TextureInfo;
}

namespace sead {
class Color4u8;
}

namespace agl {
class TextureData;
}

namespace al {
class LayoutActor;
class LayoutPaneGroup;
class IUseLayout;
class MessageHolder;

void killLayoutIfActive(al::LayoutActor*);
void appearLayoutIfDead(al::LayoutActor*);
bool isActive(const al::LayoutActor*);
bool isDead(const al::LayoutActor*);
void calcTrans(sead::Vector3f*, const al::IUseLayout*);
sead::Vector3f& getLocalTrans(const al::IUseLayout*);
sead::Vector3f* getLocalTransPtr(const al::IUseLayout*);
void calcScale(sead::Vector3f*, const al::IUseLayout*);
sead::Vector3f& getLocalScale(const al::IUseLayout*);
void setLocalTrans(al::IUseLayout*, const sead::Vector3f&);
void setLocalTrans(al::IUseLayout*, const sead::Vector2f&);
void setLocalScale(al::IUseLayout*, float);
void setLocalScale(al::IUseLayout*, const sead::Vector2f&);
void setLocalAlpha(al::IUseLayout*, float);
void calcPaneTrans(sead::Vector3f*, const al::IUseLayout*, const char*);
void calcPaneMtx(sead::Matrix34f*, const al::IUseLayout*, const char*);
void calcPaneTrans(sead::Vector2f*, const al::IUseLayout*, const char*);
void calcPaneScale(sead::Vector3f*, const al::IUseLayout*, const char*);
void calcPaneSize(sead::Vector3f*, const al::IUseLayout*, const char*);
sead::Matrix34f& getPaneMtx(const al::IUseLayout*, const char*);
sead::Matrix34f* getPaneMtxRaw(const al::IUseLayout*, const char*);
f32 getGlobalAlpha(const al::IUseLayout*, const char*);
void setPaneLocalTrans(al::IUseLayout*, const char*, const sead::Vector2f&);
void setPaneLocalTrans(al::IUseLayout*, const char*, const sead::Vector3f&);
void setPaneLocalRotate(al::IUseLayout*, const char*, const sead::Vector3f&);
void setPaneLocalScale(al::IUseLayout*, const char*, const sead::Vector2f&);
void setPaneLocalSize(al::IUseLayout*, const char*, const sead::Vector2f&);
void setPaneLocalAlpha(al::IUseLayout*, const char*, float);
sead::Vector3f& getPaneLocalTrans(const al::IUseLayout*, const char*);
void getPaneLocalSize(sead::Vector2f*, const al::IUseLayout*, const char*);
sead::Vector3f& getPaneLocalRotate(const al::IUseLayout*, const char*);
sead::Vector3f& getPaneLocalScale(const al::IUseLayout*, const char*);
sead::Vector3f& getTextBoxDrawRectSize(const al::IUseLayout*, const char*);
void showPane(al::IUseLayout*, const char*);
void hidePane(al::IUseLayout*, const char*);
void showPaneNoRecursive(al::IUseLayout*, const char*);
void hidePaneNoRecursive(al::IUseLayout*, const char*);
bool isHidePane(const al::IUseLayout*, const char*);
void showPaneRoot(al::IUseLayout*);
void hidePaneRoot(al::IUseLayout*);
void showPaneRootNoRecursive(al::IUseLayout*);
void hidePaneRootNoRecursive(al::IUseLayout*);
bool isHidePaneRoot(const al::IUseLayout*);
bool isExistPane(const al::IUseLayout*, const char*);
bool isContainPointPane(const al::IUseLayout*, const char*, const sead::Vector2f&);
void findHitPaneFromLayoutPos(const al::IUseLayout*, const sead::Vector2f&);
bool isExistHitPaneFromLayoutPos(const al::IUseLayout*, const sead::Vector2f&);
void findHitPaneFromScreenPos(const al::IUseLayout*, const sead::Vector2f&);
bool isExistHitPaneFromScreenPos(const al::IUseLayout*, const sead::Vector2f&);
bool isTouchPosInPane(const al::IUseLayout*, const char*);
void setCursorPanePos(al::IUseLayout*, const al::IUseLayout*);
void setPaneVtxColor(const al::IUseLayout*, const char*, const sead::Color4u8&);
bool isTriggerTouchPane(const al::IUseLayout*, const char*);
bool isHoldTouchPane(const al::IUseLayout*, const char*);
bool isReleaseTouchPane(const al::IUseLayout*, const char*);
s32 getPaneChildNum(const al::IUseLayout*, const char*);
const char* getPaneChildName(const al::IUseLayout*, const char*, s32);
void setPaneStringLength(al::IUseLayout*, const char*, const char16_t*, u16, u16);
void setPaneString(al::IUseLayout*, const char*, const char16_t*, u16);
void setPaneCounterDigit1(al::IUseLayout*, const char*, s32, u16);
void setPaneCounterDigit2(al::IUseLayout*, const char*, s32, u16);
void setPaneCounterDigit3(al::IUseLayout*, const char*, s32, u16);
void setPaneCounterDigit4(al::IUseLayout*, const char*, s32, u16);
void setPaneCounterDigit5(al::IUseLayout*, const char*, s32, u16);
void setPaneCounterDigit6(al::IUseLayout*, const char*, s32, u16);
void setPaneNumberDigit1(al::IUseLayout*, const char*, s32, u16);
void setPaneNumberDigit2(al::IUseLayout*, const char*, s32, u16);
void setPaneNumberDigit3(al::IUseLayout*, const char*, s32, u16);
void setPaneNumberDigit4(al::IUseLayout*, const char*, s32, u16);
void setPaneNumberDigit5(al::IUseLayout*, const char*, s32, u16);
void setPaneStringFormat(al::IUseLayout*, const char*, const char*, ...);
void setTextPositionCenterH(al::IUseLayout*, const char*);
void initPaneMessage(al::IUseLayout*, const char*, const al::MessageHolder*, const char*, u32);
void setPaneSystemMessage(al::LayoutActor*, const char*, const char*, const char*);
void setPaneStageMessage(al::LayoutActor*, const char*, const char*, const char*);
const char16_t* getPaneStringBuffer(const al::IUseLayout*, const char*);
s32 getPaneStringBufferLength(const al::IUseLayout*, const char*);
void setTextBoxPaneFont(const al::LayoutActor*, const char*, const char*);
void adjustPaneSizeToTextSizeAll(const al::LayoutActor*);
void requestCaptureRecursive(const al::LayoutActor*);
void setRubyScale(const al::LayoutActor*, float);
nn::ui2d::TextureInfo* createTextureInfo();
nn::ui2d::TextureInfo* createTextureInfo(const agl::TextureData&);
nn::ui2d::TextureInfo* createTextureInfo(const al::IUseLayout*, const char*);
void getPaneTextureInfo(nn::ui2d::TextureInfo*, const al::IUseLayout*, const char*);
nn::ui2d::TextureInfo* createTextureInfo(const char*, const char*, const char*);
void updateTextureInfo(nn::ui2d::TextureInfo*, const agl::TextureData&);
void setPaneTexture(al::IUseLayout*, const char*, const nn::ui2d::TextureInfo*);
void registerLayoutPartsActor(al::LayoutActor*, al::LayoutActor*);
void updateLayoutPaneRecursive(al::LayoutActor*);
s32 getLayoutPaneGroupNum(al::LayoutActor*);
al::LayoutPaneGroup* getLayoutPaneGroup(al::LayoutActor*, s32);
}  // namespace al
