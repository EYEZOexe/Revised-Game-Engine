//
// Created by s5216712 on 11/12/2023.
//

#ifndef GAMELEVELONE_H
#define GAMELEVELONE_H

#include "LabyrinthFramework/World.h"
#include "LabyrinthFramework/TimeManager.h"

namespace labyrinth_engine
{
    class PlayerSpaceship;
    class GameLevelOne : public World
    {
    public:
        GameLevelOne(Application* a_application);
    private:
        void BeginPlay() override;
        void InitialiseGameStages() override;
        void PlayerSpaceshipDestroyed(Actor* a_actor);
        void GameOver();
        Weak<PlayerSpaceship> m_playerSpaceship;
        TimerHandler m_timerHandler;
    };
}




#endif //GAMELEVELONE_H
