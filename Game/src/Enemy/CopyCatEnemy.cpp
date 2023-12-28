//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Enemy/CopyCatEnemy.h"

#include "Weapon/ProjectileLauncher.h"

namespace labyrinth_engine
{
    CopyCatEnemy::CopyCatEnemy(World* a_owningWorld, const std::string& a_texturePath, const sf::Vector2f& a_velocity)
        : EnemySpaceship{a_owningWorld, a_texturePath}
        , m_TwinBladeLeftShooter{new ProjectileLauncher{this, 1.0f, {50.0f, -20.0f}}}
        , m_TwinBladeRightShooter{new ProjectileLauncher{this, 1.0f, {50.0f, 20.0f}}}
    {
        SetSpaceshipVelocity(a_velocity);
    }

    void CopyCatEnemy::ActorTick(float a_deltaTime)
    {
        EnemySpaceship::ActorTick(a_deltaTime);
        Fire();
    }

    void CopyCatEnemy::Fire()
    {
        m_TwinBladeLeftShooter->Fire();
        m_TwinBladeRightShooter->Fire();
    }
}
