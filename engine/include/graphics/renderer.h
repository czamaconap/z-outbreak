#pragma once

#include <glm/vec3.hpp>

struct Transform;

namespace Renderer
{
    bool Init();
    void BeginFrame();
    void DrawQuad(const Transform &transform, const glm::vec3 &color);
    void EndFrame();
    void Cleanup();
}