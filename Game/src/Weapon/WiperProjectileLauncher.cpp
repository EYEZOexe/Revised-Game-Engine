//
// Created by Tomas Tzorta on 18/12/2023.
//

#include "Weapon/WiperProjectileLauncher.h"

namespace labyrinth_engine
{
    WiperProjectileLauncher::WiperProjectileLauncher(Actor* a_owner, float a_cooldown, const sf::Vector2f& a_offset, float a_bulletSpacing)
        : ProjectileLauncher{a_owner}
        , m_width{a_bulletSpacing}
        , m_projectileLauncher{a_owner, a_cooldown, {a_offset.x, a_offset.y - a_bulletSpacing / 2.0f}, 0.0f, "PNG/Lasers/laserGreen11.png"}
        , m_projectileLauncher2{a_owner, a_cooldown, {a_offset.x, a_offset.y - a_bulletSpacing / 6.0f}, 0.0f, "PNG/Lasers/laserBlue07.png"}
        , m_projectileLauncher3{a_owner, a_cooldown, {a_offset.x, a_offset.y + a_bulletSpacing / 6.0f}, 0.0f, "PNG/Lasers/laserBlue07.png"}
        , m_projectileLauncher4{a_owner, a_cooldown, {a_offset.x, a_offset.y + a_bulletSpacing / 2.0f}, 0.0f, "PNG/Lasers/laserGreen11.png"}
    {

    }

    void WiperProjectileLauncher::OnFire()
    {
        m_projectileLauncher.Fire();
        m_projectileLauncher2.Fire();
        m_projectileLauncher3.Fire();
        m_projectileLauncher4.Fire();
    }
}
