#pragma once

#include <heap/seadHeap.h>

namespace al {
class LayoutSystem {
    LayoutSystem();
    void init();
    void initGraphicsResource();
    void initFont();
    void initEui();
    void* tryFindFont(const char* fontName);
    void* getFontNamePair(int);
    void prepareInitFontForChange();
    void reinitFont(sead::Heap*);
    void beginDraw();
    void endDraw();
};
}  // namespace al