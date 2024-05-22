#include "Boss/Mofumofu/MofumofuWarpHole.h"
#include <al/Library/Effect/EffectSystemInfo.h>
#include <al/Library/Joint/JointControllerKeeper.h>
#include <al/Library/LiveActor/ActorActionFunction.h>
#include <al/Library/LiveActor/ActorInitFunction.h>
#include <al/Library/LiveActor/ActorModelFunction.h>
#include <al/Library/LiveActor/ActorPoseKeeper.h>
#include <al/Library/Math/MathAngleUtil.h>
#include <al/Library/Nerve/NerveSetupUtil.h>
#include <al/Library/Nerve/NerveUtil.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace {

NERVE_IMPL(MofumofuWarpHole, Close);
NERVE_IMPL(MofumofuWarpHole, Disappear);
NERVE_IMPL(MofumofuWarpHole, Appear);
NERVE_IMPL(MofumofuWarpHole, HideMove);
NERVE_IMPL(MofumofuWarpHole, HideWait);
NERVE_IMPL(MofumofuWarpHole, Wait);
NERVE_IMPL(MofumofuWarpHole, DashSign);
NERVE_IMPL(MofumofuWarpHole, DashSignEnd);
NERVE_IMPL_(MofumofuWarpHole, CloseAndDisappear, Close);

struct {
    NERVE_MAKE(MofumofuWarpHole, Close);
    NERVE_MAKE(MofumofuWarpHole, Disappear);
    NERVE_MAKE(MofumofuWarpHole, Appear);
    NERVE_MAKE(MofumofuWarpHole, HideMove);
    NERVE_MAKE(MofumofuWarpHole, HideWait);
    NERVE_MAKE(MofumofuWarpHole, Wait);
    NERVE_MAKE(MofumofuWarpHole, DashSign);
    NERVE_MAKE(MofumofuWarpHole, DashSignEnd);
    NERVE_MAKE(MofumofuWarpHole, CloseAndDisappear);
} NrvMofumofuWarpHole;

}  // namespace

MofumofuWarpHole::MofumofuWarpHole(const char* name) : al::LiveActor(name) {}

void MofumofuWarpHole::init(const al::ActorInitInfo& actorInitInfo) {
    al::initActorWithArchiveName(this, actorInitInfo, "MofumofuWarpHole", nullptr);
    al::initNerve(this, &NrvMofumofuWarpHole.Appear, 0);
    al::initJointControllerKeeper(this, 1);
    al::initJointGlobalQuatController(this, &gap, "DashSign");
    makeActorDead();
}

void MofumofuWarpHole::appear() {
    al::LiveActor::appear();
    al::setNerve(this, &NrvMofumofuWarpHole.Appear);
}

void MofumofuWarpHole::disappear() {
    al::setNerve(this, &NrvMofumofuWarpHole.Disappear);
}
void MofumofuWarpHole::close() {
    al::setNerve(this, &NrvMofumofuWarpHole.Close);
}
void MofumofuWarpHole::closeAndDisappear() {
    al::setNerve(this, &NrvMofumofuWarpHole.CloseAndDisappear);
}
void MofumofuWarpHole::open() {
    al::setNerve(this, &NrvMofumofuWarpHole.Appear);
}
void MofumofuWarpHole::startHideMove() {
    al::setNerve(this, &NrvMofumofuWarpHole.HideMove);
}
void MofumofuWarpHole::startDashSign() {
    al::setNerve(this, &NrvMofumofuWarpHole.DashSign);
}
bool MofumofuWarpHole::isWait() const {
    return al::isNerve(this, &NrvMofumofuWarpHole.Wait);
}
bool MofumofuWarpHole::isHideWait() const {
    return al::isNerve(this, &NrvMofumofuWarpHole.HideWait);
}
void MofumofuWarpHole::calcDashSignFront(sead::Vector3f* front) const {
    al::calcJointFrontDir(front, this, "DashSign");
}
void MofumofuWarpHole::exeAppear() {
    if (al::isFirstStep(this))
        al::startAction(this, "Appear");
    al::setNerveAtActionEnd(this, &NrvMofumofuWarpHole.Wait);
}
void MofumofuWarpHole::exeWait() {
    if (al::isFirstStep(this))
        al::startAction(this, "Wait");
}
void MofumofuWarpHole::exeDisappear() {
    if (al::isFirstStep(this))
        al::startAction(this, "Disappear");
    if (!al::isEffectEmitting(this, "Disappear"))
        kill();
}
void MofumofuWarpHole::exeClose() {
    if (al::isFirstStep(this))
        al::startAction(this, "Disappear");

    if (al::isActionEnd(this)) {
        if (al::isNerve(this, &NrvMofumofuWarpHole.CloseAndDisappear))
            al::setNerve(this, &NrvMofumofuWarpHole.Disappear);
        else
            al::setNerve(this, &NrvMofumofuWarpHole.HideWait);
    }
}
void MofumofuWarpHole::exeHideWait() {}
void MofumofuWarpHole::exeHideMove() {
    if (al::isFirstStep(this))
        al::startAction(this, "Move");
}
/*
void MofumofuWarpHole::exeDashSign() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "DashSign");
        al::calcQuat(&gap, this);
    }

    sead::Vector3f* playerPos = rs::getPlayerPos(this);
    const sead::Vector3f& trans = al::getTrans(this);

    sead::Vector3f a3 = (*playerPos) - (trans);
    al::verticalizeVec(&a3, al::getGravity(this), a3);
    if (!al::tryNormalizeOrZero(&a3))
        a3 = al::getFront(this);  // TODO small mismatch here

    al::turnVecToVecDegree(&a3, al::getFront(this), a3, 55);
    al::normalize(&a3);

    sead::Vector3f v21{0, 0, 0};
    al::calcQuatFront(&v21, gap);

    f32 v13 = al::calcNerveEaseInRate(this, 100, 120);
    f32 v14 = al::lerpValue(0.3, 0.05, v13);
    al::turnVecToVecRate(&a3, v21, a3, v14);
    al::normalize(&a3);
    al::turnVecToVecRate(&v21, v21, a3, 0.15);
    al::normalize(&v21);

    const sead::Vector3f& v15 = al::getGravity(this);
    sead::Vector3f v20{-v15.x, -v15.y, -v15.z};
    al::makeQuatFrontUp(&gap, v21, v20);
    al::setNerveAtGreaterEqualStep(this, &NrvMofumofuWarpHole.DashSignEnd, 120);
}
void MofumofuWarpHole::exeDashSignEnd() {
    if (al::isFirstStep(this))
        al::startAction(this, "DashSignEnd");
    al::setNerveAtActionEnd(this, &NrvMofumofuWarpHole.Wait);
}
*/