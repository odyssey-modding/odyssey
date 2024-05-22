#pragma once

namespace al {
class ActorResource;
class ActionAnimCtrl;
class ActionFlagCtrl;
class ActionEffectCtrl;
class ActionSeCtrl;
class ActionBgmCtrl;
class ActionPadAndCameraCtrl;
class ActionScreenEffectCtrl;
class NerveActionCtrl;
class LiveActor;

class ActorActionKeeper {
private:
    al::LiveActor* mRootActor;
    const char* mName;
    bool mIsActionRunning;
    al::ActionAnimCtrl* mActionAnimCtrl;
    al::NerveActionCtrl* mNerveActionCtrl;
    al::ActionFlagCtrl* mActionFlagCtrl;
    al::ActionEffectCtrl* mActionEffectCtrl;
    al::ActionSeCtrl* mActionSeCtrl;
    al::ActionBgmCtrl* mActionBgmCtrl;
    al::ActionPadAndCameraCtrl* mActionPadAndCameraCtrl;
    al::ActionScreenEffectCtrl* mActionScreenEffectCtrl;

public:
    static ActorActionKeeper* tryCreate(al::LiveActor*, const al::ActorResource*, const char*, const char*);
    void startAction(const char*);
    bool tryStartActionNoAnim(const char*);
    void updatePrev();
    void updatePost();
    ActorActionKeeper(al::LiveActor*, const char*, al::ActionAnimCtrl*, al::NerveActionCtrl*, al::ActionFlagCtrl*, al::ActionEffectCtrl*,
                      al::ActionSeCtrl*, al::ActionBgmCtrl*, al::ActionPadAndCameraCtrl*, al::ActionScreenEffectCtrl*);
    void init();
};
}  // namespace al