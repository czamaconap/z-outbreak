#include "core/gl_system.h"
#include "graphics/renderer.h"
#include "input/input.h"
#include <GLFW/glfw3.h>

int main()
{
    if (!GLSystem::Init(800, 600, "Outbreak"))
    {
        return -1;
    }

    if (!Renderer::Init())
    {
        GLSystem::Cleanup();
        return -1;
    }

    while (!GLSystem::WindowShouldClose())
    {
        GLSystem::PollEvents();
        Input::Update(GLSystem::GetWindow());

        if (Input::KeyPressed(GLFW_KEY_ESCAPE))
        {
            GLSystem::SetWindowShouldClose(true);
        }

        Renderer::BeginFrame();
        Renderer::EndFrame();

        GLSystem::SwapBuffers();
    }

    Renderer::Cleanup();
    GLSystem::Cleanup();
    return 0;
}