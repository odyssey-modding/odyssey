#pragma once

namespace al {
class AreaObjDirector;
class CameraDirector;
class ClippingDirector;
class CollisionDirector;
class DemoDirector;
class GameDataHolderBase;
class GravityHolder;
class ItemDirectorBase;
class NatureDirector;
class GamePadSystem;
class PadRumbleDirector;
class PlayerHolder;
class SceneObjHolder;
class SceneStopCtrl;
class SceneMsgCtrl;
class ScreenCoverCtrl;
class ShadowDirector;
class ModelGroup;
class GraphicsSystemInfo;
class ModelDrawBufferCounter;

struct ActorSceneInfo {
    al::AreaObjDirector* mAreaObjDirector;
    al::CameraDirector* mCameraDirector;
    al::ClippingDirector* mClippingDirector;
    al::CollisionDirector* mCollisionDirector;
    al::DemoDirector* mDemoDirector;
    al::GameDataHolderBase* mGameDataHolder;
    al::GravityHolder* mGravityHolder;
    al::ItemDirectorBase* mItemDirector;
    al::NatureDirector* mNatureDirector;
    const al::GamePadSystem* mGamePadSystem;
    al::PadRumbleDirector* mPadRumbleDirector;
    al::PlayerHolder* mPlayerHolder;
    al::SceneObjHolder* mSceneObjHolder;
    al::SceneStopCtrl* mSceneStopCtrl;
    al::SceneMsgCtrl* mSceneMsgCtrl;
    al::ScreenCoverCtrl* mScreenCoverCtrl;
    al::ShadowDirector* mShadowDirector;
    al::ModelGroup* mModelGroup;
    al::GraphicsSystemInfo* mGraphicsSystemInfo;
    al::ModelDrawBufferCounter* mModelDrawBufferCounter;
};
}  // namespace al
