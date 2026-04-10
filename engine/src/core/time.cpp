#include "core/time.h"
#include <GLFW/glfw3.h>

namespace Time
{
    static float g_deltaTime = 0.0f;
    static float g_lastTime = 0.0f;

    void Update()
    {
        float currentTime = static_cast<float>(glfwGetTime());
        g_deltaTime = currentTime - g_lastTime;
        g_lastTime = currentTime;
    }

    float GetDeltaTime()
    {
        return g_deltaTime;
    }
}