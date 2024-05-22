#pragma once

#include <al/Library/Audio/AudioKeeper.h>
#include <al/Library/Camera/CameraDirector.h>
#include <al/Library/Effect/EffectKeeper.h>
#include <al/Library/HostIO/HioNode.h>
#include <al/Library/Layout/LayoutKeeper.h>
#include <al/Library/Message/MessageSystem.h>
#include <al/Library/Nerve/NerveKeeper.h>
#include <al/Library/Scene/SceneObjHolder.h>
#include <al/Project/Layout/LayoutActionKeeper.h>
#include <prim/seadSafeString.h>

namespace al {
class NerveKeeper;
class LayoutKeeper;
class LayoutActionKeeper;
class LayoutTextPaneAnimator;
class EffectKeeper;
class AudioKeeper;
class LayoutExecuteInfo;
class HitReactionKeeper;
class LayoutSceneInfo;
class LayoutPartsActorKeeper;
class CameraDirector;
class SceneObjHolder;
class MessageSystem;
class Nerve;

class LayoutActor : public al::IUseHioNode,
                    public al::IUseNerve,
                    public al::IUseLayout,
                    public al::IUseLayoutAction,
                    public al::IUseMessageSystem,
                    public al::IUseCamera,
                    public al::IUseAudioKeeper,
                    public al::IUseEffectKeeper,
                    public al::IUseSceneObjHolder {
private:
    sead::FixedSafeString<0x80> mName;
    al::NerveKeeper* mNerveKeeper;
    al::LayoutKeeper* mLayoutKeeper;
    al::LayoutActionKeeper* mLayoutActionKeeper;
    al::LayoutTextPaneAnimator* mTextPaneAnimator;
    al::EffectKeeper* mEffectKeeper;
    al::AudioKeeper* mAudioKeeper;
    al::LayoutExecuteInfo* mExecuteInfo;
    al::HitReactionKeeper* mHitReactionKeeper;
    al::LayoutSceneInfo* mLayoutSceneInfo;
    al::LayoutPartsActorKeeper* mLayoutPartsActorKeeper;
    bool mIsAlive;

public:
    LayoutActor(const char*);

    virtual void appear();
    virtual void kill();
    virtual void control() {}
    virtual void calcAnim(bool recursive);
    virtual void movement();

    virtual al::NerveKeeper* getNerveKeeper() const override;
    virtual const char* getName() const override;
    virtual al::EffectKeeper* getEffectKeeper() const override;
    virtual al::AudioKeeper* getAudioKeeper() const override;
    virtual al::LayoutActionKeeper* getLayoutActionKeeper() const override;
    virtual al::LayoutKeeper* getLayoutKeeper() const override;
    virtual al::CameraDirector* getCameraDirector() const override;
    virtual al::SceneObjHolder* getSceneObjHolder() const override;
    virtual const al::MessageSystem* getMessageSystem() const override;

    void initLayoutKeeper(al::LayoutKeeper*);
    void initActionKeeper();
    void initTextPaneAnimator(al::LayoutTextPaneAnimator*);
    void initExecuteInfo(al::LayoutExecuteInfo*);
    void initHitReactionKeeper(al::HitReactionKeeper*);
    void initSceneInfo(al::LayoutSceneInfo*);
    void initLayoutPartsActorKeeper(s32);
    void initEffectKeeper(al::EffectKeeper*);
    void initAudioKeeper(al::AudioKeeper*);
    void initNerve(const al::Nerve*, s32);
    void setMainGroupName(const char*);
    void syncAction();
};
}  // namespace al
class CameraDirector;
