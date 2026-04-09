#pragma once

struct GLFWwindow;

namespace Input
{
    void Update(GLFWwindow *window);
    bool KeyDown(unsigned int key);
    bool KeyPressed(unsigned int key);
}