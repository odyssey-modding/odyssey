#pragma once

#include <basis/seadTypes.h>
#include <mc/seadCoreInfo.h>
#include <prim/seadSafeString.h>
#include <al/Library/Thread/FunctorV0M.h>

namespace sead {
class DelegateThread;
class Thread;
}  // namespace sead

namespace al {
class AsyncFunctorThread {
private:
    sead::DelegateThread* mDelegateThread = nullptr;
    FunctorBase* mFunctor = nullptr;
    bool mIsDone = true;

public:
    AsyncFunctorThread(const sead::SafeString& functor_name, const FunctorBase& functor,
                       s32 priority, s32 stack_size, sead::CoreId id);
    virtual ~AsyncFunctorThread();

    void threadFunction(sead::Thread* unused_1, s64 unused_2);
    void start();
    bool isDone() const;
};
static_assert(sizeof(AsyncFunctorThread) == 0x20);
}  // namespace al
