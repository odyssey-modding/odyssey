#pragma once

#include <basis/seadTypes.h>
namespace al {
class Nerve;
class NerveStateBase;

class NerveStateCtrl {
    struct State {
        al::NerveStateBase* state;
        const al::Nerve* nerve;
        const char* name;
    };

private:
    s32 mMaxStates;
    s32 mStateCount;
    State* mStates;
    State* mCurrentState;

public:
    NerveStateCtrl(s32 maxStates);

    void addState(al::NerveStateBase* state, const al::Nerve* nerve, const char* name);
    bool updateCurrentState();
    void startState(const al::Nerve* nerve);
    void update();

    State* findStateInfo(const al::Nerve* nerve);
    bool isCurrentStateEnd() const;
    void tryEndCurrentState();
};

}  // namespace al
