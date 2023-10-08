#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class IUseCamera;
class LiveActor;
class PadRumbleKeeper;

void addPlayerAccelStick(al::LiveActor*, sead::Vector3f*, f32, s32, const sead::Matrix34f*);
void addPlayerAccelStickGravity(al::LiveActor*, sead::Vector3f*, f32, const sead::Vector3f&, s32, const sead::Matrix34f*);
void addPlayerAccelInputGravity(al::LiveActor*, sead::Vector3f*, const sead::Vector2f&, f32, const sead::Vector3f&, const sead::Matrix34f*);
bool tryCalcTouchWorldPosPlane(const al::IUseCamera*, sead::Vector3f*, const sead::Vector3f&, const sead::Vector3f&);
bool tryCalcTouchWorldPosPlaneXZ(const al::IUseCamera*, sead::Vector3f*, f32);

class PlayerHolder {
private:
    struct Player {
        al::LiveActor* mActor = nullptr;
        al::PadRumbleKeeper* mPadRumbleKeeper = nullptr;
    };

    Player* mPlayers = nullptr;
    s32 mBufferSize = 0;
    s32 mPlayerNum = 0;

public:
    PlayerHolder(s32 maxPlayers);
    void clear();
    void registerPlayer(al::LiveActor* actor, al::PadRumbleKeeper* rumbleKeeper);
    al::LiveActor* getPlayer(s32 index) const;
    al::LiveActor* tryGetPlayer(s32 index) const;
    s32 getPlayerNum() const;
    s32 getBufferSize() const;
    bool isFull() const;
    bool isExistPadRumbleKeeper(s32 index) const;
    al::PadRumbleKeeper* getPadRumbleKeeper(s32 index) const;
};

s32 getPlayerNumMax(const al::LiveActor*);
s32 getPlayerNumMax(const al::PlayerHolder*);
s32 getAlivePlayerNum(const al::LiveActor*);
s32 getAlivePlayerNum(const al::PlayerHolder*);
al::LiveActor* getPlayerActor(const al::LiveActor*, s32);
al::LiveActor* getPlayerActor(const al::PlayerHolder*, s32);
const sead::Vector3f& getPlayerPos(const al::LiveActor*, s32);
const sead::Vector3f& getPlayerPos(const al::PlayerHolder*, s32);
al::LiveActor* tryGetPlayerActor(const al::LiveActor*, s32);
al::LiveActor* tryGetPlayerActor(const al::PlayerHolder*, s32);
bool isPlayerDead(const al::LiveActor*, s32);
bool isPlayerDead(const al::PlayerHolder*, s32);
bool isPlayerAreaTarget(const al::LiveActor*, s32);
bool isPlayerAreaTarget(const al::PlayerHolder*, s32);
al::LiveActor* tryFindAlivePlayerActorFirst(const al::LiveActor*);
al::LiveActor* tryFindAlivePlayerActorFirst(const al::PlayerHolder*);
al::LiveActor* findAlivePlayerActorFirst(const al::LiveActor*);
al::LiveActor* findAlivePlayerActorFirst(const al::PlayerHolder*);
al::PadRumbleKeeper* getPlayerPadRumbleKeeper(const al::LiveActor*, s32);
const al::PadRumbleKeeper& getPlayerPort(const al::PlayerHolder*, s32);
const al::PadRumbleKeeper& getPlayerPort(const al::LiveActor*, s32);
al::LiveActor* findAlivePlayerActorFromPort(const al::PlayerHolder*, s32);
al::LiveActor* tryFindAlivePlayerActorFromPort(const al::PlayerHolder*, s32);
al::LiveActor* findAlivePlayerActorFromPort(const al::LiveActor*, s32);
al::LiveActor* tryFindAlivePlayerActorFromPort(const al::LiveActor*, s32);
s32 findNearestPlayerId(const al::LiveActor*, f32);
al::LiveActor* findNearestPlayerActor(const al::LiveActor*);
al::LiveActor* tryFindNearestPlayerActor(const al::LiveActor*);
const sead::Vector3f& findNearestPlayerPos(const al::LiveActor*);
const sead::Vector3f& tryFindNearestPlayerPos(sead::Vector3f*, const al::LiveActor*);
const sead::Vector3f& tryFindNearestPlayerDisatanceFromTarget(f32*, const al::LiveActor*, const sead::Vector3f&);
bool isNearPlayer(const al::LiveActor*, f32);
bool isNearPlayerH(const al::LiveActor*, f32);
bool isNearPlayerHCondition(const al::LiveActor*, f32, bool (*)(const al::LiveActor*));
const sead::Vector3f& getFarPlayerPosMaxX(const al::LiveActor*);
const sead::Vector3f& getFarPlayerPosMinX(const al::LiveActor*);
u32 calcPlayerListOrderByDistance(const al::LiveActor*, const al::LiveActor**, u32);
u32 calcAlivePlayerActor(const al::LiveActor*, const al::LiveActor**, u32);
al::LiveActor* tryFindNearestPlayerActorCondition(const al::LiveActor*, bool (*)(const al::LiveActor*));
bool tryFindNearestPlayerPosCondition(sead::Vector3f*, const al::LiveActor*, bool (*)(const al::LiveActor*));
bool isResetablePlayerPos(const al::LiveActor*, const sead::Vector3f&, f32, f32);
bool isResetablePlayerPos(const al::LiveActor*, f32);
void faceToPlayer(al::LiveActor*);

}  // namespace al
