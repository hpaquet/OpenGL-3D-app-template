
#ifndef WAVEINTERFERENCE_STATEBASE_H
#define WAVEINTERFERENCE_STATEBASE_H

#include "../Context.h"

class RenderMaster;
class Application;

class StateBase
{
public:
    StateBase(Application& app)
            :   m_pApplication  (&app)
    { }

    virtual ~StateBase() noexcept = default;

    virtual void handleEvent() = 0;
    virtual void handleInput() = 0;

    virtual void update(float deltaTime) = 0;

    virtual void render(RenderMaster& renderer) = 0;

protected:
    Application* m_pApplication;

};


#endif //WAVEINTERFERENCE_STATEBASE_H
