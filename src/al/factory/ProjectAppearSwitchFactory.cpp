#include "al/factory/ProjectAppearSwitchFactory.h"
#include <array>

namespace al {

typedef LiveActor* (*createActor)(const char* name);

// FIXME fill in method references: (1.0) off_7101D89F18
    static al::NameToCreator<al::createActor> sProjectAppearSwitchFactoryEntries[] = {{"FixMapParts", nullptr},
                                                            {"FallMapParts", nullptr},
                                                            {"CapHanger", nullptr},
                                                            {"Coin", nullptr},
                                                            {"CoinCollect", nullptr},
                                                            {"FixMapPartsCapHanger", nullptr},
                                                            {"FloaterMapParts", nullptr},
                                                            {"KeyMoveMapParts", nullptr},
                                                            {"MeganeMapParts", nullptr},
                                                            {"PoleGrabCeil", nullptr},
                                                            {"RailDrawer", nullptr},
                                                            {"ReactionObject", nullptr},
                                                            {"RotateMapParts", nullptr},
                                                            {"SeesawMapParts", nullptr},
                                                            {"Tank", nullptr},
                                                            {"TreasureBox", nullptr},
                                                            {"TreasureBoxKey", nullptr},
                                                            {"WaveSurfMapParts", nullptr},
                                                            {"WobbleMapParts", nullptr}};

ProjectAppearSwitchFactory::ProjectAppearSwitchFactory() : ActorFactory("アクター生成") {
    initFactory(sProjectAppearSwitchFactoryEntries);
}

}  // namespace al