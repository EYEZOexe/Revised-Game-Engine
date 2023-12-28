//
// Created by Tomas Tzorta on 16/12/2023.
//

#ifndef HEXAGON_H
#define HEXAGON_H

#include "Enemy/EnemySpaceship.h"

namespace labyrinth_engine
{
    class ProjectileLauncher;

    class EnforcerEnemy : public EnemySpaceship
    {
    public:
        /* Constructors and Destructors */
        EnforcerEnemy(World* a_world, const std::string& texturePath = "PNG/Enemies/enemyGreen4.png", const sf::Vector2f& a_velocity = {0.0f, 100.0f});
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
        void Fire() override;

        Unique<ProjectileLauncher> m_shooter;
        Unique<ProjectileLauncher> m_shooter2;
        Unique<ProjectileLauncher> m_shooter3;
        Unique<ProjectileLauncher> m_shooter4;
        Unique<ProjectileLauncher> m_shooter5;
        Unique<ProjectileLauncher> m_shooter6;
    };
}

#endif //HEXAGON_H
