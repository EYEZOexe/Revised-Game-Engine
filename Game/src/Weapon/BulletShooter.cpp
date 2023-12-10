//
// Created by NAT20 on 09/12/2023.
//

#include "Weapon/BulletShooter.h"
#include "Framework/Core.h"

namespace GameFramework
{
    BulletShooter::BulletShooter(Framework::Actor* a_owner, float a_cooldownTime)
        : ProjectileLauncher{a_owner}
        , m_cooldown{}
        , m_cooldownTime{a_cooldownTime}
    {

    }

    bool BulletShooter::IsOnCooldown() const
    {
        if (m_cooldown.getElapsedTime().asSeconds() > m_cooldownTime) // If the cooldown has passed
        {
            return false;
        }

        return true;
    }

    void BulletShooter::OnFire()
    {
        m_cooldown.restart();
        GE_LOG("Fire!");
    }
}
