#pragma once

#include <prim/seadSafeString.h>
namespace al {
class SceneMsg {
private:
    void* field_00;
    sead::FixedSafeString<128> field_08;
    sead::FixedSafeString<128> field_a0;

public:
    SceneMsg();
    void clear();
    void setMsg(const char*, const char*);
};
}  // namespace al
