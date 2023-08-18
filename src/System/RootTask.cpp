#include "RootTask.h"
#include "GameSystem.h"
#include <al/Library/Memory/HeapUtil.h>
#include <heap/seadHeapMgr.h>

RootTask::RootTask(const sead::TaskConstructArg& constructArg) : sead::Task(constructArg, "RootTask") {}
RootTask::~RootTask() = default;
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
