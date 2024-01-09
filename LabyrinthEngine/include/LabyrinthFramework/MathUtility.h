//
// Created by Tomas Tzorta on 08/12/2023.
//

#ifndef MATHUTILITY_H
#define MATHUTILITY_H

#include <SFML/Graphics.hpp>

namespace labyrinth_engine
{
    sf::Vector2f RotationToVector(float a_rotation); // convert rotation to vector
    float DegreesToradians(float a_degrees); // convert degrees to radians
    float RadiansToDegrees(float a_radians); // convert radians to degrees

    template<typename T>
    float GetVectorLength(const sf::Vector2<T>& a_vector) // get the length of a vector
    {
        return sqrtf(a_vector.x * a_vector.x + a_vector.y * a_vector.y); // return the length of the vector
    }

    template<typename T>
    sf::Vector2<T>& ScaleVector(sf::Vector2<T>& a_vector, float a_length) // scale a vector
    {
        a_vector.x *= a_length; // scale the x component
        a_vector.y *= a_length; // scale the y component
        return a_vector; // return the vector
    }

    template<typename T>
    sf::Vector2<T>& NormalizeVector(sf::Vector2<T>& a_vector) // normalize a vector
    {
        float length = GetVectorLength<T>(a_vector); // get the length of the vector
        if (length == 0.0f) return a_vector; // if the length is 0, return the vector

        ScaleVector(a_vector, 1.0f / length); // scale the vector

        return a_vector;
    }

    float InterpolateFloat(float a_start, float a_end, float a_alpha); // interpolate a float
    sf::Color InterpolateColour(const sf::Color& a_start, const sf::Color& a_end, float a_alpha); // interpolate a colour
    sf::Vector2f InterpolateVector(const sf::Vector2f& a_start, const sf::Vector2f& a_end, float a_alpha); // interpolate a vector

    float RandomFloat(float a_min, float a_max); // get a random float
    sf::Vector2f RandomVector(); // get a random vector

}




#endif //MATHUTILITY_H
