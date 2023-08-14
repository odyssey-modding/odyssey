#include "GameSystem.h"
#include "Application.h"
#include "System/GameConfigData.h"
#include <al/Library/System/GameSystemInfo.h>

namespace {

NERVE_IMPL(GameSystem, Play);

struct {
    NERVE_MAKE(GameSystem, Play);
} NrvGameSystem;

}  // namespace
