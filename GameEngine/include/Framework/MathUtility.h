//
// Created by NAT20 on 08/12/2023.
//

#ifndef MATHUTILITY_H
#define MATHUTILITY_H

#include "SFML/Graphics.hpp"

namespace Framework
{
    sf::Vector2f RotationToVector(float a_rotation);
    float DegreesToradians(float a_degrees);
    float RadiansToDegrees(float a_radians);
}




#endif //MATHUTILITY_H
