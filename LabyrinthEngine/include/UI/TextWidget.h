//
// Created by Tomas Tzorta on 24/12/2023.
//

#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include "LabyrinthFramework/Core.h"
#include "Widget.h"

namespace labyrinth_engine
{
    class TextWidget: public Widget
    {
    public:
        /* Constructors and Destructors */
        TextWidget(const std::string& a_text, const std::string& a_fontDirectory = "Bonus/kenvector_future.ttf", unsigned int a_fontSize = 10);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        void SetWidgetText(const std::string& a_text); // Set the text of the widget
        void SetWidgetTextSize(unsigned int a_fontSize); // Set the size of the text

        // Getters
        sf::FloatRect GetWidgetBounds() const override;

        /* End of Setters and getters */

    protected:

    private:
        void UpdateWidgetLocation(const sf::Vector2f& a_position) override; // Update the location of the widget
        void UpdateWidgetRotation(float& a_rotation) override; // Update the rotation of the widget
        void DrawWidget(sf::RenderWindow& a_window) override; // Draw the widget
        Shared<sf::Font> m_widgetFont; // Font of the widget
        sf::Text m_widgetText; // Text of the widget
    };
}

#endif //TEXTWIDGET_H
