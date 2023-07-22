#pragma once

#include <al/Library/IUse/IUseCamera.h>
#include <common/aglRenderBuffer.h>
#include <basis/seadTypes.h>
#include <container/seadPtrArray.h>
#include <math/seadVector.h>
#include <math/seadMatrix.h>
#include <gfx/seadCamera.h>

namespace al {

class SceneCameraInfo;
class ScreenCapture;

class ScreenCaptureExecutor {
public:
    ScreenCaptureExecutor(int);
    ~ScreenCaptureExecutor();

    void createScreenCapture(int, int, int);
    void draw(agl::DrawContext*, const agl::RenderBuffer*, int) const;
    void tryCapture(agl::DrawContext*, const agl::RenderBuffer*, int);
    void tryCaptureAndDraw(agl::DrawContext*, const agl::RenderBuffer*, int);

    void requestCapture(bool, int);
    void onDraw(int screenCaptureIndex);
    void offDraw(int screenCaptureIndex);
    void offDraw();

    bool isDraw(int) const;

    void* vtable;
    sead::PtrArray<ScreenCapture> mArray;
    bool mIsCaptured;
};

class ScreenCoverCtrl {
public:
    ScreenCoverCtrl();
    void requestCaptureScreenCover(int totalFrames);
    void update();

    int mFrameTimer;
    bool mIsActive;
};

u32 getDisplayWidth();
u32 getDisplayHeight();
u32 getLayoutDisplayWidth();
u32 getLayoutDisplayHeight();
u32 getVirtualDisplayWidth();
u32 getVirtualDisplayHeight();
u32 getSubDisplayWidth();
u32 getSubDisplayHeight();

bool isInScreen(const sead::Vector2f&, float);

bool calcWorldPosFromScreen(sead::Vector3f* output, const sead::Vector2f&, const sead::Matrix34f&, float); // Always returns true
void calcWorldPosFromScreenPos(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f, float);
void calcWorldPosFromScreenPos(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f, const sead::Vector3f);
void calcWorldPosFromScreenPos(sead::Vector3f* output, const al::SceneCameraInfo*, const sead::Vector2f, float, int);
void calcWorldPosFromScreenPos(sead::Vector3f* output, const al::SceneCameraInfo*, const sead::Vector2f, const sead::Vector3f, int);
void calcWorldPosFromScreenPosSub(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f, float);
void calcWorldPosFromScreenPosSub(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f, const sead::Vector3f);
void calcWorldPosFromLayoutPos(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f, float);
void calcWorldPosFromLayoutPos(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f, const sead::Vector3f);
void calcWorldPosFromLayoutPos(sead::Vector3f* output, const al::SceneCameraInfo*, const sead::Vector2f, float, int);
void calcWorldPosFromLayoutPos(sead::Vector3f* output, const al::SceneCameraInfo*, const sead::Vector2f, const sead::Vector3f, int);
void calcWorldPosFromLayoutPosSub(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f, float);
void calcWorldPosFromLayoutPosSub(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f, const sead::Vector3f);

void calcScreenPosFromWorldPos(sead::Vector2f* output, const al::IUseCamera*, const sead::Vector3f&);
void calcScreenPosFromWorldPosSub(sead::Vector2f* output, const al::IUseCamera*, const sead::Vector3f&);
void calcScreenPosFromLayoutPos(sead::Vector2f* output, const sead::Vector2f&);
float calcScreenRadiusFromWorldRadius(const sead::Vector3f&, const al::IUseCamera*, float);
float calcScreenRadiusFromWorldRadiusSub(const sead::Vector3f&, const al::IUseCamera*, float);

void calcLayoutPosFromScreenPos(sead::Vector2f* output, const sead::Vector2f&);
void calcLayoutPosFromWorldPos(sead::Vector2f* output, const al::IUseCamera*, const sead::Vector3f&);
void calcLayoutPosFromWorldPos(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector3f&);
void calcLayoutPosFromWorldPos(sead::Vector2f* output, const al::SceneCameraInfo*, const sead::Vector3f&, int);
void calcLayoutPosFromWorldPos(sead::Vector3f* output, const al::SceneCameraInfo*, const sead::Vector3f&, int);
void calcLayoutPosFromWorldPosSub(sead::Vector2f* output, const al::IUseCamera*, const sead::Vector3f&);
void calcLayoutPosFromWorldPosWithClampOutRange(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector3f&, float, int);
void calcLayoutPosFromWorldPosWithClampOutRange(sead::Vector3f* output, const al::SceneCameraInfo*, const sead::Vector3f&, float, int);
void calcLayoutPosFromWorldPosWithClampByScreen(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector3f&);
float calcLayoutRadiusFromWorldRadius(const sead::Vector3f&, const al::IUseCamera*, float);

bool calcCameraPosToWorldPosDirFromScreenPos(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f&, float);
bool calcCameraPosToWorldPosDirFromScreenPos(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f&, const sead::Vector3f&);
bool calcCameraPosToWorldPosDirFromScreenPos(sead::Vector3f* output, const al::SceneCameraInfo*, const sead::Vector2f&, float, int);
bool calcCameraPosToWorldPosDirFromScreenPos(sead::Vector3f* output, const al::SceneCameraInfo*, const sead::Vector2f&, const sead::Vector3f&, int);
void calcCameraPosToWorldPosDirFromScreenPosSub(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f&, float);
void calcCameraPosToWorldPosDirFromScreenPosSub(sead::Vector3f* output, const al::IUseCamera*, const sead::Vector2f&, const sead::Vector3f&);

void calcLineCameraToWorldPosFromScreenPos(sead::Vector3f* output1, sead::Vector3f* output2, const al::IUseCamera*, const sead::Vector2f&);
void calcLineCameraToWorldPosFromScreenPos(sead::Vector3f* output1, sead::Vector3f* output2, const al::IUseCamera*, const sead::Vector2f&, float, float);
void calcLineCameraToWorldPosFromScreenPos(sead::Vector3f* output1, sead::Vector3f* output2, const al::SceneCameraInfo*, const sead::Vector2f&, int);
void calcLineCameraToWorldPosFromScreenPos(sead::Vector3f* output1, sead::Vector3f* output2, const al::SceneCameraInfo*, const sead::Vector2f&, float, float, int);
void calcLineCameraToWorldPosFromScreenPosSub(sead::Vector3f* output1, sead::Vector3f* output2, const al::IUseCamera*, const sead::Vector2f&);
void calcLineCameraToWorldPosFromScreenPosSub(sead::Vector3f* output1, sead::Vector3f* output2, const al::IUseCamera*, const sead::Vector2f&, float, float);
} // namespace al

namespace ScreenFunction {
void calcWorldPositionFromCenterScreen(sead::Vector3f*,sead::Vector2f const&,sead::Vector3f const&,sead::Camera const&,sead::Projection const&,sead::Viewport const&);
} // namespace ScreenFunction