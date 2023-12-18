//
// Created by Tomas Tzorta on 18/12/2023.
//

#ifndef THREEPROJECTILELAUNCHER_H
#define THREEPROJECTILELAUNCHER_H

#include <SFML/Graphics.hpp>
#include "Weapon/ProjectileLauncher.h"

namespace labyrinth_engine
{
    class ThreeProjectileLauncher : public ProjectileLauncher
    {
    public:
        /* Constructors and Destructors */
        ThreeProjectileLauncher(Actor* a_actor, float a_cooldown = 0.3, const sf::Vector2f& a_offset = {0.0f, 0.0f});
        /* End of Constructors and Destructors */

        /* Class Functions */
        ProjectileLauncher launcherLeft;
        ProjectileLauncher launcherCenter;
        ProjectileLauncher launcherRight;

        // Void Functions

        // Boolean Functions

        // Virtual Functions

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


#endif //THREEPROJECTILELAUNCHER_H
