//
// Created by Tomas Tzorta on 09/12/2023.
//

#include "Weapon/Launcher.h"

#include "LabyrinthFramework/AudioManager.h"


namespace labyrinth_engine
{
    Launcher::Launcher(Actor* a_owner)
        : m_owner{a_owner} // set the owner of the launcher
          , m_currentLauncherLevel{1} // set the current launcher level to 1
          , m_maxLauncherLevel{4} // set the max launcher level to 4
    {

    }

    void Launcher::Fire()
    {
        if(CanFire() && !IsOnCooldown()) // if the launcher can fire and is not on cooldown
        {
            OnFire(); // call the on fire function

        }
    }

    void Launcher::IncreaseLauncherLevel(int a_increaseAmount)
    {
        if (m_currentLauncherLevel == m_maxLauncherLevel)
        {
            return; // if the current launcher level is equal to the max launcher level return
        }

        ++m_currentLauncherLevel; // increase the current launcher level
    }

    void Launcher::SetLauncherLevel(int a_level)
    {
        m_currentLauncherLevel = a_level; // set the current launcher level to the level specified
    }
}
