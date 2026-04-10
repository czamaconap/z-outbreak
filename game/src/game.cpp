#include "game.h"
#include "graphics/renderer.h"

void Game::Init()
{
    player.Init();
}

void Game::Update()
{
    player.Update(room);
}

void Game::Render()
{
    Transform roomTransform;
    roomTransform.position = glm::vec3(0.0f, 0.0f, 0.0f);
    roomTransform.scale = glm::vec3(1.6f, 1.6f, 1.0f);

    Renderer::DrawQuad(roomTransform, glm::vec3(0.2f, 0.2f, 0.25f));
    Renderer::DrawQuad(player.transform, glm::vec3(1.0f, 0.3f, 0.2f));
}