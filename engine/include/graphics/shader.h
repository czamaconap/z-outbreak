#pragma once
#include <string>
#include <glm/glm.hpp>

struct Shader
{
    unsigned int ID = 0;

    bool Load(const std::string &vertexPath, const std::string &fragmentPath);
    void Use() const;
    void SetMat4(const std::string &name, const glm::mat4 &value) const;
    void SetVec3(const std::string &name, const glm::vec3 &value);
};