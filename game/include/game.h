#pragma once

#include "player/player.h"

struct Game
{
    Player player;
    Room room;

    void Init();
    void Update();
    void Render();
};