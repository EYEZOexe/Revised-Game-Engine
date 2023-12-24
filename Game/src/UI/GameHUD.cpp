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
    {
        m_gameFramerateText.SetWidgetTextSize(20);
    }

    void GameHUD::HUDInit(const sf::RenderWindow& a_window)
    {
        auto windowSize = a_window.getSize();
        m_playerHealthBar.SetWidgetPosition(sf::Vector2f{20.0f, windowSize.y - 50.0f});
        PlayerHUDReset();
    }

    void GameHUD::PlayerHealthUpdate(float a_amount, float a_currentHealth, float a_maxHealth)
    {
        m_playerHealthBar.UpdateStatus(a_currentHealth, a_maxHealth);
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
            m_playerHealthBar.UpdateStatus(healthComponent.GetHealth(), healthComponent.GetMaxHealth());
        }
    }

    void GameHUD::PlayerDeath(Actor* a_actor)
    {
        PlayerHUDReset();
    }

    void GameHUD::DrawHUD(sf::RenderWindow& a_window)
    {
        m_gameFramerateText.FrameworkWidgetDraw(a_window);
        m_playerHealthBar.FrameworkWidgetDraw(a_window);
    }

    void GameHUD::UpdateHUD(float a_deltaTime)
    {
        int frameRate = int(1 / a_deltaTime);
        std::string frameRateString = "Frame Rate: " + std::to_string(frameRate);
        m_gameFramerateText.SetWidgetText(frameRateString);
    }
}
