//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "UI/HUD.h"

namespace labyrinth_engine
{
    void HUD::HUDInitFramework(const sf::RenderWindow& a_window)
    {
        if (!m_bIsHUDInitialised)
        {
            m_bIsHUDInitialised = true;
            HUDInit(a_window);

        }
    }

    void HUD::UpdateHUD(float a_deltaTime)
    {

    }

    bool HUD::IsHUDClicked(const sf::Event& a_event)
    {
        return false;
    }

    HUD::HUD()
        : m_bIsHUDInitialised{false}
    {

    }

    void HUD::HUDInit(const sf::RenderWindow& a_window)
    {

    }
}
