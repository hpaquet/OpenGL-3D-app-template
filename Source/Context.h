
#ifndef WAVEINTERFERENCE_CONTEXT_H
#define WAVEINTERFERENCE_CONTEXT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define ASSERT(x) if (!(x)) __builtin_trap();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

class Context
{
public:
    Context();
    ~Context();

    bool isOpen();
    void swapBuffers();
    void pollEvents();

    double getTime();
    void setTime(double t);

    GLFWwindow* m_window;
private:

    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

};

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);



#endif //WAVEINTERFERENCE_CONTEXT_H
