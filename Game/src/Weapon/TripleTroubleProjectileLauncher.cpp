//
// Created by Tomas Tzorta on 18/12/2023.
//

#include "Weapon/TripleTroubleProjectileLauncher.h"

namespace labyrinth_engine
{
    TripleTroubleProjectileLauncher::TripleTroubleProjectileLauncher(Actor* a_owner, float a_cooldown, const sf::Vector2f& a_offset)
        : ProjectileLauncher{a_owner}
        , launcherLeft{a_owner, a_cooldown, a_offset, -30.0f, "ss/Shoot/1.png"}
        , launcherCenter{a_owner, a_cooldown, a_offset, 0.0f, "ss/Shoot/1.png"}
        , launcherRight{a_owner, a_cooldown, a_offset, 30.0f, "ss/Shoot/1.png"}
        , launcherMaxLeft{a_owner, a_cooldown, a_offset, 15.0f, "ss/Shoot/1.png"}
        , launcherMaxRight{a_owner, a_cooldown, a_offset, -15.0f, "ss/Shoot/1.png"}
    {
    }

    void TripleTroubleProjectileLauncher::IncreaseLauncherLevel(int a_increaseAmount)
    {
        //Increase the level of the launcher
        ProjectileLauncher::IncreaseLauncherLevel(a_increaseAmount);
        launcherLeft.IncreaseLauncherLevel(a_increaseAmount);
        launcherCenter.IncreaseLauncherLevel(a_increaseAmount);
        launcherRight.IncreaseLauncherLevel(a_increaseAmount);

        launcherMaxLeft.IncreaseLauncherLevel(a_increaseAmount);
        launcherMaxRight.IncreaseLauncherLevel(a_increaseAmount);
    }

    void TripleTroubleProjectileLauncher::SetLauncherLevel(int a_level)
    {
        ProjectileLauncher::SetLauncherLevel(a_level);

        launcherLeft.SetLauncherLevel(a_level);
        launcherCenter.SetLauncherLevel(a_level);
        launcherRight.SetLauncherLevel(a_level);

        launcherMaxLeft.SetLauncherLevel(a_level);
        launcherMaxRight.SetLauncherLevel(a_level);
    }

    void TripleTroubleProjectileLauncher::OnFire()
    {
        //Fire for all the launchers
        launcherLeft.Fire();
        launcherCenter.Fire();
        launcherRight.Fire();

        //If the launcher is at max level, fire the max level launchers
        if (GetCurrentLauncherLevel() == GetMaxLauncherLevel())
        {
            launcherMaxLeft.Fire();
            launcherMaxRight.Fire();
        }
    }
}
