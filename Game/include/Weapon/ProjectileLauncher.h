//
// Created by NAT20 on 09/12/2023.
//

#ifndef WEAPON_H
#define WEAPON_H

#include "Framework/Actor.h"

namespace GameFramework
{
    class Framework::Actor;

    class ProjectileLauncher
    {
    public:
        void Fire();

        virtual bool CanFire() const {return true;}
        virtual bool IsOnCooldown() const {return false;}

        Framework::Actor* GetOwner() const {return m_owner;}

    protected:
        ProjectileLauncher(Framework::Actor* a_owner);

    private:
        virtual void OnFire() = 0;
        Framework::Actor* m_owner;
    };
}

#endif //WEAPON_H
