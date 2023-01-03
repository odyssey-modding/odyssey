#pragma once

namespace al {
class ByamlIter;

class InOutParam {
private:
    f32 mInMin;
    f32 mInMax;
    f32 mOutMin;
    f32 mOutMax;
public:
    InOutParam();
    InOutParam(const al::InOutParam& src);
    InOutParam(f32 inMin, f32 inMax, f32 outMin, f32 outMax);
    void init(const al::ByamlIter& iter);
    f32 calcLeapValue(f32 value);
    f32 calcEaseInValue(f32 value);
    f32 calcEaseOutValue(f32 value);
    f32 calcEaseInOutValue(f32 value);
    f32 calcSqrtValue(f32 value);
    f32 calcSquareValue(f32 value);
};
}
