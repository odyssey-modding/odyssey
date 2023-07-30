#pragma once

#include <al/Library/Yaml/Writer/ByamlWriter.h>
#include <al/Library/HostIO/HioNode.h>

class ByamlSave : public al::HioNode {
public:
    virtual void write(al::ByamlWriter*) = 0;
    virtual void read(const al::ByamlIter&) = 0;
};
