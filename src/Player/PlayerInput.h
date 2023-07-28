#pragma once

#include <math/seadVectorFwd.h>

class PlayerInput {

public:
    bool isSpinClockwise() const;
    void calcMoveInput(sead::Vector3f*, const sead::Vector3f&) const;
};
