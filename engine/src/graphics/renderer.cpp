#include "graphics/renderer.h"
#include "graphics/shader.h"
#include "math/transform.h"
#include <glad/glad.h>
#include <iostream>

namespace Renderer
{
    static unsigned int g_VAO = 0;
    static unsigned int g_VBO = 0;
    static Shader g_shader;
    static Transform g_triangleTransform;

    bool Init()
    {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f};

        glGenVertexArrays(1, &g_VAO);
        glGenBuffers(1, &g_VBO);

        glBindVertexArray(g_VAO);

        glBindBuffer(GL_ARRAY_BUFFER, g_VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        if (!g_shader.Load("triangle.vert", "triangle.frag"))
        {
            std::cout << "Error: no se pudo cargar el shader\n";
            return false;
        }

        g_triangleTransform.scale = glm::vec3(0.4f, 0.4f, 1.0f);

        return true;
    }

    void BeginFrame()
    {
        glClearColor(0.05f, 0.05f, 0.08f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        g_shader.Use();
        g_shader.SetMat4("model", g_triangleTransform.ToMat4());

        glBindVertexArray(g_VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void EndFrame()
    {
    }

    void Cleanup()
    {
        if (g_VBO != 0)
        {
            glDeleteBuffers(1, &g_VBO);
            g_VBO = 0;
        }

        if (g_VAO != 0)
        {
            glDeleteVertexArrays(1, &g_VAO);
            g_VAO = 0;
        }
    }
}