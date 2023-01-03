#pragma once

#include <basis/seadTypes.h>

namespace al {
class LiveActor;
class PadRumbleKeeper;

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

}  // namespace al
