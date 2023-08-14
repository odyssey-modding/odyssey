#include "RootTask.h"
#include <al/Library/Memory/HeapUtil.h>
#include <heap/seadHeapMgr.h>
#include "GameSystem.h"

void RootTask::enter() {}
void RootTask::calc() {
    if (!mGameSystem) {
        sead::ScopedCurrentHeapSetter heapSetter(al::getStationedHeap());
        mGameSystem = new GameSystem();
        mGameSystem->init();
    }
    mGameSystem->movement();
}
void RootTask::draw() {
    if (mGameSystem)
        mGameSystem->drawMain();
}
