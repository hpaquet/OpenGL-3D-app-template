
#ifndef WAVEINTERFERENCE_PLAYER_H
#define WAVEINTERFERENCE_PLAYER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Util/Entity.h"

class Player : public Entity
{
public:
    Player();

    void handleInput(GLFWwindow* window);

    void update(float dt);

private:
    void keyboardInput(GLFWwindow* window);
    void mouseInput(GLFWwindow* window);

    glm::vec3 m_velocity;
};


#endif //WAVEINTERFERENCE_PLAYER_H
