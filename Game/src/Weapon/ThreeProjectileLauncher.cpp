//
// Created by Tomas Tzorta on 18/12/2023.
//

#include "Weapon/ThreeProjectileLauncher.h"

namespace labyrinth_engine
{
    ThreeProjectileLauncher::ThreeProjectileLauncher(Actor* a_actor, float a_cooldown, const sf::Vector2f& a_offset)
        : ProjectileLauncher{a_actor}
        , launcherLeft{a_actor, a_cooldown, a_offset, -30.0f, "PNG/Lasers/laserRed01.png"}
        , launcherCenter{a_actor, a_cooldown, a_offset, 0.0f, "PNG/Lasers/laserRed01.png"}
        , launcherRight{a_actor, a_cooldown, a_offset, 30.0f, "PNG/Lasers/laserRed01.png"}
    {
    }

    void ThreeProjectileLauncher::OnFire()
    {
        launcherLeft.Fire();
        launcherCenter.Fire();
        launcherRight.Fire();
    }
}
