//
// Created by s5216712 on 11/12/2023.
//

#include "Enemy/Vanguard.h"

#include "Weapon/ProjectileLauncher.h"

namespace labyrinth_engine
{
    Vanguard::Vanguard(World* a_owningWorld, const std::string& a_texturePath, const sf::Vector2f& a_velocity)
        : EnemySpaceship(a_owningWorld, a_texturePath)
        , m_projectileLauncher{new ProjectileLauncher(this)}
    {
       SetSpaceshipVelocity(a_velocity);
    }

    void Vanguard::ActorTick(float a_deltaTime)
    {
        EnemySpaceship::ActorTick(a_deltaTime);
        Fire();
    }

    void Vanguard::Fire()
    {
        m_projectileLauncher->Fire();
    }
}
