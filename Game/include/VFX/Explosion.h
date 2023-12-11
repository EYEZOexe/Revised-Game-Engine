//
// Created by Tomas Tzorta on 11/12/2023.
//

#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <string>
#include "LabyrinthFramework/Core.h"
#include <SFML/Graphics.hpp>

namespace labyrinth_engine
{
    class World;
    class Explosion
    {
    public:
        /* Constructors and Destructors */
        Explosion(int a_particleAmount = 20,
            float a_particleLifeTimeMin = 0.5f,
            float a_particleLifeTimeMax = 1.5f,
            float a_particleSpeedMin = 200.0f,
            float a_particleSpeedMax = 400.0f,
            float a_particleSizeMin = 1.0f,
            float a_particleSizeMax = 2.0f,
            const sf::Color& a_particleColour = sf::Color::White,
            const List<std::string>& a_particleTextures = {"PNG/Effects/star1.png", "PNG/Effects/star2.png", "PNG/Effects/star3.png"});
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions
        void SpawnExplosion(World* a_world, const sf::Vector2f& a_location);

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
        int m_particleAmount;
        float m_particleLifeTimeMin;
        float m_particleLifeTimeMax;
        float m_particleSpeedMin;
        float m_particleSpeedMax;
        float m_particleSizeMin;
        float m_particleSizeMax;
        sf::Color m_particleColour;
        List<std::string>  m_particleTextures;
    };
}

#endif //EXPLOSION_H
