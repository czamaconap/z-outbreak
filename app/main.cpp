#include "core/gl_system.h"
#include "core/time.h"
#include "graphics/renderer.h"
#include "input/input.h"
#include "game.h"
#include <GLFW/glfw3.h>

int main()
{
    if (!GLSystem::Init(800, 600, "Z-Outbreak"))
    {
        return -1;
    }

    if (!Renderer::Init())
    {
        GLSystem::Cleanup();
        return -1;
    }

    Game game;
    game.Init();

    while (!GLSystem::WindowShouldClose())
    {
        GLSystem::PollEvents();
        Time::Update();
        Input::Update(GLSystem::GetWindow());

        if (Input::KeyPressed(GLFW_KEY_ESCAPE))
        {
            GLSystem::SetWindowShouldClose(true);
        }

        game.Update();

        Renderer::BeginFrame();
        game.Render();
        Renderer::EndFrame();

        GLSystem::SwapBuffers();
    }

    Renderer::Cleanup();
    GLSystem::Cleanup();
    return 0;
}