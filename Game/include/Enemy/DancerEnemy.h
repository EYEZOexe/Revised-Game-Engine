//
// Created by Tomas Tzorta on 16/12/2023.
//

#ifndef UFO_H
#define UFO_H

#include "EnemySpaceship.h"


namespace labyrinth_engine
{
    class ProjectileLauncher;
    class DancerEnemy : public EnemySpaceship
    {
    public:
        /* Constructors and Destructors */
        DancerEnemy(World* a_world, const sf::Vector2f& a_velocity, const std::string& a_texturePath = "PNG/UFO.png", float a_rotationSpeed = 40.0f);
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

        Unique<ProjectileLauncher> m_UFOLeftShooter;
        Unique<ProjectileLauncher> m_UFORightShooter;
        Unique<ProjectileLauncher> m_UFOMiddleShooter;
        float m_RotationSpeed;
    };
}

#endif //UFO_H
