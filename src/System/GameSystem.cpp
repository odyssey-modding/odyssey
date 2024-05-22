#include "GameSystem.h"
#include <al/Library/Nerve/NerveSetupUtil.h>

namespace {

NERVE_IMPL(GameSystem, Play);

struct {
    NERVE_MAKE(GameSystem, Play);
} NrvGameSystem;

}  // namespace
