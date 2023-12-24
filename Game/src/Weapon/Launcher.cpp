//
// Created by Tomas Tzorta on 09/12/2023.
//

#include "Weapon/Launcher.h"


namespace labyrinth_engine
{
    void Launcher::Fire()
    {
        if(CanFire() && !IsOnCooldown())
        {
            OnFire();
        }
    }

    void Launcher::IncreaseLauncherLevel(int a_increaseAmount)
    {
        if (m_currentLauncherLevel == m_maxLauncherLevel) return;

        ++m_currentLauncherLevel;
    }

    Launcher::Launcher(Actor* a_owner)
        : m_owner{a_owner}
        , m_currentLauncherLevel{1}
        , m_maxLauncherLevel{4}
    {

    }
}
