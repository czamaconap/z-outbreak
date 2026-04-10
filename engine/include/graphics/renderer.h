#pragma once

struct Transform;

namespace Renderer
{
    bool Init();
    void BeginFrame();
    void DrawQuad(const Transform &transform);
    void EndFrame();
    void Cleanup();
}