
#ifndef WAVEINTERFERENCE_PLAYINGSTATE_H
#define WAVEINTERFERENCE_PLAYINGSTATE_H

#include "StateBase.h"
#include "../Player/Player.h"

class PlayingState : public StateBase
{
public:
    PlayingState(Application& app);

    void handleEvent();
    void handleInput();

    void update(float deltaTime);

    void render(RenderMaster& renderer);

private:
    Player m_player;
};


#endif //WAVEINTERFERENCE_PLAYINGSTATE_H
