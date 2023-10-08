#include "WorldMapEarth.h"
#include <al/Library/LiveActor/ActorInitFunction.h>
#include <al/Library/LiveActor/ActorPoseKeeper.h>
#include <al/Library/Math/MathAngleUtil.h>
#include <al/Library/Math/MathSpeedUtil.h>

WorldMapEarth::WorldMapEarth(const char* name) : al::LiveActor(name) {}

void WorldMapEarth::init(const al::ActorInitInfo& initInfo) {
    al::initMapPartsActor(this, initInfo, nullptr);
    makeActorAlive();
}

void WorldMapEarth::control() {
    al::setRotateY(this, al::modf(al::getRotate(this).y + 0.05f + 360.0f, 360.0f) + 0.0f);
}
