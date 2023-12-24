//
// Created by Tomas Tzorta on 24/12/2023.
//

#ifndef STATUSMETER_H
#define STATUSMETER_H

#include "UI/Widget.h"

namespace labyrinth_engine
{
    class StatusMeter : public Widget
    {
    public:
        /* Constructors and Destructors */
        StatusMeter(const sf::Vector2f& a_size = sf::Vector2f{(300.0f), (40.0f)}, float a_minValue = 0.75f, const sf::Color& a_frontColour = sf::Color::Green, const sf::Color& a_backColour = sf::Color{128, 128, 128, 255});
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions
        void UpdateStatus(float a_value, float a_maxValue);

        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void DrawWidget(sf::RenderWindow& a_window) override;
        void UpdateWidgetLocation(const sf::Vector2f& a_position) override;
        void UpdateWidgetRotation(float& a_rotation) override;
        Shared<sf::Font> m_StatusFont;
        sf::Text m_StatusText;

        sf::RectangleShape m_StatusMeterFront;
        sf::RectangleShape m_StatusMeterBack;

        sf::Color m_StatusMeterFrontColour;
        sf::Color m_StatusMeterBackColour;

        float m_StatusValue;
    };
}

#endif //STATUSMETER_H
