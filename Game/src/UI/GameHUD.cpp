//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "UI/GameHUD.h"

namespace labyrinth_engine
{
    GameHUD::GameHUD()
        : m_gameFramerateText{"Frame Rate: "}
    {
        m_gameFramerateText.SetWidgetTextSize(30);
    }

    void GameHUD::DrawHUD(sf::RenderWindow& a_window)
    {
        m_gameFramerateText.FrameworkWidgetDraw(a_window);
    }

    void GameHUD::UpdateHUD(float a_deltaTime)
    {
        int frameRate = int(1 / a_deltaTime);
        std::string frameRateString = "Frame Rate: " + std::to_string(frameRate);
        m_gameFramerateText.SetWidgetText(frameRateString);
    }
}
