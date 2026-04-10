#pragma once

#include "math/transform.h"
#include "world/room.h"

struct Player
{
    Transform transform;
    float speed = 1.0f;

    void Init();
    void Update(const Room &room);
};