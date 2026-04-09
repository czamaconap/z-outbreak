#pragma once

#include "math/transform.h"

struct Player
{
    Transform transform;
    float speed = 0.01f;

    void Init();
    void Update();
};