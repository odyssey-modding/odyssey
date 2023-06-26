#pragma once

#include <al/Library/LiveActor/LiveActor.h>
#include <al/Library/Nerve/NerveSetupUtil.h>

class AnagramAlphabetCharacter;

class AnagramAlphabet : public al::LiveActor {
    public:
    AnagramAlphabet(char const*);
    void init(al::ActorInitInfo const&);
    bool testBase(AnagramAlphabetCharacter *);
    bool testEndHack();
    bool testComplete();

    void exeWait();
    void exeComplete();
    void appearShine();
};