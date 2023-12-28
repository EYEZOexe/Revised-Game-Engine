//
// Created by s5216712 on 11/12/2023.
//

#include "Enemy/RookieEnemy.h"

#include "Weapon/ProjectileLauncher.h"

namespace labyrinth_engine
{
    RookieEnemy::RookieEnemy(World* a_owningWorld, const std::string& a_texturePath, const sf::Vector2f& a_velocity)
        : EnemySpaceship(a_owningWorld, a_texturePath)
        , m_projectileLauncher{new ProjectileLauncher{this, 1.0f, {50.0f, 0.0f}}}
    {
        SetSpaceshipVelocity(a_velocity);
    }

    void RookieEnemy::ActorTick(float a_deltaTime)
    {
        EnemySpaceship::ActorTick(a_deltaTime);
        Fire();

    }

    void RookieEnemy::Fire()
    {
        EnemySpaceship::Fire();
        m_projectileLauncher->Fire();
    }
}
