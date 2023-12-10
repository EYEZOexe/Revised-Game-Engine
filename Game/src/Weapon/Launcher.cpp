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

    Launcher::Launcher(Actor* a_owner)
        : m_owner(a_owner)
    {

    }
}
