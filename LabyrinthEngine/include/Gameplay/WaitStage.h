//
// Created by Tomas Tzorta on 16/12/2023.
//

#ifndef WAITSTAGE_H
#define WAITSTAGE_H

#include "Gameplay/GameStage.h"

namespace labyrinth_engine
{
    class WaitStage : public GameStage
    {
    public:
        /* Constructors and Destructors */
        WaitStage(World* a_world, float a_waitDuration = 5.0f);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

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
        float m_waitDuration;
    };
}

#endif //WAITSTAGE_H
