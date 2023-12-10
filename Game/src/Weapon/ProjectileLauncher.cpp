//
// Created by Tomas Tzorta on 09/12/2023.
//

#include "Weapon/ProjectileLauncher.h"
#include "LabyrinthEngine/Core.h"
#include "Weapon/Projectile.h"
#include "LabyrinthEngine/World.h"

namespace labyrinth_engine
{
    ProjectileLauncher::ProjectileLauncher(Actor* a_owner, float a_cooldownTime)
        : Launcher{a_owner}
        , m_cooldown{}
        , m_cooldownTime{a_cooldownTime}
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
        m_cooldown.restart();
        Wptr<Projectile> newProjectile = GetOwner()->GetWorld()->SpawnActor<Projectile>(GetOwner(), "PNG/Lasers/laserBlue01.png");
        newProjectile.lock()->SetActorLocation(GetOwner()->GetActorLocation());
        newProjectile.lock()->SetActorRotation(GetOwner()->GetActorRotation());

    }
}
