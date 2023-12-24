//
// Created by Tomas Tzorta on 24/12/2023.
//

#ifndef GAMEHUD_H
#define GAMEHUD_H

#include "UI/HUD.h"
#include "UI/TextWidget.h"

namespace labyrinth_engine
{
    class GameHUD : public HUD
    {
    public:
        /* Constructors and Destructors */
        GameHUD();
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void DrawHUD(sf::RenderWindow& a_window) override;
        void UpdateHUD(float a_deltaTime) override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        TextWidget m_gameFramerateText;
    };
}

#endif //GAMEHUD_H
