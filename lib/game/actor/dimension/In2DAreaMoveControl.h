#pragma once

#include <container/seadPtrArray.h>

namespace al {
class AreaObj;
}

class In2DAreaMoveControl {
public:
    In2DAreaMoveControl();
private:
    sead::FixedPtrArray<al::AreaObj, 8> mSnapAreaObjs;
    sead::FixedPtrArray<al::AreaObj, 8> mSnapPushOutAreaObjs;
};