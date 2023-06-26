#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>
#include <math/seadMatrix.h>

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

void startHitReaction(al::LiveActor const*,char const*);
void startHitReactionHitEffect(al::LiveActor const*,char const*,al::HitSensor const*,al::HitSensor const*);
void startHitReactionHitEffect(al::LiveActor const*,char const*,sead::Vector3<float> const&);
void startHitReactionHitEffect(al::LiveActor const*,char const*,sead::Matrix34<float> const*);
void startHitReactionBlowHit(al::LiveActor const*,al::HitSensor const*,al::HitSensor const*);
void startHitReactionBlowHit(al::LiveActor const*,sead::Vector3<float> const&);
void startHitReactionBlowHit(al::LiveActor const*);
void startHitReactionBlowHitDirect(al::LiveActor const*,al::HitSensor const*,al::HitSensor const*);
void startHitReactionBlowHitDirect(al::LiveActor const*,sead::Vector3<float> const&);
void startHitReactionBlowHitDirect(al::LiveActor const*);
}  // namespace al
