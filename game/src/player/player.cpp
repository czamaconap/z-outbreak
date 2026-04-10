#include "player/player.h"
#include "input/input.h"
#include "core/time.h"
#include <GLFW/glfw3.h>

void Player::Init()
{
    transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
    transform.scale = glm::vec3(0.25f, 0.35f, 1.0f);
}

void Player::Update()
{
    float dt = Time::GetDeltaTime();

    if (Input::KeyDown(GLFW_KEY_A))
    {
        transform.position.x -= speed * dt;
    }

    if (Input::KeyDown(GLFW_KEY_D))
    {
        transform.position.x += speed * dt;
    }

    if (Input::KeyDown(GLFW_KEY_W))
    {
        transform.position.y += speed * dt;
    }

    if (Input::KeyDown(GLFW_KEY_S))
    {
        transform.position.y -= speed * dt;
    }
}