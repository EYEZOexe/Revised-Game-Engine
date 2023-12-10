//
// Created by NAT20 on 08/12/2023.
//

#ifndef MATHUTILITY_H
#define MATHUTILITY_H

#include "SFML/Graphics.hpp"

namespace labyrinth_engine
{
    sf::Vector2f RotationToVector(float a_rotation);
    float DegreesToradians(float a_degrees);
    float RadiansToDegrees(float a_radians);

    template<typename T>
    float GetVectorLength(const sf::Vector2<T>& a_vector)
    {
        return sqrtf(a_vector.x * a_vector.x + a_vector.y * a_vector.y);
    }

    template<typename T>
    sf::Vector2<T>& ScaleVector(sf::Vector2<T>& a_vector, float a_length)
    {
        a_vector.x *= a_length;
        a_vector.y *= a_length;
        return a_vector;
    }

    template<typename T>
    sf::Vector2<T>& NormalizeVector(sf::Vector2<T>& a_vector)
    {
        float length = GetVectorLength<T>(a_vector);
        if (length == 0.0f) return a_vector;

        ScaleVector(a_vector, 1.0f / length);

        return a_vector;
    }

}




#endif //MATHUTILITY_H
