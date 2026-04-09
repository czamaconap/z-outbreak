#include "input/input.h"
#include <GLFW/glfw3.h>

namespace Input
{
    static bool g_keyDown[512] = {false};
    static bool g_keyDownLastFrame[512] = {false};
    static bool g_keyPressed[512] = {false};

    void Update(GLFWwindow *window)
    {
        for (int i = 0; i < 512; i++)
        {
            g_keyDown[i] = (glfwGetKey(window, i) == GLFW_PRESS);
            g_keyPressed[i] = (g_keyDown[i] && !g_keyDownLastFrame[i]);
            g_keyDownLastFrame[i] = g_keyDown[i];
        }
    }

    bool KeyDown(unsigned int key)
    {
        return g_keyDown[key];
    }

    bool KeyPressed(unsigned int key)
    {
        return g_keyPressed[key];
    }
}