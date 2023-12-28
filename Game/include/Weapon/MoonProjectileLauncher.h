//
// Created by Tomas Tzorta on 18/12/2023.
//

#ifndef MOONPROJECTILELAUNCHER_H
#define MOONPROJECTILELAUNCHER_H

#include "Weapon/ProjectileLauncher.h"
#include <SFML/Graphics.hpp>

namespace labyrinth_engine
{
    class MoonProjectileLauncher : public ProjectileLauncher
    {
    public:
        /* Constructors and Destructors */
        MoonProjectileLauncher(Actor* a_owner, float a_cooldown = 0.3, const sf::Vector2f& a_offset = {0.0f, 0.0f}, float a_bulletSpacing = 60.0f);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void IncreaseLauncherLevel(int a_increaseAmount = 1) override; // increase the launcher level

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void OnFire() override;

        float m_width;

        ProjectileLauncher m_projectileLauncher; // projectile launcher
        ProjectileLauncher m_projectileLauncher2;
        ProjectileLauncher m_projectileLauncher3;
        ProjectileLauncher m_projectileLauncher4;

        ProjectileLauncher m_projectileLauncherMax;
        ProjectileLauncher m_projectileLauncherMax2;
    };
}


#endif //MOONPROJECTILELAUNCHER_H
