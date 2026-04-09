#pragma once
#include <string>

struct Shader
{
    unsigned int ID = 0;

    bool Load(const std::string &vertexPath, const std::string &fragmentPath);
    void Use() const;
};