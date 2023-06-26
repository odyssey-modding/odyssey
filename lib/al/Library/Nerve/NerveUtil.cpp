#include <al/Library/Nerve/NerveUtil.h>
#include <al/Library/Nerve/NerveKeeper.h>
#include <al/Library/IUse/IUseNerve.h>

namespace al {
void setNerve(al::IUseNerve* user, const al::Nerve* nerve) {
    user->getNerveKeeper()->setNerve(nerve);
}
void setNerveAtStep(al::IUseNerve* user, const al::Nerve* nerve, s32 step) {
    if (user->getNerveKeeper()->getCurrentStep() == step)
        user->getNerveKeeper()->setNerve(nerve);
}
void setNerveAtGreaterEqualStep(al::IUseNerve* user, const al::Nerve* nerve, s32 step) {
    if (user->getNerveKeeper()->getCurrentStep() >= step)
        user->getNerveKeeper()->setNerve(nerve);
}
bool isStep(const al::IUseNerve *user, s32 step){
return user->getNerveKeeper()->getCurrentStep() == step;
}
bool isFirstStep(const al::IUseNerve *user){
    return isStep(user, 0);
}
bool isGreaterStep(const al::IUseNerve *user, s32 step){
return user->getNerveKeeper()->getCurrentStep() > step;
}
bool isGreaterEqualStep(const al::IUseNerve* user, s32 step) {
    return user->getNerveKeeper()->getCurrentStep() >= step;
}
bool isLessStep(const al::IUseNerve* user, s32 step) {
    return user->getNerveKeeper()->getCurrentStep() < step;
}
bool isLessEqualStep(const al::IUseNerve* user, s32 step) {
    return user->getNerveKeeper()->getCurrentStep() <= step;
}
bool isInRangeStep(const al::IUseNerve* user, s32 startStep, s32 endStep) {
    al::NerveKeeper* nerveKeeper = user->getNerveKeeper();
    return startStep <= nerveKeeper->getCurrentStep() && nerveKeeper->getCurrentStep() <= endStep;
}
bool isIntervalStep(const al::IUseNerve* user, s32 interval, s32 offset) {
    s32 currentStep = user->getNerveKeeper()->getCurrentStep() - offset;
    if (currentStep < 0) return false;
    return currentStep == (interval != 0 ? currentStep / interval : 0) * interval;
}
bool isIntervalOnOffStep(const al::IUseNerve* user, s32 interval, s32 offset) {
    if (interval == 0) return false;
    return ((user->getNerveKeeper()->getCurrentStep() - offset) / interval) == 0;
}
bool isNerve(const al::IUseNerve* user, const al::Nerve* nerve) {
    return user->getNerveKeeper()->getCurrentNerve() == nerve;
}
bool isNewNerve(const al::IUseNerve* user) {
    return user->getNerveKeeper()->isNewNerve();
}
}
