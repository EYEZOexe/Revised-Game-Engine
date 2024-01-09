//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "UI/StatusMeter.h"
#include "LabyrinthFramework/AssetManager.h"

namespace labyrinth_engine
{
    StatusMeter::StatusMeter(const sf::Vector2f& a_size, float a_minValue, const sf::Color& a_frontColour,const sf::Color& a_backColour)
        : m_StatusFont{{AssetManager::GetInstance().LoadFont("Bonus/kenvector_future.ttf")}}
        , m_StatusText{"", *m_StatusFont.get()}
        , m_StatusMeterFront{a_size}
        , m_StatusMeterBack{a_size}
        , m_StatusValue{a_minValue}
        , m_StatusMeterFrontColour{a_frontColour}
        , m_StatusMeterBackColour{a_backColour}
    {
        m_StatusMeterFront.setFillColor(m_StatusMeterFrontColour);
        m_StatusMeterBack.setFillColor(m_StatusMeterBackColour);
        SetStatusTextSize(20);
    }

    void StatusMeter::UpdateStatus(float a_value, float a_maxValue)
    {
        if (a_maxValue == 0) return;

        // Update the status value and text
        m_StatusValue = a_value / a_maxValue;
        std::string statusText = std::to_string((int)a_value) + "/" + std::to_string((int)a_maxValue);
        m_StatusText.setString(statusText);

        sf::Vector2f statusBarSize = m_StatusMeterBack.getSize();
        m_StatusMeterFront.setSize({statusBarSize.x * m_StatusValue, statusBarSize.y});
        CenterWidgetText();
    }

    sf::FloatRect StatusMeter::GetWidgetBounds() const
    {
        return m_StatusMeterBack.getGlobalBounds();
    }

    void StatusMeter::DrawWidget(sf::RenderWindow& a_window)
    {
        a_window.draw(m_StatusMeterBack);
        a_window.draw(m_StatusMeterFront);
        a_window.draw(m_StatusText);
    }

    void StatusMeter::UpdateWidgetLocation(const sf::Vector2f& a_position)
    {
        m_StatusMeterFront.setPosition(a_position);
        m_StatusMeterBack.setPosition(a_position);
        CenterWidgetText();
    }

    void StatusMeter::UpdateWidgetRotation(float& a_rotation)
    {
        m_StatusText.setRotation(a_rotation);
        m_StatusMeterFront.setRotation(a_rotation);
        m_StatusMeterBack.setRotation(a_rotation);

    }

    void StatusMeter::CenterWidgetText()
    {
        sf::Vector2f widgetCenter = GetWidgetCenterPosition();
        sf::FloatRect textBounds = m_StatusText.getGlobalBounds();
        m_StatusText.setPosition(widgetCenter - sf::Vector2f{textBounds.width/2.0f, textBounds.height});
    }
}
