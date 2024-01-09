//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "UI/Widget.h"

namespace labyrinth_engine
{
    Widget::Widget()
        : m_bIsWidgetVisible{true}
          , m_widgetTransform{}
    {

    }

    void Widget::FrameworkWidgetDraw(sf::RenderWindow& a_window)
    {
        if (m_bIsWidgetVisible)
        {
            DrawWidget(a_window);
        }
    }

    bool Widget::IsMouseOver(const sf::Event& a_event)
    {
        return false;
    }

    sf::Vector2f Widget::GetWidgetCenterPosition() const
    {
        sf::FloatRect widgetBounds = GetWidgetBounds();
        return sf::Vector2f{widgetBounds.left + widgetBounds.width/2.0f, widgetBounds.top + widgetBounds.height/2.0f}; // Return the center position of the widget
    }

    void Widget::SetWidgetPosition(const sf::Vector2f& a_position)
    {
        m_widgetTransform.setPosition(a_position); // Set the position of the widget
        UpdateWidgetLocation(a_position); // Update the location of the widget
    }

    void Widget::SetWidgetRotation(float& a_rotation)
    {
        m_widgetTransform.setRotation(a_rotation); // Set the rotation of the widget
        UpdateWidgetRotation(a_rotation); // Update the rotation of the widget
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
