//
// Created by Tomas Tzorta on 16/12/2023.
//

#ifndef TWINBLADE_H
#define TWINBLADE_H

#include "Enemy/EnemySpaceship.h"

namespace labyrinth_engine
{
    class ProjectileLauncher;
    class TwinBlade : public EnemySpaceship
    {
    public:
        /* Constructors and Destructors */
        TwinBlade(World* a_owningWorld, const std::string& a_texturePath = "PNG/Enemies/enemyBlack1.png", const sf::Vector2f& a_velocity = {0.0f, 120.0f});
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void ActorTick(float a_deltaTime) override;
        void Fire() override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        Unique<ProjectileLauncher> m_TwinBladeLeftShooter;
        Unique<ProjectileLauncher> m_TwinBladeRightShooter;
    };
}



#endif //TWINBLADE_H
