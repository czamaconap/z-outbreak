#pragma once
#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace GLSystem
{
    bool Init(int width, int height, const std::string &title);
    void PollEvents();
    void SwapBuffers();
    bool WindowShouldClose();
    void SetWindowShouldClose(bool value);
    GLFWwindow *GetWindow();
    void Cleanup();
}