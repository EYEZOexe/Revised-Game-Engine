//
// Created by Tomas Tzorta on 18/12/2023.
//

#ifndef TRIPLETROUBLEPROJECTILELAUNCHER_H
#define TRIPLETROUBLEPROJECTILELAUNCHER_H

#include <SFML/Graphics.hpp>
#include "Weapon/ProjectileLauncher.h"

namespace labyrinth_engine
{
    class TripleTroubleProjectileLauncher : public ProjectileLauncher
    {
    public:
        /* Constructors and Destructors */
        TripleTroubleProjectileLauncher(Actor* a_owner, float a_cooldown = 0.3, const sf::Vector2f& a_offset = {0.0f, 0.0f});
        /* End of Constructors and Destructors */

        /* Class Functions */
        ProjectileLauncher launcherLeft;
        ProjectileLauncher launcherCenter;
        ProjectileLauncher launcherRight;

        ProjectileLauncher launcherMaxLeft;
        ProjectileLauncher launcherMaxRight;

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void IncreaseLauncherLevel(int a_increaseAmount = 1) override;
        void SetLauncherLevel(int a_level) override;

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
    };
}


#endif //TRIPLETROUBLEPROJECTILELAUNCHER_H
