//
// Created by Tomas Tzorta on 24/12/2023.
//

#ifndef HUD_H
#define HUD_H

#include "LabyrinthFramework/Object.h"
#include "SFML/Graphics.hpp"

namespace labyrinth_engine
{
    class HUD : public Object
    {
    public:
        /* Constructors and Destructors */
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions
        void HUDInitFramework(sf::RenderWindow& a_window); // Function to initialize the HUD

        // Boolean Functions
        bool IsHUDInitialized() {return m_isHUDInitialised;}

        // Virtual Functions
        virtual void DrawHUD(sf::RenderWindow& a_window) = 0; // Pure virtual function to draw the HUD
        virtual bool IsHUDClicked(const sf::Event& a_event); // Pure virtual function to check if the HUD is clicked

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:
        HUD();

    private:
        bool m_isHUDInitialised; // Boolean to check if the HUD is initialized
        virtual void HUDInit(sf::RenderWindow& a_window);
    };
}

#endif //HUD_H
