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
    const char* field_0;
    al::LiveActor* mRootActor;
    void* field_10;
    al::ActionAnimCtrl* mActionAnimCtrl;
    al::NerveActionCtrl* mNerveActionCtrl;
    al::ActionFlagCtrl* mActionFlagCtrl;
    al::ActionEffectCtrl* mActionEffectCtrl;
    al::ActionSeCtrl* mActionSeCtrl;
    al::ActionBgmCtrl* mActionBgmCtrl;
    al::ActionPadAndCameraCtrl* mActionPadAndCameraCtrl;
    al::ActionScreenEffectCtrl* mActionScreenEffectCtrl;

public:
    static ActorActionKeeper* tryCreate(al::LiveActor*, al::ActorResource const*, char const*, char const*);
    void startAction(char const*);
    bool tryStartActionNoAnim(char const*);
    void updatePrev();
    void updatePost();
    ActorActionKeeper(al::LiveActor*, char const*, al::ActionAnimCtrl*, al::NerveActionCtrl*, al::ActionFlagCtrl*, al::ActionEffectCtrl*,
                      al::ActionSeCtrl*, al::ActionBgmCtrl*, al::ActionPadAndCameraCtrl*, al::ActionScreenEffectCtrl*);
    void init();
};
}  // namespace al