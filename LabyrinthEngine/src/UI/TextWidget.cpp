//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "UI/TextWidget.h"

#include "LabyrinthFramework/AssetManager.h"

namespace labyrinth_engine
{
    TextWidget::TextWidget(const std::string& a_text, const std::string& a_fontDirectory, unsigned int a_fontSize)
        : m_widgetFont{AssetManager::GetInstance().LoadFont(a_fontDirectory)}
        , m_widgetText{a_text, *(m_widgetFont.get()), a_fontSize}
    {

    }

    void TextWidget::SetWidgetText(const std::string& a_text)
    {
        m_widgetText.setString(a_text);
    }

    void TextWidget::SetWidgetTextSize(unsigned a_fontSize)
    {
        m_widgetText.setCharacterSize(a_fontSize);
    }

    sf::FloatRect TextWidget::GetWidgetBounds() const
    {
        return m_widgetText.getGlobalBounds();
    }

    void TextWidget::UpdateWidgetLocation(const sf::Vector2f& a_position)
    {
        m_widgetText.setPosition(a_position);
    }

    void TextWidget::UpdateWidgetRotation(float& a_rotation)
    {
        m_widgetText.setRotation(a_rotation);
    }

    void TextWidget::DrawWidget(SDL_Window& a_window)
    {
        //TODO: Fix this
        //a_window.draw(m_widgetText);
    }
}
