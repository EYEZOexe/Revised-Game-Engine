//
// Created by Tomas Tzorta on 28/12/2023.
//

#ifndef SINNERBOSSGAMESTAGE_H
#define SINNERBOSSGAMESTAGE_H
#include "Gameplay/GameStage.h"

namespace labyrinth_engine
{
    class Actor;

    class SinnerBossGameStage: public GameStage
    {
    public:
        /* Constructors and Destructors */
        SinnerBossGameStage(World* a_world);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions
        void FinalEnemyDestroyed(Actor* a_actor);

        // Boolean Functions

        // Virtual Functions
        void StartStage() override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
    };
}

#endif //SINNERBOSSGAMESTAGE_H
