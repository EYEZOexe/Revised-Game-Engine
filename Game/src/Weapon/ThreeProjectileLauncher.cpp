//
// Created by Tomas Tzorta on 18/12/2023.
//

#include "Weapon/ThreeProjectileLauncher.h"

namespace labyrinth_engine
{
    ThreeProjectileLauncher::ThreeProjectileLauncher(Actor* a_owner, float a_cooldown, const sf::Vector2f& a_offset)
        : ProjectileLauncher{a_owner}
        , launcherLeft{a_owner, a_cooldown, a_offset, -30.0f, "PNG/Lasers/laserRed01.png"}
        , launcherCenter{a_owner, a_cooldown, a_offset, 0.0f, "PNG/Lasers/laserRed01.png"}
        , launcherRight{a_owner, a_cooldown, a_offset, 30.0f, "PNG/Lasers/laserRed01.png"}
    {
    }

    void ThreeProjectileLauncher::OnFire()
    {
        launcherLeft.Fire();
        launcherCenter.Fire();
        launcherRight.Fire();
    }
}
