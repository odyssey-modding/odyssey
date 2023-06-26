#pragma once

#include "LiveActor.h"

namespace alSubActorFunction {
    bool trySyncAlive(al::SubActorKeeper *);
    bool trySyncDead(al::SubActorKeeper *);
    bool trySyncClippingStart(al::SubActorKeeper *);
    bool trySyncClippingEnd(al::SubActorKeeper *);
    bool trySyncShowModel(al::SubActorKeeper *);
    bool trySyncHideModel(al::SubActorKeeper *);
    bool trySyncModelAlphaMask(al::SubActorKeeper *,float);
    void findSubActor(al::SubActorKeeper const*,char const*);
}

namespace al {
    void isExistSubActorKeeper(al::LiveActor const*);
    void getSubActor(al::LiveActor const*,char const*);
    void tryGetSubActor(al::LiveActor const*,char const*);
    void getSubActor(al::LiveActor const*,int);
    void getSubActorNum(al::LiveActor const*);
    void offSyncClippingSubActor(al::LiveActor *,al::LiveActor const*);
    void offSyncClippingSubActor(al::LiveActor *,char const*);
    void offSyncClippingSubActorAll(al::LiveActor *);
    void onSyncClippingSubActor(al::LiveActor *,al::LiveActor const*);
    void onSyncClippingSubActor(al::LiveActor *,char const*);
    void onSyncClippingSubActorAll(al::LiveActor *);
    void offSyncAppearSubActor(al::LiveActor *,al::LiveActor const*);
    void offSyncAppearSubActor(al::LiveActor *,char const*);
    void offSyncAppearSubActorAll(al::LiveActor *);
    void onSyncAppearSubActor(al::LiveActor *,al::LiveActor const*);
    void onSyncAppearSubActor(al::LiveActor *,char const*);
    void onSyncAppearSubActorAll(al::LiveActor *);
    void offSyncHideSubActor(al::LiveActor *,al::LiveActor const*);
    void offSyncHideSubActor(al::LiveActor *,char const*);
    void offSyncHideSubActorAll(al::LiveActor *);
    void onSyncHideSubActor(al::LiveActor *,al::LiveActor const*);
    void onSyncHideSubActor(al::LiveActor *,char const*);
    void onSyncHideSubActorAll(al::LiveActor *);
    void isSyncHideSubActor(al::LiveActor const*,al::LiveActor const*);
    void offSyncAlphaMaskSubActor(al::LiveActor *,al::LiveActor const*);
    void offSyncAlphaMaskSubActor(al::LiveActor *,char const*);
    void offSyncAlphaMaskSubActorAll(al::LiveActor *);
    void onSyncAlphaMaskSubActor(al::LiveActor *,al::LiveActor const*);
    void onSyncAlphaMaskSubActor(al::LiveActor *,char const*);
    void onSyncAlphaMaskSubActorAll(al::LiveActor *);
    void isSyncAlphaMaskSubActor(al::LiveActor const*,al::LiveActor const*);
    void startActionSubActor(al::LiveActor const*,char const*,char const*);
    void isActionEndSubActor(al::LiveActor const*,char const*);
    void isActionPlayingSubActor(al::LiveActor const*,char const*,char const*);
    void isActionOneTimeSubActor(al::LiveActor const*,char const*);
    void isActionOneTimeSubActor(al::LiveActor const*,char const*,char const*);
    void tryStartActionSubActorAll(al::LiveActor const*,char const*);
    void makeActorDeadSubActorAll(al::LiveActor const*);
    void tryValidateCollisionPartsSubActorAll(al::LiveActor *);
    void tryInvalidateCollisionPartsSubActorAll(al::LiveActor *);
}