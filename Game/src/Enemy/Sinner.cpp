//
// Created by Tomas Tzorta on 28/12/2023.
//

#include "Enemy/Sinner.h"
#include "Gameplay/HealthComponent.h"

namespace labyrinth_engine
{
    Sinner::Sinner(World* a_world)
        : EnemySpaceship{a_world, "ss/Ship/7.png"}
        , m_sinnerSpeed{100.0f}
        , m_sinnerStartingSpeed{100.0f}
        , m_sinnerEdgeBoundaries{100.0f}
        , m_projectileLauncherLeft{this, 1.0f, {130.0f, -130.0f}}
        , m_projectileLauncherRight{this, 1.0f, {130.0f, 130.0f}}
        , m_tripleTroubleProjectileLauncher{this, 5.0f, {130.0f, 0.0f}}
        , m_moonProjectileLauncherLeft{this, 6.0f, {130.0f, 130.0f}}
        , m_moonProjectileLauncherRight{this, 6.0f, {130.0f, -130.0f}}
        , m_sinnerState{1}

    {
        GetSprite().setScale({4.0f, 4.0f});
        SetSpaceshipVelocity({m_sinnerSpeed, 0.0f});
        SetEnemyRewardSpawnChance(0);
    }

    void Sinner::ActorBeginPlay()
    {
        EnemySpaceship::ActorBeginPlay();

        HealthComponent& healthComponent = GetHealthComponent();
        healthComponent.SetMaxHealth(1000.0f, 1000.0f);
        healthComponent.OnHealthChange.Bind(GetWeakReference(), &Sinner::SinnerDamaged);
    }

    void Sinner::ActorTick(float a_deltaTime)
    {
        EnemySpaceship::ActorTick(a_deltaTime);
        ShootProjectile();
        ShootMoonProjectile();
        ShootTripleTroubleProjectile();
        SinnerMovement();
    }

    void Sinner::SetSinnerState(int a_state)
    {
        m_sinnerState = a_state;
        m_projectileLauncherLeft.SetLauncherLevel(m_sinnerState);
        m_projectileLauncherRight.SetLauncherLevel(m_sinnerState);
        m_tripleTroubleProjectileLauncher.SetLauncherLevel(m_sinnerState);
        m_moonProjectileLauncherLeft.SetLauncherLevel(m_sinnerState);
        m_moonProjectileLauncherRight.SetLauncherLevel(m_sinnerState);
        m_sinnerSpeed = m_sinnerState * m_sinnerStartingSpeed;
    }

    void Sinner::SinnerMovement()
    {
        if (GetActorLocation().x > GetWindowSize().x - m_sinnerEdgeBoundaries)
        {
            SetSpaceshipVelocity({-m_sinnerSpeed, 0.0f});
        }
        else if (GetActorLocation().x < m_sinnerEdgeBoundaries)
        {
            SetSpaceshipVelocity({m_sinnerSpeed, 0.0f});
        }
    }

    void Sinner::ShootProjectile()
    {
        m_projectileLauncherLeft.Fire();
        m_projectileLauncherRight.Fire();
    }

    void Sinner::ShootMoonProjectile()
    {
        m_moonProjectileLauncherLeft.Fire();
        m_moonProjectileLauncherRight.Fire();
    }

    void Sinner::ShootTripleTroubleProjectile()
    {
        m_tripleTroubleProjectileLauncher.Fire();
    }

    void Sinner::SinnerDamaged(float a_damage, float a_currentHealth, float a_maxHealth)
    {
        float healthPercentage = a_currentHealth / a_maxHealth;
        if (healthPercentage < 0.7 && healthPercentage > 0.5)
        {
            SetSinnerState(2);
        }
        if (healthPercentage < 0.5 && healthPercentage > 0.3)
        {
            SetSinnerState(3);
        }
        if (healthPercentage < 0.3 && healthPercentage > 0.1)
        {
            SetSinnerState(4);
        }
    }

}
