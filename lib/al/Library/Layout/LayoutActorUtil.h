#pragma once

#include <common/aglTextureData.h>
#include <gfx/seadColor.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace nn::ui2d {
class TextureInfo;
}

namespace al {
class LayoutActor;
class IUseLayout;
class MessageHolder;

void killLayoutIfActive(al::LayoutActor*);
void appearLayoutIfDead(al::LayoutActor*);
bool isActive(al::LayoutActor const*);
bool isDead(al::LayoutActor const*);
void calcTrans(sead::Vector3f*, al::IUseLayout const*);
void getLocalTrans(al::IUseLayout const*);
void getLocalTransPtr(al::IUseLayout const*);
void calcScale(sead::Vector3f*, al::IUseLayout const*);
void getLocalScale(al::IUseLayout const*);
void setLocalTrans(al::IUseLayout*, sead::Vector3f const&);
void setLocalTrans(al::IUseLayout*, sead::Vector2<float> const&);
void setLocalScale(al::IUseLayout*, float);
void setLocalScale(al::IUseLayout*, sead::Vector2<float> const&);
void setLocalAlpha(al::IUseLayout*, float);
void calcPaneTrans(sead::Vector3f*, al::IUseLayout const*, char const*);
void calcPaneMtx(sead::Matrix34f*, al::IUseLayout const*, char const*);
void calcPaneTrans(sead::Vector2<float>*, al::IUseLayout const*, char const*);
void calcPaneScale(sead::Vector3f*, al::IUseLayout const*, char const*);
void calcPaneSize(sead::Vector3f*, al::IUseLayout const*, char const*);
void getPaneMtx(al::IUseLayout const*, char const*);
void getPaneMtxRaw(al::IUseLayout const*, char const*);
void getGlobalAlpha(al::IUseLayout const*, char const*);
void setPaneLocalTrans(al::IUseLayout*, char const*, sead::Vector2<float> const&);
void setPaneLocalTrans(al::IUseLayout*, char const*, sead::Vector3f const&);
void setPaneLocalRotate(al::IUseLayout*, char const*, sead::Vector3f const&);
void setPaneLocalScale(al::IUseLayout*, char const*, sead::Vector2<float> const&);
void setPaneLocalSize(al::IUseLayout*, char const*, sead::Vector2<float> const&);
void setPaneLocalAlpha(al::IUseLayout*, char const*, float);
void getPaneLocalTrans(al::IUseLayout const*, char const*);
void getPaneLocalSize(sead::Vector2<float>*, al::IUseLayout const*, char const*);
void getPaneLocalRotate(al::IUseLayout const*, char const*);
void getPaneLocalScale(al::IUseLayout const*, char const*);
void getTextBoxDrawRectSize(al::IUseLayout const*, char const*);
void showPane(al::IUseLayout*, char const*);
void hidePane(al::IUseLayout*, char const*);
void showPaneNoRecursive(al::IUseLayout*, char const*);
void hidePaneNoRecursive(al::IUseLayout*, char const*);
bool isHidePane(al::IUseLayout const*, char const*);
void showPaneRoot(al::IUseLayout*);
void hidePaneRoot(al::IUseLayout*);
void showPaneRootNoRecursive(al::IUseLayout*);
void hidePaneRootNoRecursive(al::IUseLayout*);
bool isHidePaneRoot(al::IUseLayout const*);
bool isExistPane(al::IUseLayout const*, char const*);
bool isContainPointPane(al::IUseLayout const*, char const*, sead::Vector2<float> const&);
void findHitPaneFromLayoutPos(al::IUseLayout const*, sead::Vector2<float> const&);
bool isExistHitPaneFromLayoutPos(al::IUseLayout const*, sead::Vector2<float> const&);
void findHitPaneFromScreenPos(al::IUseLayout const*, sead::Vector2<float> const&);
bool isExistHitPaneFromScreenPos(al::IUseLayout const*, sead::Vector2<float> const&);
bool isTouchPosInPane(al::IUseLayout const*, char const*);
void setCursorPanePos(al::IUseLayout*, al::IUseLayout const*);
void setPaneVtxColor(al::IUseLayout const*, char const*, sead::Color4u8 const&);
bool isTriggerTouchPane(al::IUseLayout const*, char const*);
bool isHoldTouchPane(al::IUseLayout const*, char const*);
bool isReleaseTouchPane(al::IUseLayout const*, char const*);
void getPaneChildNum(al::IUseLayout const*, char const*);
void getPaneChildName(al::IUseLayout const*, char const*, s32);
void setPaneStringLength(al::IUseLayout*, char const*, char16_t const*, u16, u16);
void setPaneString(al::IUseLayout*, char const*, char16_t const*, u16);
void setPaneCounterDigit1(al::IUseLayout*, char const*, s32, u16);
void setPaneCounterDigit2(al::IUseLayout*, char const*, s32, u16);
void setPaneCounterDigit3(al::IUseLayout*, char const*, s32, u16);
void setPaneCounterDigit4(al::IUseLayout*, char const*, s32, u16);
void setPaneCounterDigit5(al::IUseLayout*, char const*, s32, u16);
void setPaneCounterDigit6(al::IUseLayout*, char const*, s32, u16);
void setPaneNumberDigit1(al::IUseLayout*, char const*, s32, u16);
void setPaneNumberDigit2(al::IUseLayout*, char const*, s32, u16);
void setPaneNumberDigit3(al::IUseLayout*, char const*, s32, u16);
void setPaneNumberDigit4(al::IUseLayout*, char const*, s32, u16);
void setPaneNumberDigit5(al::IUseLayout*, char const*, s32, u16);
void setPaneStringFormat(al::IUseLayout*, char const*, char const*, ...);
void setTextPositionCenterH(al::IUseLayout*, char const*);
void initPaneMessage(al::IUseLayout*, char const*, al::MessageHolder const*, char const*, unsigned s32);
void setPaneSystemMessage(al::LayoutActor*, char const*, char const*, char const*);
void setPaneStageMessage(al::LayoutActor*, char const*, char const*, char const*);
void getPaneStringBuffer(al::IUseLayout const*, char const*);
void getPaneStringBufferLength(al::IUseLayout const*, char const*);
void setTextBoxPaneFont(al::LayoutActor const*, char const*, char const*);
void adjustPaneSizeToTextSizeAll(al::LayoutActor const*);
void requestCaptureRecursive(al::LayoutActor const*);
void setRubyScale(al::LayoutActor const*, float);
void createTextureInfo();
void createTextureInfo(agl::TextureData const&);
void createTextureInfo(al::IUseLayout const*, char const*);
void getPaneTextureInfo(nn::ui2d::TextureInfo*, al::IUseLayout const*, char const*);
void createTextureInfo(char const*, char const*, char const*);
void updateTextureInfo(nn::ui2d::TextureInfo*, agl::TextureData const&);
void setPaneTexture(al::IUseLayout*, char const*, nn::ui2d::TextureInfo const*);
void registerLayoutPartsActor(al::LayoutActor*, al::LayoutActor*);
void updateLayoutPaneRecursive(al::LayoutActor*);
void getLayoutPaneGroupNum(al::LayoutActor*);
void getLayoutPaneGroup(al::LayoutActor*, s32);
}  // namespace al
