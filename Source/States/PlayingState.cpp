
#include "PlayingState.h"

#include "../Renderer/RenderMaster.h"
#include "../Application.h"

PlayingState::PlayingState(Application& app)
        :   StateBase   (app)
{
    app.getCamera().hookEntity(m_player);
}

void PlayingState::handleEvent()
{

}

void PlayingState::handleInput()
{
    m_player.handleInput(&(m_pApplication->getWindow()));
}

void PlayingState::update(float deltaTime)
{
    m_player.update(deltaTime);
}

void PlayingState::render(RenderMaster& renderer)
{
    renderer.drawQuad({0, 0, 0});
}
