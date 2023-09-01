#pragma once

class In2DAreaMoveControl;

namespace al {
    class LiveActor;
}

class ActorDimensionKeeper {
    const al::LiveActor* mLiveActor;
    bool isValid = true;
    bool is2D = false;
    bool isIn2DArea = false;
    bool isCurrently2D = false;
    bool isCanChange2D = false;
    bool isCanChange3D = false;
    In2DAreaMoveControl* mIn2DAreaMoveControl = nullptr;

public:
    ActorDimensionKeeper(const al::LiveActor* actor);
    void validate();
    void invalidate();
    void forceChange2DKeep();
    void forceEndChange2DKeep();
    bool update();

    bool getIs2D() const { return is2D; }
    bool getIsIn2DArea() const { return isIn2DArea; }
    bool getIsCurrently2D() const { return isCurrently2D; }
    bool getIsCanChange2D() const { return isCanChange2D; }
    bool getIsCanChange3D() const { return isCanChange3D; }
};

class IUseDimension {
public:
    virtual ActorDimensionKeeper* getActorDimensionKeeper() const = 0;
};