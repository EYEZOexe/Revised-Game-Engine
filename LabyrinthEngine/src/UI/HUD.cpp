//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "UI/HUD.h"

namespace labyrinth_engine
{
    void HUD::HUDInitFramework( sf::RenderWindow& a_window)
    {
        if (!m_isHUDInitialised)
        {
            m_isHUDInitialised = true;
            HUDInit(a_window);

        }
    }

    bool HUD::IsHUDClicked(const sf::Event& a_event)
    {
        return false;
    }

    HUD::HUD()
        : m_isHUDInitialised{false}
    {

    }

    void HUD::HUDInit(sf::RenderWindow& a_window)
    {

    }
}
