//
// Created by Tomas Tzorta on 28/12/2023.
//

#ifndef SINNER_H
#define SINNER_H

#include "EnemySpaceship.h"

namespace labyrinth_engine
{
    class Sinner : public EnemySpaceship
    {
    public:
        /* Constructors and Destructors */
        Sinner(World* a_world);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void ActorTick(float a_deltaTime) override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        float m_sinnerSpeed;
        float m_sinnerEdgeBoundaries;
    };
}

#endif //SINNER_H
