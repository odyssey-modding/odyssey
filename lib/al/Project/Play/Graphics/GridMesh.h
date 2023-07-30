#pragma once

#include <al/Library/HostIO/HioNode.h>
#include <basis/seadTypes.h>
#include <common/aglDrawContext.h>

namespace agl {
class IndexStream;
}
namespace al {
class QuadNode;
class MeshQuadtree;
class IUseGridMesh : al::IUseHioNode {
    virtual void finalize() = 0;
    virtual s32 getGridMeshType() const = 0;
    virtual s32 getGridNum() const = 0;
    virtual s32 getLodNum() const = 0;
    virtual void calcMeshScaleLod(const al::QuadNode& node, s32) const = 0;
    virtual agl::IndexStream* getIndexStream() const = 0;
    virtual const char* getName() const = 0;
    virtual void activateVertexAttribute(agl::DrawContext* drawContext, s32) const = 0;
    virtual void drawTreeMesh(agl::DrawContext*, const al::MeshQuadtree&, const al::QuadNode&, float, int) = 0;
    virtual void drawArrayMesh(agl::DrawContext* drawContext, const al::QuadNode& node, int, int, int, int, int) = 0;
};
}  // namespace al
