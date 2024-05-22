#pragma once

#include <al/Library/LiveActor/LiveActor.h>

namespace al {
class CollisionPartsConnector;

class FootPrint : public al::LiveActor {
private:
    al::CollisionPartsConnector* mConnector = nullptr;
    const char* mMaterialName = nullptr;

public:
    FootPrint(const al::ActorInitInfo&, const char*);
    void appear();
    void startDisappear();
    bool isDisappear() const;
    void exeAppear();
    void exeDisappear();
    void setAnimationByMaterial(const char*);
    void setAnimationByCharacter(const char*);
    void setAnimationByMetamorphosis(const char*);
    void setFollowCollisionParts(const al::CollisionParts*);
    void control();
};
}  // namespace al