
#include "Context.h"

#include <iostream>


Context::Context()
{

    if (!glfwInit()){
        // throw error
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    m_window = glfwCreateWindow(1280, 720, "app", NULL, NULL);

    if (!m_window) {
        glfwTerminate();
        // throw error
    }

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(m_window, 0, 0);

    glfwSetKeyCallback(m_window, key_callback);

    glfwSetErrorCallback(error_callback);

    glfwMakeContextCurrent(m_window);

    glfwSwapInterval(1);

    glfwSetTime(0);

    glewInit();

}

Context::~Context() {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Context::error_callback(int error, const char* description)
{
    std::cerr << "Error " << error << " : " << description ;
}
void Context::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

bool Context::isOpen() {
    return !glfwWindowShouldClose(m_window);
}

void Context::swapBuffers() {
    glfwSwapBuffers(m_window);
}

void Context::pollEvents() {
    glfwPollEvents();
}

double Context::getTime() {
    return glfwGetTime();
}

void Context::setTime(double t) {
    glfwSetTime(t);
}

void GLClearError(){
    while(glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line){
    while ( GLenum error = glGetError()){
        std::cerr << "[OpenGL Error] (" << error << ")\n" << function << " -> " << file << " : "  << line << "\n";
        return false;
    }
    return true;
}
