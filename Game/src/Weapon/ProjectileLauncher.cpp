//
// Created by Tomas Tzorta on 09/12/2023.
//

#include "Weapon/ProjectileLauncher.h"
#include "LabyrinthFramework/Core.h"
#include "Weapon/Projectile.h"
#include "LabyrinthFramework/World.h"

namespace labyrinth_engine
{
    ProjectileLauncher::ProjectileLauncher(Actor* a_owner, float a_cooldownTime, const sf::Vector2f& a_selfPositionOffset, float a_selfRotationOffset)
        : Launcher{a_owner}
        , m_cooldown{}
        , m_cooldownTime{a_cooldownTime}
        , m_selfPositionOffset{a_selfPositionOffset}
        , m_selfRotationOffset{a_selfRotationOffset}
    {

    }

    bool ProjectileLauncher::IsOnCooldown() const
    {
        if (m_cooldown.getElapsedTime().asSeconds() > m_cooldownTime) // If the cooldown has passed
        {
            return false;
        }

        return true;
    }

    void ProjectileLauncher::OnFire()
    {
        sf::Vector2f ownerForwardVector = GetOwner()->GetActorForwardVector();
        sf::Vector2f ownerRightVector = GetOwner()->GetActorRightVector();

        m_cooldown.restart();
        Weak<Projectile> newProjectile = GetOwner()->GetWorld()->SpawnActor<Projectile>(GetOwner(), "PNG/Lasers/laserBlue01.png");
        newProjectile.lock()->SetActorLocation(GetOwner()->GetActorLocation() + ownerForwardVector * m_selfPositionOffset.x + ownerRightVector * m_selfPositionOffset.y);
        newProjectile.lock()->SetActorRotation(GetOwner()->GetActorRotation() + m_selfRotationOffset);

    }
}
