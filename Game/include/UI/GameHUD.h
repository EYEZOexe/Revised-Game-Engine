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

        // Void Functions


        // Boolean Functions

        // Virtual Functions
        void DrawHUD(sf::RenderWindow& a_window) override;
        void UpdateHUD(float a_deltaTime) override;
        bool IsHUDClicked(const sf::Event& a_event) override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void PlayerStatsUpdate();

        void HUDInit(const sf::RenderWindow& a_window) override;
        void PlayerHealthUpdate(float a_amount, float a_currentHealth, float a_maxHealth);
        void PlayerLifeUpdate(int a_amount);
        void PlayerScoreUpdate(int a_amount);
        void PlayerDeath(Actor* a_actor);
        void PlayerHUDReset();

        TextWidget m_gameFramerateText;
        StatusMeter m_playerHealthBar;
        ImageWidget m_playerLifeIcon;
        TextWidget m_playerLifeText;

        ImageWidget m_playerScoreIcon;
        TextWidget m_playerScoreText;

        ButtonWidget m_testButton;
        void TestButtonPressed();

        sf::Color m_playerMaxHealthColour;
        sf::Color m_playerDamageHealthColour;
        float m_playerDamagedHealthThreshold;

        float m_imageWidgetSpacing;
    };
}

#endif //GAMEHUD_H
