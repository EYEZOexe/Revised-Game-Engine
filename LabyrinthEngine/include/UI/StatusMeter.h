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
        void UpdateStatus(float a_value, float a_maxValue); // update the status
        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Setters and Getters */

        // Setters
        void SetStatusTextSize(unsigned int a_fontSize) {m_StatusText.setCharacterSize(a_fontSize);} // set the font size
        void SetFrontWidgetColour(const sf::Color& a_colour) {m_StatusMeterFront.setFillColor(a_colour);} // set the front colour
        void SetBackWidgetColour(const sf::Color& a_colour) {m_StatusMeterBack.setFillColor(a_colour);} // set the back colour

        // Getters
        sf::FloatRect GetWidgetBounds() const override; // get the bounds of the widget

        /* End of Setters and getters */

    protected:

    private:
        void DrawWidget(sf::RenderWindow& a_window) override; // draw the widget
        void UpdateWidgetLocation(const sf::Vector2f& a_position) override; // update the widget location
        void UpdateWidgetRotation(float& a_rotation) override; // update the widget rotation
        void CenterWidgetText(); // center the widget text
        Shared<sf::Font> m_StatusFont; // the font of the status text
        sf::Text m_StatusText; // the status text

        sf::RectangleShape m_StatusMeterFront; // the front of the status meter
        sf::RectangleShape m_StatusMeterBack; // the back of the status meter

        sf::Color m_StatusMeterFrontColour; // the front colour of the status meter
        sf::Color m_StatusMeterBackColour; // the back colour of the status meter

        float m_StatusValue;
    };
}

#endif //STATUSMETER_H
