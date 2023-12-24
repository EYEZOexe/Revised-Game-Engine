//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "UI/GameHUD.h"

namespace labyrinth_engine
{
    GameHUD::GameHUD()
        : m_gameFramerateText{"Frame Rate: "}
        , m_playerHealthBar{}
    {
        m_gameFramerateText.SetWidgetTextSize(30);
    }

    void GameHUD::HUDInit(const sf::RenderWindow& a_window)
    {
        auto windowSize = a_window.getSize();
        m_playerHealthBar.SetWidgetPosition(sf::Vector2f{20.0f, windowSize.y - 50.0f});
        m_playerHealthBar.UpdateStatus(100, 200);
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
