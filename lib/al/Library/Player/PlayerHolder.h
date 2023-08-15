#pragma once

#include <basis/seadTypes.h>
#include <al/Library/Camera/CameraDirector.h>

namespace al {
class LiveActor;
class PadRumbleKeeper;

void addPlayerAccelStick(al::LiveActor*, sead::Vector3f*, f32, s32, const sead::Matrix34f*);
void addPlayerAccelStickGravity(al::LiveActor*, sead::Vector3f*, f32, const sead::Vector3f&, s32, const sead::Matrix34f*);
void addPlayerAccelInputGravity(al::LiveActor*, sead::Vector3f*, sead::Vector2<f32> const&, f32, const sead::Vector3f&, const sead::Matrix34f*);
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

void getPlayerNumMax(al::LiveActor const*);
void getPlayerNumMax(al::PlayerHolder const*);
void getAlivePlayerNum(al::LiveActor const*);
void getAlivePlayerNum(al::PlayerHolder const*);
void getPlayerActor(al::LiveActor const*, s32);
void getPlayerActor(al::PlayerHolder const*, s32);
void getPlayerPos(al::LiveActor const*, s32);
void getPlayerPos(al::PlayerHolder const*, s32);
bool tryGetPlayerActor(al::LiveActor const*, s32);
bool tryGetPlayerActor(al::PlayerHolder const*, s32);
bool isPlayerDead(al::LiveActor const*, s32);
bool isPlayerDead(al::PlayerHolder const*, s32);
bool isPlayerAreaTarget(al::LiveActor const*, s32);
bool isPlayerAreaTarget(al::PlayerHolder const*, s32);
bool tryFindAlivePlayerActorFirst(al::LiveActor const*);
bool tryFindAlivePlayerActorFirst(al::PlayerHolder const*);
void findAlivePlayerActorFirst(al::LiveActor const*);
void findAlivePlayerActorFirst(al::PlayerHolder const*);
void getPlayerPadRumbleKeeper(al::LiveActor const*, s32);
void getPlayerPort(al::PlayerHolder const*, s32);
void getPlayerPort(al::LiveActor const*, s32);
void findAlivePlayerActorFromPort(al::PlayerHolder const*, s32);
bool tryFindAlivePlayerActorFromPort(al::PlayerHolder const*, s32);
void findAlivePlayerActorFromPort(al::LiveActor const*, s32);
bool tryFindAlivePlayerActorFromPort(al::LiveActor const*, s32);
void findNearestPlayerId(al::LiveActor const*, f32);
void findNearestPlayerActor(al::LiveActor const*);
bool tryFindNearestPlayerActor(al::LiveActor const*);
void findNearestPlayerPos(al::LiveActor const*);
bool tryFindNearestPlayerPos(sead::Vector3f*, al::LiveActor const*);
bool tryFindNearestPlayerDisatanceFromTarget(f32*, al::LiveActor const*, const sead::Vector3f&);
bool isNearPlayer(al::LiveActor const*, f32);
bool isNearPlayerH(al::LiveActor const*, f32);
bool isNearPlayerHCondition(al::LiveActor const*, f32, bool (*)(al::LiveActor const*));
void getFarPlayerPosMaxX(al::LiveActor const*);
void getFarPlayerPosMinX(al::LiveActor const*);
void calcPlayerListOrderByDistance(al::LiveActor const*, al::LiveActor const**, u32);
void calcAlivePlayerActor(al::LiveActor const*, al::LiveActor const**, u32);
bool tryFindNearestPlayerActorCondition(al::LiveActor const*, bool (*)(al::LiveActor const*));
bool tryFindNearestPlayerPosCondition(sead::Vector3f*, al::LiveActor const*, bool (*)(al::LiveActor const*));
bool isResetablePlayerPos(al::LiveActor const*, const sead::Vector3f&, f32, f32);
bool isResetablePlayerPos(al::LiveActor const*, f32);
void faceToPlayer(al::LiveActor*);

}  // namespace al
