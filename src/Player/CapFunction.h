#pragma once

class HackCap;
class PlayerAnimator;

namespace CapFunction {
void endHack(HackCap*, PlayerAnimator*);
void getHackObjInfo(HackCap*);
void putOnCapPlayer(HackCap*, PlayerAnimator*);
}  // namespace CapFunction