#pragma once

struct Transform;

namespace Renderer
{
    bool Init();
    void BeginFrame();
    void DrawTriangle(const Transform &transform);
    void EndFrame();
    void Cleanup();
}