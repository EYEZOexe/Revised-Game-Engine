//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Enemy/CopyCatEnemy.h"

#include "Weapon/ProjectileLauncher.h"

namespace labyrinth_engine
{
    CopyCatEnemy::CopyCatEnemy(World* a_owningWorld, const std::string& a_texturePath, const sf::Vector2f& a_velocity)
        : EnemySpaceship{a_owningWorld, a_texturePath}
        , m_CopyCatLeftShooter{new ProjectileLauncher{this, 1.0f, {50.0f, -20.0f}}}
        , m_CopyCatRightShooter{new ProjectileLauncher{this, 1.0f, {50.0f, 20.0f}}}
    {
        SetSpaceshipVelocity(a_velocity);
        GetSprite().setScale({3.0f, 3.0f});
    }

    void CopyCatEnemy::ActorTick(float a_deltaTime)
    {
        EnemySpaceship::ActorTick(a_deltaTime);
        Fire();
    }

    void CopyCatEnemy::Fire()
    {
        m_CopyCatLeftShooter->Fire();
        m_CopyCatRightShooter->Fire();

        if (GetLastTimeFired() >= m_CopyCatLeftShooter->GetCooldownTime())
        {
            AudioManager::GetInstance().PlaySFX("Shoot");
            ResetLastTimeFired();
        }
    }
}
