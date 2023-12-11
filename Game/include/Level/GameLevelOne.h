//
// Created by s5216712 on 11/12/2023.
//

#ifndef GAMELEVELONE_H
#define GAMELEVELONE_H

#include "LabyrinthFramework/World.h"

namespace labyrinth_engine
{
    class PlayerSpaceship;
    class GameLevelOne : public World
    {
    public:
        GameLevelOne(Application* a_application);
    private:
        Wptr<PlayerSpaceship> testPlayerSpaceship;
    };
}




#endif //GAMELEVELONE_H
