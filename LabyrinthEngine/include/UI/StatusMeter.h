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
        StatusMeter(const sf::Vector2f& a_size = sf::Vector2f{200.0f, 30.0f}, float a_minValue = 0.75f, const sf::Color& a_frontColour = sf::Color::Green, const sf::Color& a_backColour = sf::Color{128, 128, 128, 255});
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
        void SetStatusTextSize(unsigned int a_fontSize) {m_StatusText.setCharacterSize(a_fontSize);}
        void SetFrontWidgetColour(const sf::Color& a_colour) {m_StatusMeterFront.setFillColor(a_colour);}
        void SetBackWidgetColour(const sf::Color& a_colour) {m_StatusMeterBack.setFillColor(a_colour);}

        // Getters
        sf::FloatRect GetWidgetBounds() const override;

        /* End of Setters and getters */

    protected:

    private:
        void DrawWidget(SDL_Window& a_window) override;
        void UpdateWidgetLocation(const sf::Vector2f& a_position) override;
        void UpdateWidgetRotation(float& a_rotation) override;
        void CenterWidgetText();
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
