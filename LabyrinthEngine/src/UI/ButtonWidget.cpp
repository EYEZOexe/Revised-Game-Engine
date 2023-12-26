//
// Created by Tomas Tzorta on 25/12/2023.
//

#include "UI/ButtonWidget.h"

#include "LabyrinthFramework/AssetManager.h"

namespace labyrinth_engine
{
    ButtonWidget::ButtonWidget(const std::string& a_buttonText, const std::string& a_buttonTextureFilename)
        : m_buttonTexture{AssetManager::GetInstance().LoadTexture(a_buttonTextureFilename)}
        , m_buttonSprite{*m_buttonTexture.get()}
        , m_buttonFont{AssetManager::GetInstance().LoadFont("Bonus/kenvector_future.ttf")}
        , m_buttonText{a_buttonText, *m_buttonFont.get(), }
        , m_ButtonIdleColour{128, 128, 128, 255}
        , m_ButtonPressedColour{64, 64, 64, 255}
        , m_ButtonHoverColour{192, 192, 192, 255}
        , m_isButtonPressed{false}
    {

    }

    void ButtonWidget::DrawWidget(sf::RenderWindow& a_window)
    {
        a_window.draw(m_buttonSprite);
        a_window.draw(m_buttonText);
    }

    void ButtonWidget::UpdateWidgetLocation(const sf::Vector2f& a_position)
    {
        m_buttonSprite.setPosition(a_position);
        m_buttonText.setPosition(a_position);
    }

    void ButtonWidget::UpdateWidgetRotation(float& a_rotation)
    {
        m_buttonSprite.setRotation(a_rotation);
        m_buttonText.setRotation(a_rotation);
    }
}
