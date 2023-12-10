//
// Created by NAT20 on 09/12/2023.
//

#include "Weapon/ProjectileLauncher.h"
#include "Framework/Core.h"

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
        GE_LOG("Fire!");
    }
}
