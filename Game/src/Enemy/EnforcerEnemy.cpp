//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Enemy/EnforcerEnemy.h"
#include "Weapon/ProjectileLauncher.h"

namespace labyrinth_engine
{
    EnforcerEnemy::EnforcerEnemy(World* a_world, const std::string& texturePath, const sf::Vector2f& a_velocity)
        : EnemySpaceship{a_world, texturePath}
        , m_shooter{new ProjectileLauncher{this, 1.0f, {20.0f, 50.0f}, 30.0f}} //front left
        , m_shooter2{new ProjectileLauncher{this, 1.0f, {20.0f, -50.0f}, -30.0f}} //front right
        , m_shooter3{new ProjectileLauncher{this, 1.0f, {50.0f, 0.0}}} //front
        , m_shooter4{new ProjectileLauncher{this, 1.0f, {-50.0f, 0.0}, -180.0f}} //back
        , m_shooter5{new ProjectileLauncher{this, 1.0f, {-20.0f, 50.0f}, 120.0f}} //back left
        , m_shooter6{new ProjectileLauncher{this, 1.0f, {-20.0f, -50.0f}, -120.0f}} //back right
    {
        SetSpaceshipVelocity(a_velocity);
        GetSprite().setScale({3.0f, 3.0f});
    }

    void EnforcerEnemy::ActorTick(float a_deltaTime)
    {
        EnemySpaceship::ActorTick(a_deltaTime);
        Fire();
    }

    void EnforcerEnemy::Fire()
    {
        m_shooter->Fire();
        m_shooter2->Fire();
        m_shooter3->Fire();
        m_shooter4->Fire();
        m_shooter5->Fire();
        m_shooter6->Fire();

        if (GetLastTimeFired() >= m_shooter->GetCooldownTime())
        {
            AudioManager::GetInstance().PlaySFX("Shoot");
            ResetLastTimeFired();
        }
    }
}
