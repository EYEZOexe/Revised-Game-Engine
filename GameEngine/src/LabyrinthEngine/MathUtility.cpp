//
// Created by Tomas Tzorta on 08/12/2023.
//

#include "LabyrinthEngine/MathUtility.h"

namespace labyrinth_engine
{
    constexpr float PI = 3.14159265358979323846f;

    sf::Vector2f RotationToVector(float a_rotation)
    {
        float radians = DegreesToradians(a_rotation);
        return sf::Vector2f(cosf(radians), sinf(radians));

    }

    float DegreesToradians(const float a_degrees)
    {
        return a_degrees * PI / 180.0f;
    }

    float RadiansToDegrees(const float a_radians)
    {
        return a_radians * 180.0f / PI;
    }

    float InterpolateFloat(float a_start, float a_end, float a_alpha)
    {
        if (a_alpha > 1.0f) a_alpha = 1.0f; //clamp the alpha
        if (a_alpha < 0.0f) a_alpha = 0.0f; //clamp the alpha

        return a_start + (a_end - a_start) * a_alpha; //interpolate
    }

    sf::Color InterpolateColour(const sf::Color& a_start, const sf::Color& a_end, float a_alpha)
    {
        int Red = InterpolateFloat(a_start.r, a_end.r, a_alpha); //interpolate the red
        int Green = InterpolateFloat(a_start.g, a_end.g, a_alpha); //interpolate the green
        int Blue = InterpolateFloat(a_start.b, a_end.b, a_alpha); //interpolate the blue
        int Alpha = InterpolateFloat(a_start.a, a_end.a, a_alpha); //interpolate the alpha

        return sf::Color(Red, Green, Blue, Alpha); //return the interpolated color
    }

    sf::Vector2f InterpolateVector(const sf::Vector2f& a_start, const sf::Vector2f& a_end, float a_alpha)
    {
        float x = InterpolateFloat(a_start.x, a_end.x, a_alpha); //interpolate the x
        float y = InterpolateFloat(a_start.y, a_end.y, a_alpha); //interpolate the y

        return sf::Vector2f(x, y); //return the interpolated vector
    }
}
