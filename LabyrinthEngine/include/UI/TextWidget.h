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
        void SetWidgetText(const std::string& a_text);
        void SetWidgetTextSize(unsigned int a_fontSize);

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void UpdateWidgetLocation(const sf::Vector2f& a_position) override;
        void UpdateWidgetRotation(float& a_rotation) override;
        void DrawWidget(sf::RenderWindow& a_window) override;
        Shared<sf::Font> m_widgetFont;
        sf::Text m_widgetText;
    };
}

#endif //TEXTWIDGET_H
