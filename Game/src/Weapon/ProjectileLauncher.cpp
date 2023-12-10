//
// Created by NAT20 on 09/12/2023.
//

#include "Weapon/ProjectileLauncher.h"



namespace GameFramework
{
    void ProjectileLauncher::Fire()
    {
        if(CanFire() && !IsOnCooldown())
        {
            OnFire();
        }
    }

    ProjectileLauncher::ProjectileLauncher(Framework::Actor* a_owner)
        : m_owner(a_owner)
    {

    }
}
