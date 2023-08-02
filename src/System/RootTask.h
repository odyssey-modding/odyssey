#pragma once

#include <gfx/seadDrawContext.h>
#include <hostio/seadHostIONode.h>

class GameSystem;

// Waiting for open-ead/sead#130
class RootTask /*: public sead::Task*/ {
private:
    char task_details[0x200];
    GameSystem* mGameSystem;
    sead::hostio::Node* mHostIoNode;
    sead::DrawContext* mDrawContext;
public:
    RootTask();
    ~RootTask();
    void enter()/* override*/;
    void draw()/* override*/;
    void calc()/* override*/;
    void prepare()/* override*/;
};
