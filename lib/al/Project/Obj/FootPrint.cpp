#include <al/Library/Collision/PartsConnector.h>
#include <al/Library/LiveActor/ActorAnimFunction.h>
#include <al/Library/LiveActor/ActorInitFunction.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Project/Obj/FootPrint.h>

namespace {
using namespace al;
// This interleaving of macros is required. Perhaps this is one of the few nerves in the game to use multiple structs, for some reason?
NERVE_IMPL(FootPrint, Appear);
NERVE_MAKE(FootPrint, Appear);
NERVE_IMPL(FootPrint, Disappear);
NERVE_MAKE(FootPrint, Disappear);

}  // namespace

namespace al {

FootPrint::FootPrint(const al::ActorInitInfo& info, const char* name) : al::LiveActor("足跡オブジェ") {
    al::initChildActorWithArchiveNameNoPlacementInfo(this, info, name, 0);
    al::initNerve(this, &Appear, 0);
    mConnector = new al::CollisionPartsConnector();
    makeActorDead();
}

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
    if (al::isFirstStep(this)) {
        bool animStarted = al::tryStartMclAnimIfExist(this, "Disappear");
        if(!animStarted) {
            kill();
            return;
        }
    }
    
    if (al::isMclAnimEnd(this))
        kill();
}

bool FootPrint::isDisappear() const {
    return al::isNerve(this, &Disappear);
}

void FootPrint::setAnimationByMaterial(const char* materialName) {
    al::startMtsAnim(this, materialName);
    mMaterialName = materialName;
}

void FootPrint::setAnimationByCharacter(const char* characterName) {
    al::tryStartMtsAnimIfExist(this, characterName);
}

void FootPrint::setAnimationByMetamorphosis(const char* animName) {
    al::tryStartVisAnimIfExist(this, animName);
}

void FootPrint::control() {
    if (mConnector->isMoved())
        al::connectPoseQT(this, mConnector);
}

}  // namespace al
