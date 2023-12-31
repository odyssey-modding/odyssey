#pragma once
#include <heap/seadDisposer.h>

namespace al {
class SystemKit;
class GameFrameworkNx;
class AccountHolder;
class DrawSystemInfo;
}
class RootTask;

class Application {
    friend class ApplicationFunction;
    SEAD_SINGLETON_DISPOSER(Application);

private:
    al::SystemKit* mSystemKit;
    al::GameFrameworkNx* mGameFramework;
    al::AccountHolder* mAccountHolder;
    al::DrawSystemInfo* mDrawSystemInfo;

public:
    Application();
    void init(s32 argc, char** argv);
    void run();
    RootTask* getRootTask() const;
    al::SystemKit* getSystemKit() const { return mSystemKit; }
    al::GameFrameworkNx* getGameFramework() const { return mGameFramework; }
    al::AccountHolder* getAccountHolder() const { return mAccountHolder; }
    al::DrawSystemInfo* getDrawSystemInfo() const { return mDrawSystemInfo; }
};

namespace agl {
class RenderBuffer;
class DrawContext;
}  // namespace agl
