#pragma once

#include <al/Library/Camera/CameraDirector.h>
#include <basis/seadTypes.h>

namespace al {
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

void getPlayerNumMax(const al::LiveActor*);
void getPlayerNumMax(const al::PlayerHolder*);
void getAlivePlayerNum(const al::LiveActor*);
void getAlivePlayerNum(const al::PlayerHolder*);
void getPlayerActor(const al::LiveActor*, s32);
void getPlayerActor(const al::PlayerHolder*, s32);
void getPlayerPos(const al::LiveActor*, s32);
void getPlayerPos(const al::PlayerHolder*, s32);
bool tryGetPlayerActor(const al::LiveActor*, s32);
bool tryGetPlayerActor(const al::PlayerHolder*, s32);
bool isPlayerDead(const al::LiveActor*, s32);
bool isPlayerDead(const al::PlayerHolder*, s32);
bool isPlayerAreaTarget(const al::LiveActor*, s32);
bool isPlayerAreaTarget(const al::PlayerHolder*, s32);
bool tryFindAlivePlayerActorFirst(const al::LiveActor*);
bool tryFindAlivePlayerActorFirst(const al::PlayerHolder*);
void findAlivePlayerActorFirst(const al::LiveActor*);
void findAlivePlayerActorFirst(const al::PlayerHolder*);
void getPlayerPadRumbleKeeper(const al::LiveActor*, s32);
void getPlayerPort(const al::PlayerHolder*, s32);
void getPlayerPort(const al::LiveActor*, s32);
void findAlivePlayerActorFromPort(const al::PlayerHolder*, s32);
bool tryFindAlivePlayerActorFromPort(const al::PlayerHolder*, s32);
void findAlivePlayerActorFromPort(const al::LiveActor*, s32);
bool tryFindAlivePlayerActorFromPort(const al::LiveActor*, s32);
void findNearestPlayerId(const al::LiveActor*, f32);
void findNearestPlayerActor(const al::LiveActor*);
bool tryFindNearestPlayerActor(const al::LiveActor*);
void findNearestPlayerPos(const al::LiveActor*);
bool tryFindNearestPlayerPos(sead::Vector3f*, const al::LiveActor*);
bool tryFindNearestPlayerDisatanceFromTarget(f32*, const al::LiveActor*, const sead::Vector3f&);
bool isNearPlayer(const al::LiveActor*, f32);
bool isNearPlayerH(const al::LiveActor*, f32);
bool isNearPlayerHCondition(const al::LiveActor*, f32, bool (*)(const al::LiveActor*));
void getFarPlayerPosMaxX(const al::LiveActor*);
void getFarPlayerPosMinX(const al::LiveActor*);
void calcPlayerListOrderByDistance(const al::LiveActor*, const al::LiveActor**, u32);
void calcAlivePlayerActor(const al::LiveActor*, const al::LiveActor**, u32);
bool tryFindNearestPlayerActorCondition(const al::LiveActor*, bool (*)(const al::LiveActor*));
bool tryFindNearestPlayerPosCondition(sead::Vector3f*, const al::LiveActor*, bool (*)(const al::LiveActor*));
bool isResetablePlayerPos(const al::LiveActor*, const sead::Vector3f&, f32, f32);
bool isResetablePlayerPos(const al::LiveActor*, f32);
void faceToPlayer(al::LiveActor*);

}  // namespace al
