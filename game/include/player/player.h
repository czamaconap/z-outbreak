#pragma once

#include "math/transform.h"

struct Player
{
    Transform transform;
    float speed = 1.0f;

    void Init();
    void Update();
};