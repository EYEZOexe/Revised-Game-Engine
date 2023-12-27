//
// Created by Tomas Tzorta on 24/12/2023.
//

#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Graphics.hpp>
#include <SDL2/SDL.h>
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
        void FrameworkWidgetDraw(sf::RenderWindow& a_window);

        // Boolean Functions

        // Virtual Functions
        virtual bool IsMouseOver(const SDL_Event& a_event);
        virtual sf::FloatRect GetWidgetBounds() const = 0;
        sf::Vector2f GetWidgetCenterPosition() const;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        void SetWidgetPosition(const sf::Vector2f& a_position);
        void SetWidgetRotation(float& a_rotation);
        void SetWidgetVisible(bool a_visible) {m_isWidgetVisible = a_visible;}

        // Getters
        sf::Vector2f GetWidgetPosition() const {return m_widgetTransform.getPosition();}
        float GetWidgetRotation() const {return m_widgetTransform.getRotation();}
        bool IsWidgetVisible() const {return m_isWidgetVisible;}

        /* End of Setters and getters */

    protected:
        Widget(); // protected because it is an abstract class

    private:
        virtual void DrawWidget(sf::RenderWindow& window);
        virtual void UpdateWidgetLocation(const sf::Vector2f& a_position);
        virtual void UpdateWidgetRotation(float& a_rotation);
        sf::Transformable m_widgetTransform; // Transformable object for the widget
        bool m_isWidgetVisible; // Boolean to check if the widget is visible
    };
}


#endif //WIDGET_H
