//
// Created by Tomas Tzorta on 09/12/2023.
//

#include "Weapon/ProjectileLauncher.h"
#include "LabyrinthFramework/Core.h"
#include "Weapon/Projectile.h"
#include "LabyrinthFramework/World.h"

namespace labyrinth_engine
{
    ProjectileLauncher::ProjectileLauncher(Actor* a_owner, float a_cooldownTime, const sf::Vector2f& a_selfPositionOffset, float a_selfRotationOffset, const std::string& a_projectileTexturePath)
        : Launcher{a_owner}
        , m_cooldown{}
        , m_cooldownTime{a_cooldownTime}
        , m_selfPositionOffset{a_selfPositionOffset}
        , m_selfRotationOffset{a_selfRotationOffset}
        , m_projectileTexturePath{a_projectileTexturePath}
    {

    }

    bool ProjectileLauncher::IsOnCooldown() const
    {
        if (m_cooldown.getElapsedTime().asSeconds() > m_cooldownTime / GetCurrentLauncherLevel()) // If the cooldown has passed
        {
            return false;
        }

        return true;
    }

    void ProjectileLauncher::IncreaseLauncherLevel(int a_increaseAmount) // Increases the launcher level by the amount specified
    {
        Launcher::IncreaseLauncherLevel(a_increaseAmount); // Increase the launcher level
    }

    void ProjectileLauncher::OnFire() // Fires the projectile
    {
        sf::Vector2f ownerForwardVector = GetOwner()->GetActorForwardVector(); // Get the owner forward vector
        sf::Vector2f ownerRightVector = GetOwner()->GetActorRightVector(); // Get the owner right vector

        m_cooldown.restart();
        Weak<Projectile> newProjectile = GetOwner()->GetWorld()->SpawnActor<Projectile>(GetOwner(), m_projectileTexturePath); // Spawn the projectile
        newProjectile.lock()->SetActorLocation(GetOwner()->GetActorLocation() + ownerForwardVector * m_selfPositionOffset.x + ownerRightVector * m_selfPositionOffset.y); // Set the projectile location
        newProjectile.lock()->SetActorRotation(GetOwner()->GetActorRotation() + m_selfRotationOffset); // Set the projectile rotation
    }
}
