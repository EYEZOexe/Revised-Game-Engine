//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "UI/Widget.h"

namespace labyrinth_engine
{
    void Widget::FrameworkWidgetDraw(sf::RenderWindow& a_window)
    {
        if (m_isWidgetVisible)
        {
            DrawWidget(a_window);
        }
    }

    bool Widget::IsMouseOver(const sf::Event& a_event)
    {
        return false;
    }

    void Widget::SetWidgetPosition(const sf::Vector2f& a_position)
    {
        m_widgetTransform.setPosition(a_position);
        UpdateWidgetLocation(a_position);
    }

    void Widget::SetWidgetRotation(float& a_rotation)
    {
        m_widgetTransform.setRotation(a_rotation);
        UpdateWidgetRotation(a_rotation);
    }

    Widget::Widget()
        : m_isWidgetVisible{true}
        , m_widgetTransform{}
    {

    }

    void Widget::DrawWidget(sf::RenderWindow& window)
    {

    }

    void Widget::UpdateWidgetLocation(const sf::Vector2f& a_position)
    {

    }

    void Widget::UpdateWidgetRotation(float& a_rotation)
    {

    }
}
