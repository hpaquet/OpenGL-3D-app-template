
#ifndef WAVEINTERFERENCE_APPLICATION_H
#define WAVEINTERFERENCE_APPLICATION_H

#include <vector>
#include <memory>


#include "Context.h"

#include "Renderer/RenderMaster.h"
#include "States/PlayingState.h"
#include "Camera.h"


class Application
{
public:

    Application(std::string&& name);

    void run();

    template<typename T, typename... Args>
    void pushState(Args&&... args)
    {
        m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        auto& s = m_states.back();
    }

    void popState();

    Camera& getCamera() { return m_camera; }

    GLFWwindow& getWindow() const { return *m_context.m_window ; }

private:

    std::vector<std::unique_ptr<StateBase>> m_states;

    Context m_context;
    RenderMaster m_masterRenderer;
    Camera m_camera;


    bool m_isPopState = false;
};


#endif //WAVEINTERFERENCE_APPLICATION_H
