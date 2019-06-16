
#include "Player.h"

#include <GLFW/glfw3.h>
#include <iostream>

Player::Player()
{
    position = {0, 0, -5};
}

void Player::handleInput(GLFWwindow* window)
{
    keyboardInput(window);
    mouseInput(window);
}

void Player::update(float dt)
{
    position += m_velocity * dt;
    m_velocity *= 0.95;
}

void Player::keyboardInput(GLFWwindow* window)
{
    glm::vec3 change;
    float speed = 0.5;

    if (glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS)
    {
        change.x = glm::cos(glm::radians(rotation.y + 90)) * speed;
        change.z = glm::sin(glm::radians(rotation.y + 90)) * speed;
    }
    if (glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS)
    {
        change.x = -glm::cos(glm::radians(rotation.y + 90)) * speed;
        change.z = -glm::sin(glm::radians(rotation.y + 90)) * speed;
    }
    if (glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS)
    {
        change.x = glm::cos(glm::radians(rotation.y)) * speed;
        change.z = glm::sin(glm::radians(rotation.y)) * speed;
    }
    if (glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS)
    {
        change.x = -glm::cos(glm::radians(rotation.y)) * speed;
        change.z = -glm::sin(glm::radians(rotation.y)) * speed;
    }

    m_velocity += change;
}

void Player::mouseInput(GLFWwindow* window)
{
    double xchange, ychange;

    static auto const BOUND = 80;

    glfwGetCursorPos(window, &xchange, &ychange);

    rotation.x += ychange * 0.05;
    rotation.y += xchange * 0.05;

    if      (rotation.x >  BOUND) rotation.x =  BOUND;
    else if (rotation.x < -BOUND) rotation.x = -BOUND;

    if      (rotation.y >  360) rotation.y = 0;
    else if (rotation.y < 0)    rotation.y = 360;


    glfwSetCursorPos(window,0,0);

}
