#include "game.h"
#include "graphics/renderer.h"

void Game::Init()
{
    player.Init();
}

void Game::Update()
{
    player.Update();
}

void Game::Render()
{
    Renderer::DrawQuad(player.transform);
}