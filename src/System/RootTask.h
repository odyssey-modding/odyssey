#pragma once

#include <gfx/seadDrawContext.h>

class GameSystem;

// TODO: Implement sead::Task, currently missing from sead headers
class RootTask {
private:
    // TODO: Remove once RootTask implements sead::Task
    char taskImplDetails[0x200];
    GameSystem* mGameSystem;
    sead::hostio::Node* mHostIoNode;
    sead::DrawContext* mDrawContext;
public:
    RootTask();
    ~RootTask();
    void enter() override;
    void draw() override;
    void calc() override;
    void prepare() override;
};
