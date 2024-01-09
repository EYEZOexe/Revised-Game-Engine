//
// Created by Tomas Tzorta on 24/12/2023.
//

#ifndef GAMEHUD_H
#define GAMEHUD_H

#include "UI/HUD.h"
#include "UI/TextWidget.h"
#include "UI/StatusMeter.h"
#include "UI/ImageWidget.h"
#include "UI/ButtonWidget.h"

namespace labyrinth_engine
{
    class Actor;
    class GameHUD : public HUD
    {
    public:
        /* Constructors and Destructors */
        GameHUD();
        /* End of Constructors and Destructors */

        /* Class Functions */
        EventCallback<> OnRestartButtonPressed; // restart button pressed event
        EventCallback<> OnQuitButtonPressed; // quit button pressed event

        // Void Functions
        void GameStageComplete(bool a_gameEnd); // game over

        // Boolean Functions

        // Virtual Functions
        void DrawHUD(sf::RenderWindow& a_window) override; // draw the HUD
        void UpdateHUD(float a_deltaTime) override; // update the HUD

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void PlayerStatsUpdate(); // update the player stats

        void HUDInit(const sf::RenderWindow& a_window) override; // initialise the HUD
        bool IsHUDClicked(const sf::Event& a_event) override; // check if the HUD is clicked
        void PlayerHealthUpdate(float a_amount, float a_currentHealth, float a_maxHealth); // update the player health
        void PlayerLifeUpdate(int a_amount); // update the player life
        void PlayerScoreUpdate(int a_amount); // update the player score
        void PlayerDeath(Actor* a_actor); // player death
        void PlayerHUDReset(); // reset the player HUD
        void RestartButtonPressed(); // player restart button pressed
        void QuitButtonPressed(); // player quit button pressed

        float m_playerDamagedHealthThreshold;
        float m_imageWidgetSpacing;

        TextWidget m_gameFramerateText;
        TextWidget m_playerLifeText;
        TextWidget m_playerScoreText;
        TextWidget m_playerGameStateText;
        TextWidget m_playerFinalScoreText;
        ButtonWidget m_playerRestartButton;
        ButtonWidget m_playerQuitButton;

        StatusMeter m_playerHealthBar;

        ImageWidget m_playerLifeIcon;
        ImageWidget m_playerScoreIcon;

        sf::Color m_playerMaxHealthColour;
        sf::Color m_playerDamageHealthColour;
        sf::Vector2u m_windowSize;
    };
}

#endif //GAMEHUD_H
