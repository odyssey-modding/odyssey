#include "al/Library/Area/AreaObj.h"
#include "math/seadVectorFwd.h"

class RouteGuideArea : public al::AreaObj {
private:
    sead::Vector3f mGuidePos = {0.0, 0.0, 0.0};
    bool mIsGuide3D = false;

public:
    RouteGuideArea(const char* name);

    void init(const al::AreaInitInfo& areaInitInfo) override;
    void calcGuidePos(sead::Vector3f* guidePos) const;
};