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
        , m_playerLifeIcon{"PNG/Power-ups/powerupRed_shield.png"}
        , m_playerLifeText{""}
        , m_playerScoreIcon{"PNG/Power-ups/star_gold.png"}
        , m_playerScoreText{""}
        , m_imageWidgetSpacing{10.0f}
        , m_testButton{}
    {
        m_gameFramerateText.SetWidgetTextSize(20);
        m_playerLifeText.SetWidgetTextSize(20);
        m_playerScoreText.SetWidgetTextSize(20);
    }

    void GameHUD::HUDInit(const sf::RenderWindow& a_window)
    {
        auto windowSize = a_window.getSize();
        m_playerHealthBar.SetWidgetPosition(sf::Vector2f{20.0f, windowSize.y - 50.0f});

        sf::Vector2f widgetPosition = m_playerHealthBar.GetWidgetPosition();

        widgetPosition += {m_playerHealthBar.GetWidgetBounds().width + m_imageWidgetSpacing, 0};
        m_playerLifeIcon.SetWidgetPosition(widgetPosition);

        widgetPosition += {m_playerLifeIcon.GetWidgetBounds().width + m_imageWidgetSpacing, 0};
        m_playerLifeText.SetWidgetPosition(widgetPosition);

        widgetPosition += {m_playerLifeText.GetWidgetBounds().width + m_imageWidgetSpacing * 4, -2.0f};
        m_playerScoreIcon.SetWidgetPosition(widgetPosition);

        widgetPosition += {m_playerScoreIcon.GetWidgetBounds().width + m_imageWidgetSpacing, 2};
        m_playerScoreText.SetWidgetPosition(widgetPosition);

        m_testButton.SetWidgetPosition({windowSize.x / 2.0f, windowSize.y / 2.0f});
        m_testButton.SetButtonTextSize(20);
        m_testButton.OnButtonPressed.Bind(GetWeakReference(), &GameHUD::TestButtonPressed);


        PlayerHUDReset();
        PlayerStatsUpdate();
    }

    void GameHUD::PlayerHealthUpdate(float a_amount, float a_currentHealth, float a_maxHealth)
    {
        m_playerHealthBar.UpdateStatus(a_currentHealth, a_maxHealth);

        if (a_currentHealth/a_maxHealth < m_playerDamagedHealthThreshold)
        {
            m_playerHealthBar.SetFrontWidgetColour(m_playerDamageHealthColour);
        }
        else
        {
            m_playerHealthBar.SetFrontWidgetColour(m_playerMaxHealthColour);
        }
    }

    void GameHUD::PlayerLifeUpdate(int a_amount)
    {
        m_playerLifeText.SetWidgetText(std::to_string(a_amount));
    }

    void GameHUD::PlayerScoreUpdate(int a_amount)
    {
        m_playerScoreText.SetWidgetText(std::to_string(a_amount));
    }

    void GameHUD::PlayerHUDReset()
    {
        Player* player = PlayerManager::GetInstance().GetPlayer();

        if (player && !player->GetPlayerSpaceship().expired())
        {
            Weak<PlayerSpaceship> playerSpaceship = player->GetPlayerSpaceship();
            playerSpaceship.lock()->OnActorDestroy.Bind(GetWeakReference(), &GameHUD::PlayerDeath);
            HealthComponent& healthComponent = player->GetPlayerSpaceship().lock()->GetHealthComponent();
            healthComponent.OnHealthChange.Bind(GetWeakReference(), &GameHUD::PlayerHealthUpdate);
            PlayerHealthUpdate(0, healthComponent.GetHealth(), healthComponent.GetMaxHealth());
        }
    }

    void GameHUD::TestButtonPressed()
    {
        LE_LOG("BUTTON PRESSED YEET");
    }

    void GameHUD::PlayerDeath(Actor* a_actor)
    {
        PlayerHUDReset();
    }

    void GameHUD::DrawHUD(sf::RenderWindow& a_window)
    {
        m_gameFramerateText.FrameworkWidgetDraw(a_window);
        m_playerHealthBar.FrameworkWidgetDraw(a_window);
        m_playerLifeIcon.FrameworkWidgetDraw(a_window);
        m_playerLifeText.FrameworkWidgetDraw(a_window);
        m_playerScoreIcon.FrameworkWidgetDraw(a_window);
        m_playerScoreText.FrameworkWidgetDraw(a_window);
        m_testButton.FrameworkWidgetDraw(a_window);
    }

    void GameHUD::UpdateHUD(float a_deltaTime)
    {
        int frameRate = int(1 / a_deltaTime);
        std::string frameRateString = "Frame Rate: " + std::to_string(frameRate);
        m_gameFramerateText.SetWidgetText(frameRateString);
    }

    bool GameHUD::IsHUDClicked(const sf::Event& a_event)
    {
        return m_testButton.IsMouseOver(a_event) || HUD::IsHUDClicked(a_event);
    }

    void GameHUD::PlayerStatsUpdate()
    {
        Player* player = PlayerManager::GetInstance().GetPlayer();

        if (player)
        {
            int playerLives = player->GetPlayerLives();
            m_playerLifeText.SetWidgetText(std::to_string(playerLives));
            player->OnPlayerLifeChange.Bind(GetWeakReference(), &GameHUD::PlayerLifeUpdate);

            int playerScore = player->GetPlayerScore();
            m_playerScoreText.SetWidgetText(std::to_string(playerScore));
            player->OnPlayerScoreChange.Bind(GetWeakReference(), &GameHUD::PlayerScoreUpdate);
        }
    }
}
