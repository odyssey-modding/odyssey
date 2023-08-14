#include "FootPrint.h"
#include <al/Library/Collision/PartsConnector.h>
#include <al/Library/LiveActor/ActorAnimFunction.h>
#include <al/Library/LiveActor/ActorInitFunction.h>
#include <al/Library/Nerve/NerveSetupUtil.h>

namespace {
using namespace al;
NERVE_IMPL(FootPrint, Appear);
NERVE_MAKE(FootPrint, Appear);
NERVE_IMPL(FootPrint, Disappear);
NERVE_MAKE(FootPrint, Disappear);

}  // namespace

namespace al {

FootPrint::FootPrint(al::ActorInitInfo const& info, char const* name) : al::LiveActor("足跡オブジェ") {
    al::initChildActorWithArchiveNameNoPlacementInfo(this, info, name, 0);
    al::initNerve(this, &Appear, 0);
    mConnector = new al::CollisionPartsConnector();
    makeActorDead();
};

void FootPrint::appear() {
    al::LiveActor::appear();
    al::setNerve(this, &Appear);
    al::invalidateClipping(this);
}

void FootPrint::exeAppear() {
    if (al::isFirstStep(this)) {
        al::tryStartMclAnimIfExist(this, "Appear");
        al::setMclAnimFrameAndStop(this, 0.0f);
    }
    if (!mConnector->isConnecting())
        kill();
}

void FootPrint::exeDisappear() {
    if (al::isFirstStep(this) && !al::tryStartMclAnimIfExist(this, "Disappear"))
        return kill();
    if (al::isMclAnimEnd(this))
        kill();
}

bool FootPrint::isDisappear() const {
    return al::isNerve(this, &Disappear);
}

void FootPrint::setAnimationByMaterial(char const* materialName) {
    al::startMtsAnim(this, materialName);
    mMaterialName = materialName;
}

void FootPrint::setAnimationByCharacter(char const* characterName) {
    al::tryStartMtsAnimIfExist(this, characterName);
}

void FootPrint::setAnimationByMetamorphosis(char const* animName) {
    al::tryStartVisAnimIfExist(this, animName);
}

void FootPrint::control() {
    if (mConnector->isMoved())
        al::connectPoseQT(this, mConnector);
}

}  // namespace al
