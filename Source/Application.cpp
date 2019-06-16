
#include "Application.h"


Application::Application(std::string&& name)
{
    pushState<PlayingState>(*this);
}

void Application::run()
{

    while (m_context.isOpen() && !m_states.empty())
    {
        auto deltaTime = m_context.getTime();
        m_context.setTime(0);

        auto& state = *m_states.back();

        state.handleInput();
        state.update(deltaTime);
        m_camera.update();

        state.render(m_masterRenderer);
        m_masterRenderer.finishRender(m_camera);

        m_context.swapBuffers();
        m_context.pollEvents();

        if (m_isPopState)
        {
            m_isPopState = false;
            m_states.pop_back();
        }

    }

}



void Application::popState()
{
    m_isPopState = true;
}
