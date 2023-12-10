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
}
