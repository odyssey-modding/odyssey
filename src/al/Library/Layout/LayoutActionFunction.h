#pragma once

namespace al {
class IUseLayoutAction;
class Nerve;

void startAction(al::IUseLayoutAction* layout, const char* actionName, const char* paneName);
void startFreezeAction(al::IUseLayoutAction* layout, const char* actionName, f32 frame,
                       const char* paneName);
void startFreezeActionEnd(al::IUseLayoutAction* layout, const char* actionName,
                          const char* paneName);
void startActionAtRandomFrame(al::IUseLayoutAction* layout, const char* actionName,
                              const char* paneName);
void startFreezeGaugeAction(al::IUseLayoutAction* layout, f32 value, f32 minFrame,
                            f32 maxFrame, const char* actionName, const char* paneName);

bool tryStartAction(al::IUseLayoutAction* layout, const char* actionName, const char* paneName);

f32 getActionFrame(const al::IUseLayoutAction* layout, const char* paneName);
f32 getActionFrameRate(const al::IUseLayoutAction* layout, const char* paneName);
f32 getActionFrameMax(const al::IUseLayoutAction* layout, const char* actionName,
                        const char* paneName);

void setActionFrameRate(const al::IUseLayoutAction* layout, f32 frameRate, const char* paneName);
void setActionFrame(const al::IUseLayoutAction* layout, f32 frame, const char* paneName);

bool isActionOneTime(const al::IUseLayoutAction* layout, const char* actionName,
                     const char* paneName);
bool isActionPlaying(const al::IUseLayoutAction* layout, const char* actionName,
                     const char* paneName);
bool isAnyActionPlaying(const al::IUseLayoutAction* layout, const char* paneName);
bool isActionEnd(const al::IUseLayoutAction* layout, const char* paneName);

bool isExistAction(const al::IUseLayoutAction* layout, const char* actionName);
bool isExistAction(const al::IUseLayoutAction* layout, const char* actionName,
                   const char* paneName);

void setNerveAtActionEnd(const al::IUseLayoutAction* layout, const al::Nerve* nerve);
}  // namespace al
