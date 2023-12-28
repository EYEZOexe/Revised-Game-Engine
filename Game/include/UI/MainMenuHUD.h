//
// Created by Tomas Tzorta on 28/12/2023.
//

#ifndef MAINMENUHUD_H
#define MAINMENUHUD_H

#include "UI/HUD.h"
#include "UI/ButtonWidget.h"
#include "UI/TextWidget.h"

namespace labyrinth_engine
{
    class MainMenuHUD : public HUD
    {
    public:
        /* Constructors and Destructors */
        MainMenuHUD();
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void DrawHUD(sf::RenderWindow& a_window) override; // draw HUD
        bool IsHUDClicked(const sf::Event& a_event) override; // check if HUD is clicked
        EventCallback<> OnPlayButtonPressed; // play button pressed event
        EventCallback<> OnQuitButtonPressed; // quit button pressed event
        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void HUDInit(const sf::RenderWindow& a_window) override; // initialize HUD
        void PlayButtonPressed(); // play button pressed
        void QuitButtonPressed(); // quit button pressed
        TextWidget m_mainMenuTitleText; // main menu text
        ButtonWidget m_mainMenuPlayButton; // main menu play button
        ButtonWidget m_mainMenuQuitButton; // main menu quit button
    };
}

#endif //MAINMENUHUD_H
