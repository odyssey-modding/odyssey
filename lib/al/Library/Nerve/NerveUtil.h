#pragma once

#include <basis/seadTypes.h>

namespace al {
class IUseNerve;
class Nerve;
class NerveStateBase;

void setNerve(al::IUseNerve* user, const al::Nerve* nerve);
void setNerveAtStep(al::IUseNerve* user, const al::Nerve* nerve, s32 step);
void setNerveAtGreaterEqualStep(al::IUseNerve* user, const al::Nerve* nerve, s32 step);

bool isStep(const al::IUseNerve* user, s32 step);
bool isFirstStep(const al::IUseNerve* user);
bool isGreaterStep(const al::IUseNerve* user, s32 step);
bool isGreaterEqualStep(const al::IUseNerve* user, s32 step);
bool isLessStep(const al::IUseNerve* user, s32 step);
bool isLessEqualStep(const al::IUseNerve* user, s32 step);
bool isInRangeStep(const al::IUseNerve* user, s32 startStep, s32 endStep);
bool isIntervalStep(const al::IUseNerve* user, s32 interval, s32 offset);
bool isIntervalOnOffStep(const al::IUseNerve* user, s32 interval, s32 offset);

bool isNerve(const al::IUseNerve* user, const al::Nerve* nerve);
bool isNewNerve(const al::IUseNerve* user);

f32 calcNerveInterval(const al::IUseNerve* user, s32, s32);
f32 calcNerveRate(const al::IUseNerve* user, s32);
f32 calcNerveRate(const al::IUseNerve* user, s32, s32);
f32 calcNerveEaseInRate(const al::IUseNerve* user, s32);
f32 calcNerveEaseInRate(const al::IUseNerve* user, s32, s32);
f32 calcNerveEaseOutRate(const al::IUseNerve* user, s32);
f32 calcNerveEaseOutRate(const al::IUseNerve* user, s32, s32);
f32 calcNerveEaseInOutRate(const al::IUseNerve* user, s32);
f32 calcNerveEaseInOutRate(const al::IUseNerve* user, s32, s32);
f32 calcNerveSquareInRate(const al::IUseNerve* user, s32);
f32 calcNerveSquareInRate(const al::IUseNerve* user, s32, s32);
f32 calcNerveSquareOutRate(const al::IUseNerve* user, s32);
f32 calcNerveSquareOutRate(const al::IUseNerve* user, s32, s32);
f32 calcNerveEaseByTypeRate(const al::IUseNerve* user, s32, s32);
f32 calcNerveEaseByTypeRate(const al::IUseNerve* user, s32, s32, s32);
f32 calcNervePowerInRate(const al::IUseNerve* user, s32, f32);
f32 calcNervePowerInRate(const al::IUseNerve* user, s32, s32, f32);
f32 calcNervePowerOutRate(const al::IUseNerve* user, s32, f32);
f32 calcNervePowerOutRate(const al::IUseNerve* user, s32, s32, f32);
f32 calcNerveJumpRate(const al::IUseNerve* user, s32, s32, s32);
f32 calcNerveEaseInValue(const al::IUseNerve* user, s32, s32, f32, f32);
f32 calcNerveStartEndRate(const al::IUseNerve* user, s32, s32, s32);
f32 calcNerveEaseInOutValue(const al::IUseNerve* user, s32, s32, f32, f32);
f32 calcNerveValue(const al::IUseNerve* user, s32, f32, f32);
f32 calcNerveValue(const al::IUseNerve* user, s32, s32, f32, f32);
f32 calcNerveEaseInValue(const al::IUseNerve* user, s32, f32, f32);
f32 calcNerveEaseOutValue(const al::IUseNerve* user, s32, f32, f32);
f32 calcNerveEaseOutValue(const al::IUseNerve* user, s32, s32, f32, f32);
f32 calcNerveEaseInOutValue(const al::IUseNerve* user, s32, f32, f32);
f32 calcNerveSquareInValue(const al::IUseNerve* user, s32, f32, f32);
f32 calcNerveSquareInValue(const al::IUseNerve* user, s32, s32, f32, f32);
f32 calcNerveSquareOutValue(const al::IUseNerve* user, s32, f32, f32);
f32 calcNerveSquareOutValue(const al::IUseNerve* user, s32, s32, f32, f32);
f32 calcNerveEaseByTypeValue(const al::IUseNerve* user, s32, f32, f32, s32);
f32 calcNerveEaseByTypeValue(const al::IUseNerve* user, s32, s32, f32, f32, s32);
f32 calcNerveCosCycle(const al::IUseNerve* user, s32);
f32 calcNerveSinCycle(const al::IUseNerve* user, s32);
f32 calcNerveRepeatRate(const al::IUseNerve* user, s32);
f32 calcNerveRepeatDegree(const al::IUseNerve* user, s32);
f32 calcNerveJumpValue(const al::IUseNerve* user, s32, s32, s32, f32);
f32 calcNerveStartEndValue(const al::IUseNerve* user, s32, s32, s32, f32, f32);

void initNerveState(al::IUseNerve* user, al::NerveStateBase* state, const al::Nerve* nerve, const char* hostName);
void addNerveState(al::IUseNerve* user, al::NerveStateBase* state, const al::Nerve* nerve, const char* hostName);
bool updateNerveState(al::IUseNerve* user);
void updateNerveStateAndNextNerve(al::IUseNerve* user, const al::Nerve* nerve);
void isStateEnd(const al::IUseNerve* user);

class NerveAction;
}  // namespace al

class alNerveFunction {
public:
    static void setNerveAction(al::IUseNerve* user, const char* action);

    class NerveActionCollector {
    private:
        friend class al::NerveAction;
        static alNerveFunction::NerveActionCollector* sCurrentCollector;

        s32 mActionCount = 0;
        al::NerveAction* mHead = nullptr;
        al::NerveAction* mTail = nullptr;

    public:
        NerveActionCollector();
        void addNerve(al::NerveAction* action);
    };
};
