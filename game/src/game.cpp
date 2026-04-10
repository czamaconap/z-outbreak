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

    float thickness = 0.05f;

    // pared izquierda
    Transform leftWall;
    leftWall.position = glm::vec3(room.left - thickness * 0.5f, 0.0f, 0.0f);
    leftWall.scale = glm::vec3(thickness, 1.6f, 1.0f);

    // pared derecha
    Transform rightWall;
    rightWall.position = glm::vec3(room.right + thickness * 0.5f, 0.0f, 0.0f);
    rightWall.scale = glm::vec3(thickness, 1.6f, 1.0f);

    // pared abajo
    Transform bottomWall;
    bottomWall.position = glm::vec3(0.0f, room.bottom - thickness * 0.5f, 0.0f);
    bottomWall.scale = glm::vec3(1.6f, thickness, 1.0f);

    // pared arriba
    Transform topWall;
    topWall.position = glm::vec3(0.0f, room.top + thickness * 0.5f, 0.0f);
    topWall.scale = glm::vec3(1.6f, thickness, 1.0f);

    // Transform roomTransform;
    // roomTransform.position = glm::vec3(0.0f, 0.0f, 0.0f);
    // roomTransform.scale = glm::vec3(1.6f, 1.6f, 1.0f);

    // Renderer::DrawQuad(roomTransform, glm::vec3(0.2f, 0.2f, 0.25f));
    Renderer::DrawQuad(player.transform, glm::vec3(1.0f, 0.3f, 0.2f));

    glm::vec3 wallColor = glm::vec3(0.1f, 0.1f, 0.1f);

    Renderer::DrawQuad(leftWall, wallColor);
    Renderer::DrawQuad(rightWall, wallColor);
    Renderer::DrawQuad(bottomWall, wallColor);
    Renderer::DrawQuad(topWall, wallColor);
}