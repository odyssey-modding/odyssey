#pragma once

#include <prim/seadSafeString.h>

namespace al {
class PlacementInfo;

class PlacementId {
private:
    const char* mId;
    const char* mUnitConfigName;
    const char* mZoneId;
    const char* mCommonID;

public:
    static bool isEqual(const al::PlacementId&, const al::PlacementId&);

    PlacementId();
    PlacementId(const char*, const char*, const char*);

    void init(const al::PlacementInfo&);
    bool isEqual(const al::PlacementId&) const;
    bool isValid() const;
    void makeString(sead::BufferedSafeString*) const;
};
}  // namespace al
