#include <glad/glad.h>
#include "core/gl_system.h"
#include <iostream>

namespace GLSystem
{
    static GLFWwindow *g_window = nullptr;

    static void FramebufferSizeCallback(GLFWwindow *window, int width, int height)
    {
        (void)window;
        glViewport(0, 0, width, height);
    }

    bool Init(int width, int height, const std::string &title)
    {
        if (!glfwInit())
        {
            std::cout << "Error: no se pudo inicializar GLFW\n";
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        g_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!g_window)
        {
            std::cout << "Error: no se pudo crear la ventana\n";
            glfwTerminate();
            return false;
        }

        glfwMakeContextCurrent(g_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Error: no se pudo inicializar GLAD\n";
            glfwDestroyWindow(g_window);
            g_window = nullptr;
            glfwTerminate();
            return false;
        }

        int framebufferWidth = 0;
        int framebufferHeight = 0;
        glfwGetFramebufferSize(g_window, &framebufferWidth, &framebufferHeight);
        glViewport(0, 0, framebufferWidth, framebufferHeight);

        glfwSetFramebufferSizeCallback(g_window, FramebufferSizeCallback);
        return true;
    }

    void PollEvents()
    {
        glfwPollEvents();
    }

    void SwapBuffers()
    {
        glfwSwapBuffers(g_window);
    }

    bool WindowShouldClose()
    {
        return glfwWindowShouldClose(g_window);
    }

    void SetWindowShouldClose(bool value)
    {
        glfwSetWindowShouldClose(g_window, value);
    }

    GLFWwindow *GetWindow()
    {
        return g_window;
    }

    void Cleanup()
    {
        if (g_window != nullptr)
        {
            glfwDestroyWindow(g_window);
            g_window = nullptr;
        }
        glfwTerminate();
    }
}