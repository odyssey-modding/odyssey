#pragma once

#include "LiveActor.h"

namespace alSubActorFunction {
bool trySyncAlive(al::SubActorKeeper*);
bool trySyncDead(al::SubActorKeeper*);
bool trySyncClippingStart(al::SubActorKeeper*);
bool trySyncClippingEnd(al::SubActorKeeper*);
bool trySyncShowModel(al::SubActorKeeper*);
bool trySyncHideModel(al::SubActorKeeper*);
bool trySyncModelAlphaMask(al::SubActorKeeper*, float);
void findSubActor(const al::SubActorKeeper*, const char*);
}  // namespace alSubActorFunction

namespace al {
bool isExistSubActorKeeper(const al::LiveActor*);
void getSubActor(const al::LiveActor*, const char*);
void tryGetSubActor(const al::LiveActor*, const char*);
al::LiveActor* getSubActor(const al::LiveActor*, int);
s32 getSubActorNum(const al::LiveActor*);
void offSyncClippingSubActor(al::LiveActor*, const al::LiveActor*);
void offSyncClippingSubActor(al::LiveActor*, const char*);
void offSyncClippingSubActorAll(al::LiveActor*);
void onSyncClippingSubActor(al::LiveActor*, const al::LiveActor*);
void onSyncClippingSubActor(al::LiveActor*, const char*);
void onSyncClippingSubActorAll(al::LiveActor*);
void offSyncAppearSubActor(al::LiveActor*, const al::LiveActor*);
void offSyncAppearSubActor(al::LiveActor*, const char*);
void offSyncAppearSubActorAll(al::LiveActor*);
void onSyncAppearSubActor(al::LiveActor*, const al::LiveActor*);
void onSyncAppearSubActor(al::LiveActor*, const char*);
void onSyncAppearSubActorAll(al::LiveActor*);
void offSyncHideSubActor(al::LiveActor*, const al::LiveActor*);
void offSyncHideSubActor(al::LiveActor*, const char*);
void offSyncHideSubActorAll(al::LiveActor*);
void onSyncHideSubActor(al::LiveActor*, const al::LiveActor*);
void onSyncHideSubActor(al::LiveActor*, const char*);
void onSyncHideSubActorAll(al::LiveActor*);
void isSyncHideSubActor(const al::LiveActor*, const al::LiveActor*);
void offSyncAlphaMaskSubActor(al::LiveActor*, const al::LiveActor*);
void offSyncAlphaMaskSubActor(al::LiveActor*, const char*);
void offSyncAlphaMaskSubActorAll(al::LiveActor*);
void onSyncAlphaMaskSubActor(al::LiveActor*, const al::LiveActor*);
void onSyncAlphaMaskSubActor(al::LiveActor*, const char*);
void onSyncAlphaMaskSubActorAll(al::LiveActor*);
void isSyncAlphaMaskSubActor(const al::LiveActor*, const al::LiveActor*);
void startActionSubActor(const al::LiveActor*, const char*, const char*);
void isActionEndSubActor(const al::LiveActor*, const char*);
void isActionPlayingSubActor(const al::LiveActor*, const char*, const char*);
void isActionOneTimeSubActor(const al::LiveActor*, const char*);
void isActionOneTimeSubActor(const al::LiveActor*, const char*, const char*);
void tryStartActionSubActorAll(const al::LiveActor*, const char*);
void makeActorDeadSubActorAll(const al::LiveActor*);
void tryValidateCollisionPartsSubActorAll(al::LiveActor*);
void tryInvalidateCollisionPartsSubActorAll(al::LiveActor*);
}  // namespace al
