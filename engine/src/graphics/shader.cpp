#include "graphics/shader.h"
#include <glad/glad.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <glm/gtc/type_ptr.hpp>

static std::string ReadFile(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cout << "Error: no se pudo abrir el archivo " << path << "\n";
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

static bool CheckShaderCompile(unsigned int shader, const char *label)
{
    int success = 0;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "Error compilando shader (" << label << "):\n"
                  << infoLog << "\n";
        return false;
    }
    return true;
}

static bool CheckProgramLink(unsigned int program)
{
    int success = 0;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cout << "Error linkeando program:\n"
                  << infoLog << "\n";
        return false;
    }
    return true;
}

bool Shader::Load(const std::string &vertexPath, const std::string &fragmentPath)
{
    std::string vertexCode = ReadFile("res/shaders/" + vertexPath);
    std::string fragmentCode = ReadFile("res/shaders/" + fragmentPath);

    if (vertexCode.empty() || fragmentCode.empty())
    {
        return false;
    }

    const char *vSource = vertexCode.c_str();
    const char *fSource = fragmentCode.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vSource, nullptr);
    glCompileShader(vertexShader);
    if (!CheckShaderCompile(vertexShader, "vertex"))
    {
        glDeleteShader(vertexShader);
        return false;
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fSource, nullptr);
    glCompileShader(fragmentShader);
    if (!CheckShaderCompile(fragmentShader, "fragment"))
    {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return false;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return CheckProgramLink(ID);
}

void Shader::Use() const
{
    glUseProgram(ID);
}

void Shader::SetMat4(const std::string &name, const glm::mat4 &value) const
{
    int location = glGetUniformLocation(ID, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}