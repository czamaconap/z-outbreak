#include "player/player.h"
#include "input/input.h"
#include "core/time.h"
#include <GLFW/glfw3.h>

void Player::Init()
{
    transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
    transform.scale = glm::vec3(0.25f, 0.35f, 1.0f);
}

void Player::Update(const Room &room)
{
    float dt = Time::GetDeltaTime();

    if (Input::KeyDown(GLFW_KEY_A))
        transform.position.x -= speed * dt;

    if (Input::KeyDown(GLFW_KEY_D))
        transform.position.x += speed * dt;

    if (Input::KeyDown(GLFW_KEY_W))
        transform.position.y += speed * dt;

    if (Input::KeyDown(GLFW_KEY_S))
        transform.position.y -= speed * dt;

    float halfWidth = transform.scale.x * 0.5f;
    float halfHeight = transform.scale.y * 0.5f;

    // Clamp horizontal
    if (transform.position.x - halfWidth < room.left)
        transform.position.x = room.left + halfWidth;

    if (transform.position.x + halfWidth > room.right)
        transform.position.x = room.right - halfWidth;

    // Clamp vertical
    if (transform.position.y - halfHeight < room.bottom)
        transform.position.y = room.bottom + halfHeight;

    if (transform.position.y + halfHeight > room.top)
        transform.position.y = room.top - halfHeight;
}