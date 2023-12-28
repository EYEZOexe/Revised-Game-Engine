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

        int GetCurrentLauncherLevel() const {return m_currentLauncherLevel;} // getter for the current launcher level
        int GetMaxLauncherLevel() const {return m_maxLauncherLevel;} // getter for the max launcher level

        Actor* GetOwner() const {return m_owner;} // getter for the owner of the launcher
        virtual void IncreaseLauncherLevel(int a_increaseAmount = 1); // virtual function that will be used to increase the launcher level

        virtual bool CanFire() const {return true;} // virtual function that will be used to check if the launcher can fire
        virtual bool IsOnCooldown() const {return false;} // virtual function that will be used to check if the launcher is on cooldown


    protected:
        Launcher(Actor* a_owner); // constructor for the launcher

    private:
        virtual void OnFire() = 0; // virtual function that will be used when the launcher fires
        Actor* m_owner; // pointer to the owner of the launcher

        int m_currentLauncherLevel; // current launcher level
        int m_maxLauncherLevel; // max launcher level
    };
}

#endif //WEAPON_H
