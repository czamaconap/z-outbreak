#pragma once

#include "player/player.h"

struct Game
{
    Player player;

    void Init();
    void Update();
    void Render();
};