//
// Created by Tomas Tzorta on 28/12/2023.
//

#ifndef SINNER_H
#define SINNER_H

#include "EnemySpaceship.h"
#include "Weapon/ProjectileLauncher.h"
#include "Weapon/MoonProjectileLauncher.h"
#include "Weapon/TripleTroubleProjectileLauncher.h"

namespace labyrinth_engine
{
    class Sinner : public EnemySpaceship
    {
    public:
        /* Constructors and Destructors */
        Sinner(World* a_world);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void ActorBeginPlay() override;
        void ActorTick(float a_deltaTime) override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        int m_sinnerState; // progression for boss stages
        void SetSinnerState(int a_state); // set the state of the sinner

        float m_sinnerStartingSpeed; // starting speed of the sinner
        float m_sinnerSpeed; // speed of the sinner
        float m_sinnerEdgeBoundaries; // boundaries for the sinner

        void SinnerMovement(); // movement of the sinner

        void ShootProjectile(); // shooting of the sinner
        ProjectileLauncher m_projectileLauncherLeft;
        ProjectileLauncher m_projectileLauncherRight;

        void ShootMoonProjectile(); // shooting of the sinner
        MoonProjectileLauncher m_moonProjectileLauncherLeft;
        MoonProjectileLauncher m_moonProjectileLauncherRight;

        void ShootTripleTroubleProjectile(); // shooting of the sinner
        TripleTroubleProjectileLauncher m_tripleTroubleProjectileLauncher;

        void SinnerDamaged(float a_damage, float a_currentHealth, float a_maxHealth); // when the sinner is damaged

    };
}

#endif //SINNER_H
