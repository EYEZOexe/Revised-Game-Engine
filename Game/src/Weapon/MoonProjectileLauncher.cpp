//
// Created by Tomas Tzorta on 18/12/2023.
//

#include "Weapon/MoonProjectileLauncher.h"

namespace labyrinth_engine
{
    MoonProjectileLauncher::MoonProjectileLauncher(Actor* a_owner, float a_cooldown, const sf::Vector2f& a_offset, float a_bulletSpacing)
        : ProjectileLauncher{a_owner}
        , m_width{a_bulletSpacing}
        , m_projectileLauncher{a_owner, a_cooldown, {a_offset.x, a_offset.y - a_bulletSpacing / 2.0f}, 0.0f, "ss/Shoot/9.png"}
        , m_projectileLauncher2{a_owner, a_cooldown, {a_offset.x, a_offset.y - a_bulletSpacing / 6.0f}, 0.0f, "ss/Shoot/9.png"}
        , m_projectileLauncher3{a_owner, a_cooldown, {a_offset.x, a_offset.y + a_bulletSpacing / 6.0f}, 0.0f, "ss/Shoot/9.png"}
        , m_projectileLauncher4{a_owner, a_cooldown, {a_offset.x, a_offset.y + a_bulletSpacing / 2.0f}, 0.0f, "ss/Shoot/9.png"}
        , m_projectileLauncherMax{a_owner, a_cooldown, {a_offset.x, a_offset.y - a_bulletSpacing / 1.5f}, -15.0f, "ss/Shoot/9.png"}
        , m_projectileLauncherMax2{a_owner, a_cooldown, {a_offset.x, a_offset.y + a_bulletSpacing / 1.5f}, 15.0f, "ss/Shoot/9.png"}
    {

    }

    void MoonProjectileLauncher::IncreaseLauncherLevel(int a_increaseAmount)
    {
        ProjectileLauncher::IncreaseLauncherLevel(a_increaseAmount); // call the base class function
        m_projectileLauncher.IncreaseLauncherLevel(a_increaseAmount);
        m_projectileLauncher2.IncreaseLauncherLevel(a_increaseAmount);
        m_projectileLauncher3.IncreaseLauncherLevel(a_increaseAmount);
        m_projectileLauncher4.IncreaseLauncherLevel(a_increaseAmount);
        m_projectileLauncherMax.IncreaseLauncherLevel(a_increaseAmount);
        m_projectileLauncherMax2.IncreaseLauncherLevel(a_increaseAmount);
    }

    void MoonProjectileLauncher::SetLauncherLevel(int a_level)
    {
        ProjectileLauncher::SetLauncherLevel(a_level);

        m_projectileLauncher.SetLauncherLevel(a_level);
        m_projectileLauncher2.SetLauncherLevel(a_level);
        m_projectileLauncher3.SetLauncherLevel(a_level);
        m_projectileLauncher4.SetLauncherLevel(a_level);
        m_projectileLauncherMax.SetLauncherLevel(a_level);
        m_projectileLauncherMax2.SetLauncherLevel(a_level);
    }

    void MoonProjectileLauncher::OnFire()
    {
        m_projectileLauncher.Fire(); // fire the projectile
        m_projectileLauncher2.Fire();
        m_projectileLauncher3.Fire();
        m_projectileLauncher4.Fire();

        if (GetCurrentLauncherLevel() == GetMaxLauncherLevel())
        {
            m_projectileLauncherMax.Fire(); // fire the projectile
            m_projectileLauncherMax2.Fire();
        }
    }
}
