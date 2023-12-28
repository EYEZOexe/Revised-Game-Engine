//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Enemy/DancerEnemy.h"
#include "Weapon/ProjectileLauncher.h"

namespace labyrinth_engine
{
    DancerEnemy::DancerEnemy(World* a_world, const sf::Vector2f& a_velocity, const std::string& a_texturePath, float a_rotationSpeed)
        : EnemySpaceship{a_world, a_texturePath}
        , m_RotationSpeed{a_rotationSpeed}
        , m_UFOLeftShooter{new ProjectileLauncher{this, 0.5f, {0.0f, 0.0f}, -60.0f}}
        , m_UFORightShooter{new ProjectileLauncher{this, 0.5f, {0.0f, 0.0f}, 60.0f}}
        , m_UFOMiddleShooter{new ProjectileLauncher{this, 0.5f, {0.0f, 0.0f}, 180.0f}}
    {
        SetSpaceshipVelocity(a_velocity);
    }

    void DancerEnemy::ActorTick(float a_deltaTime)
    {
        EnemySpaceship::ActorTick(a_deltaTime);
        Fire();
        AddActorRotationOffset(m_RotationSpeed * a_deltaTime);
    }

    void DancerEnemy::Fire()
    {
        m_UFOLeftShooter->Fire();
        m_UFORightShooter->Fire();
        m_UFOMiddleShooter->Fire();
    }
}
