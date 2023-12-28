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
        ProjectileLauncher::IncreaseLauncherLevel(a_increaseAmount);
        launcherLeft.IncreaseLauncherLevel(a_increaseAmount);
        launcherCenter.IncreaseLauncherLevel(a_increaseAmount);
        launcherRight.IncreaseLauncherLevel(a_increaseAmount);

        launcherMaxLeft.IncreaseLauncherLevel(a_increaseAmount);
        launcherMaxRight.IncreaseLauncherLevel(a_increaseAmount);
    }

    void TripleTroubleProjectileLauncher::OnFire()
    {
        launcherLeft.Fire();
        launcherCenter.Fire();
        launcherRight.Fire();

        if (GetCurrentLauncherLevel() == GetMaxLauncherLevel())
        {
            launcherMaxLeft.Fire();
            launcherMaxRight.Fire();
        }
    }
}
