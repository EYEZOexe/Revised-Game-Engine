//
// Created by Tomas Tzorta on 24/12/2023.
//

#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Graphics.hpp>
#include "LabyrinthFramework/Object.h"

namespace labyrinth_engine
{
    class Widget : public Object
    {
    public:
        /* Constructors and Destructors */
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions
        void FrameworkWidgetDraw(sf::RenderWindow& a_window); // Function to draw the widget

        // Boolean Functions

        // Virtual Functions
        virtual bool IsMouseOver(const sf::Event& a_event); // Function to check if the mouse is over the widget
        virtual sf::FloatRect GetWidgetBounds() const = 0; // Function to get the bounds of the widget
        sf::Vector2f GetWidgetCenterPosition() const; // Function to get the center position of the widget

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        void SetWidgetPosition(const sf::Vector2f& a_position); // Function to set the position of the widget
        void SetWidgetRotation(float& a_rotation); // Function to set the rotation of the widget
        void SetWidgetVisible(bool a_visible) {m_bIsWidgetVisible = a_visible;} // Function to set the visibility of the widget

        // Getters
        sf::Vector2f GetWidgetPosition() const {return m_widgetTransform.getPosition();} // Function to get the position of the widget
        float GetWidgetRotation() const {return m_widgetTransform.getRotation();} // Function to get the rotation of the widget
        bool IsWidgetVisible() const {return m_bIsWidgetVisible;} // Function to check if the widget is visible

        /* End of Setters and getters */

    protected:
        Widget(); // protected because it is an abstract class

    private:
        virtual void DrawWidget(sf::RenderWindow& window); // Function to draw the widget
        virtual void UpdateWidgetLocation(const sf::Vector2f& a_position); // Function to update the location of the widget
        virtual void UpdateWidgetRotation(float& a_rotation); // Function to update the rotation of the widget
        sf::Transformable m_widgetTransform; // Transformable object for the widget
        bool m_bIsWidgetVisible; // Boolean to check if the widget is visible
    };
}


#endif //WIDGET_H
