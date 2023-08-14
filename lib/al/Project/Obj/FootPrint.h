#pragma once

#include <al/Library/Collision/PartsConnector.h>
#include <al/Library/LiveActor/LiveActor.h>

namespace al {
class FootPrint : public al::LiveActor {
private:
    al::CollisionPartsConnector* mConnector = nullptr;
    char const* mMaterialName = nullptr;

public:
    FootPrint(al::ActorInitInfo const&, char const*);
    void appear();
    void startDisappear();
    bool isDisappear() const;
    void exeAppear();
    void exeDisappear();
    void setAnimationByMaterial(char const*);
    void setAnimationByCharacter(char const*);
    void setAnimationByMetamorphosis(char const*);
    void setFollowCollisionParts(al::CollisionParts const*);
    void control();
};
}  // namespace al