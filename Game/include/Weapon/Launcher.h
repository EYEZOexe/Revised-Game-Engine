//
// Created by Tomas Tzorta on 09/12/2023.
//

#ifndef WEAPON_H
#define WEAPON_H

#include "LabyrinthFramework/Actor.h"

namespace labyrinth_engine
{
    class Actor;

    class Launcher
    {
    public:
        void Fire();

        virtual bool CanFire() const {return true;}
        virtual bool IsOnCooldown() const {return false;}

        Actor* GetOwner() const {return m_owner;}
        int GetCurrentLauncherLevel() const {return m_currentLauncherLevel;}
        int GetMaxLauncherLevel() const {return m_maxLauncherLevel;}

        virtual void IncreaseLauncherLevel(int a_increaseAmount = 1);

    protected:
        Launcher(Actor* a_owner);

    private:
        virtual void OnFire() = 0;
        Actor* m_owner;

        int m_currentLauncherLevel;
        int m_maxLauncherLevel;
    };
}

#endif //WEAPON_H
