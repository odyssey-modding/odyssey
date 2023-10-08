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

void calcNerveInterval(const al::IUseNerve* user, s32, s32);
f32 calcNerveRate(const al::IUseNerve* user, s32);
f32 calcNerveRate(const al::IUseNerve* user, s32, s32);
void calcNerveEaseInRate(const al::IUseNerve* user, s32);
void calcNerveEaseInRate(const al::IUseNerve* user, s32, s32);
void calcNerveEaseOutRate(const al::IUseNerve* user, s32);
void calcNerveEaseOutRate(const al::IUseNerve* user, s32, s32);
void calcNerveEaseInOutRate(const al::IUseNerve* user, s32);
void calcNerveEaseInOutRate(const al::IUseNerve* user, s32, s32);
void calcNerveSquareInRate(const al::IUseNerve* user, s32);
void calcNerveSquareInRate(const al::IUseNerve* user, s32, s32);
void calcNerveSquareOutRate(const al::IUseNerve* user, s32);
void calcNerveSquareOutRate(const al::IUseNerve* user, s32, s32);
void calcNerveEaseByTypeRate(const al::IUseNerve* user, s32, s32);
void calcNerveEaseByTypeRate(const al::IUseNerve* user, s32, s32, s32);
void calcNervePowerInRate(const al::IUseNerve* user, s32, f32);
void calcNervePowerInRate(const al::IUseNerve* user, s32, s32, f32);
void calcNervePowerOutRate(const al::IUseNerve* user, s32, f32);
void calcNervePowerOutRate(const al::IUseNerve* user, s32, s32, f32);
void calcNerveJumpRate(const al::IUseNerve* user, s32, s32, s32);
void calcNerveEaseInValue(const al::IUseNerve* user, s32, s32, f32, f32);
void calcNerveStartEndRate(const al::IUseNerve* user, s32, s32, s32);
void calcNerveEaseInOutValue(const al::IUseNerve* user, s32, s32, f32, f32);
void calcNerveValue(const al::IUseNerve* user, s32, f32, f32);
void calcNerveValue(const al::IUseNerve* user, s32, s32, f32, f32);
void calcNerveEaseInValue(const al::IUseNerve* user, s32, f32, f32);
void calcNerveEaseOutValue(const al::IUseNerve* user, s32, f32, f32);
void calcNerveEaseOutValue(const al::IUseNerve* user, s32, s32, f32, f32);
void calcNerveEaseInOutValue(const al::IUseNerve* user, s32, f32, f32);
void calcNerveSquareInValue(const al::IUseNerve* user, s32, f32, f32);
void calcNerveSquareInValue(const al::IUseNerve* user, s32, s32, f32, f32);
void calcNerveSquareOutValue(const al::IUseNerve* user, s32, f32, f32);
void calcNerveSquareOutValue(const al::IUseNerve* user, s32, s32, f32, f32);
void calcNerveEaseByTypeValue(const al::IUseNerve* user, s32, f32, f32, s32);
void calcNerveEaseByTypeValue(const al::IUseNerve* user, s32, s32, f32, f32, s32);
void calcNerveCosCycle(const al::IUseNerve* user, s32);
void calcNerveSinCycle(const al::IUseNerve* user, s32);
void calcNerveRepeatRate(const al::IUseNerve* user, s32);
void calcNerveRepeatDegree(const al::IUseNerve* user, s32);
void calcNerveJumpValue(const al::IUseNerve* user, s32, s32, s32, f32);
void calcNerveStartEndValue(const al::IUseNerve* user, s32, s32, s32, f32, f32);

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
