//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "UI/GameHUD.h"
#include "Player/PlayerManager.h"
#include "Player/Player.h"
#include "Player/PlayerSpaceship.h"
#include "LabyrinthFramework/Actor.h"

namespace labyrinth_engine
{
    GameHUD::GameHUD()
        : m_gameFramerateText{"Frame Rate: "}
        , m_playerHealthBar{}
        , m_playerMaxHealthColour{sf::Color::Green}
        , m_playerDamageHealthColour{sf::Color::Red}
        , m_playerDamagedHealthThreshold{0.3f}
        , m_playerLifeIcon{"ss/HUD/LifeIcon.png"}
        , m_playerLifeText{""}
        , m_playerScoreIcon{"ss/Item/Gem3.png"}
        , m_playerScoreText{""}
        , m_imageWidgetSpacing{10.0f}
    {
        m_gameFramerateText.SetWidgetTextSize(20);
        m_playerLifeText.SetWidgetTextSize(20);
        m_playerScoreText.SetWidgetTextSize(20);
    }

    void GameHUD::HUDInit(const sf::RenderWindow& a_window)
    {
        auto windowSize = a_window.getSize(); // get the size of the window
        m_playerHealthBar.SetWidgetPosition(sf::Vector2f{20.0f, windowSize.y - 50.0f}); // set the position of the health bar

        sf::Vector2f widgetPosition = m_playerHealthBar.GetWidgetPosition();

        widgetPosition += {m_playerHealthBar.GetWidgetBounds().width + m_imageWidgetSpacing, 0}; // add the width of the health bar and the spacing between the health bar and the life icon
        m_playerLifeIcon.SetWidgetPosition(widgetPosition); // set the position of the life icon

        widgetPosition += {m_playerLifeIcon.GetWidgetBounds().width + m_imageWidgetSpacing, 0}; // add the width of the life icon and the spacing between the life icon and the life text
        m_playerLifeText.SetWidgetPosition(widgetPosition); // set the position of the life text

        widgetPosition += {m_playerLifeText.GetWidgetBounds().width + m_imageWidgetSpacing * 4, 2}; // add the width of the life text and the spacing between the life text and the score icon
        m_playerScoreIcon.SetWidgetPosition(widgetPosition); // set the position of the score icon

        widgetPosition += {m_playerScoreIcon.GetWidgetBounds().width + m_imageWidgetSpacing, -2}; // add the width of the score icon and the spacing between the score icon and the score text
        m_playerScoreText.SetWidgetPosition(widgetPosition); // set the position of the score text

        PlayerHUDReset(); // reset the player HUD
        PlayerStatsUpdate(); // update the player stats
    }

    void GameHUD::DrawHUD(sf::RenderWindow& a_window)
    {
        m_gameFramerateText.FrameworkWidgetDraw(a_window); // draw the framerate text
        m_playerHealthBar.FrameworkWidgetDraw(a_window); // draw the health bar
        m_playerLifeIcon.FrameworkWidgetDraw(a_window); // draw the life icon
        m_playerLifeText.FrameworkWidgetDraw(a_window); // draw the life text
        m_playerScoreIcon.FrameworkWidgetDraw(a_window); // draw the score icon
        m_playerScoreText.FrameworkWidgetDraw(a_window); // draw the score text
    }

    void GameHUD::UpdateHUD(float a_deltaTime)
    {
        int frameRate = int(1 / a_deltaTime); // calculate the frame rate
        std::string frameRateString = "Frame Rate: " + std::to_string(frameRate); // convert the frame rate to a string
        m_gameFramerateText.SetWidgetText(frameRateString); // set the text of the frame rate text
    }

    void GameHUD::PlayerStatsUpdate()
    {
        Player* player = PlayerManager::GetInstance().GetPlayer(); // get the player

        if (player) // if the player exists
        {
            int playerLives = player->GetPlayerLives(); // get the player lives
            m_playerLifeText.SetWidgetText(std::to_string(playerLives)); // set the text of the player lives
            player->OnPlayerLifeChange.Bind(GetWeakReference(), &GameHUD::PlayerLifeUpdate); // bind the player life update function to the player life change event

            int playerScore = player->GetPlayerScore(); // get the player score
            m_playerScoreText.SetWidgetText(std::to_string(playerScore)); // set the text of the player score
            player->OnPlayerScoreChange.Bind(GetWeakReference(), &GameHUD::PlayerScoreUpdate); // bind the player score update function to the player score change event
        }
    }

    void GameHUD::PlayerHealthUpdate(float a_amount, float a_currentHealth, float a_maxHealth)
    {
        m_playerHealthBar.UpdateStatus(a_currentHealth, a_maxHealth); // update the health bar

        if (a_currentHealth/a_maxHealth < m_playerDamagedHealthThreshold)  // if the current health is less than the damaged health threshold
        {
            m_playerHealthBar.SetFrontWidgetColour(m_playerDamageHealthColour); // set the front widget colour to the damage health colour
        }
        else
        {
            m_playerHealthBar.SetFrontWidgetColour(m_playerMaxHealthColour); // set the front widget colour to the max health colour
        }
    }

    void GameHUD::PlayerLifeUpdate(int a_amount)
    {
        m_playerLifeText.SetWidgetText(std::to_string(a_amount)); // set the text of the player lives
    }

    void GameHUD::PlayerScoreUpdate(int a_amount)
    {
        m_playerScoreText.SetWidgetText(std::to_string(a_amount)); // set the text of the player score
    }

    void GameHUD::PlayerHUDReset()
    {
        Player* player = PlayerManager::GetInstance().GetPlayer();

        if (player && !player->GetPlayerSpaceship().expired()) // if the player exists and the player spaceship is not expired
        {
            Weak<PlayerSpaceship> playerSpaceship = player->GetPlayerSpaceship(); // get the player spaceship
            playerSpaceship.lock()->OnActorDestroy.Bind(GetWeakReference(), &GameHUD::PlayerDeath); // bind the player death function to the player spaceship destroy event
            HealthComponent& healthComponent = player->GetPlayerSpaceship().lock()->GetHealthComponent(); // get the health component of the player spaceship
            healthComponent.OnHealthChange.Bind(GetWeakReference(), &GameHUD::PlayerHealthUpdate); // bind the player health update function to the player spaceship health change event
            PlayerHealthUpdate(0, healthComponent.GetHealth(), healthComponent.GetMaxHealth()); // update the player health
        }
    }

    void GameHUD::PlayerDeath(Actor* a_actor)
    {
        PlayerHUDReset(); // reset the player HUD
    }
}
