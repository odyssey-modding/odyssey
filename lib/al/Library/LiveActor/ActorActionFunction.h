#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class LiveActor;
class HitSensor;
class Nerve;

void startAction(al::LiveActor* actor, const char* actionName);
void startActionAtRandomFrame(al::LiveActor* actor, const char* actionName);
bool tryStartAction(al::LiveActor* actor, const char* actionName);
bool tryStartActionIfNotPlaying(al::LiveActor* actor, const char* actionName);
bool tryStartActionIfActionEnd(al::LiveActor* actor, const char* actionName);

bool isActionPlaying(al::LiveActor* actor, const char* actionName);
bool isActionEnd(al::LiveActor* actor);
bool isExistAction(al::LiveActor* actor);
bool isExistAction(al::LiveActor* actor, const char* actionName);
bool isActionOneTime(al::LiveActor* actor);
bool isActionOneTime(al::LiveActor* actor, const char* actionName);

const char* getActionName(al::LiveActor* actor);
s32 getActionFrame(al::LiveActor* actor);
s32 getActionFrameMax(al::LiveActor* actor);
s32 getActionFrameMax(al::LiveActor* actor, const char* actionName);
f32 getActionFrameRate(al::LiveActor* actor);

void stopAction(al::LiveActor* actor);
void restartAction(al::LiveActor* actor);
void copyAction(al::LiveActor* actor, const al::LiveActor* sourceActor);

void startNerveAction(al::LiveActor* actor, const char* actionName);
void setNerveAtActionEnd(al::LiveActor* actor, const al::Nerve* nerve);
void resetNerveActionForInit(al::LiveActor* actor);

void startHitReaction(const al::LiveActor* actor, const char* reactionName);
void startHitReactionHitEffect(const al::LiveActor* actor, const char* reactionName, const al::HitSensor*, const al::HitSensor*);
void startHitReactionHitEffect(const al::LiveActor* actor, const char* reactionName, const sead::Vector3f&);
void startHitReactionHitEffect(const al::LiveActor* actor, const char* reactionName, const sead::Matrix34f*);
void startHitReactionBlowHit(const al::LiveActor* actor, const al::HitSensor*, const al::HitSensor*);
void startHitReactionBlowHit(const al::LiveActor* actor, const sead::Vector3f&);
void startHitReactionBlowHit(const al::LiveActor* actor);
void startHitReactionBlowHitDirect(const al::LiveActor* actor, const al::HitSensor*, const al::HitSensor*);
void startHitReactionBlowHitDirect(const al::LiveActor* actor, const sead::Vector3f&);
void startHitReactionBlowHitDirect(const al::LiveActor* actor);
}  // namespace al
