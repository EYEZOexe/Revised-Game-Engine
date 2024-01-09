//
// Created by Tomas Tzorta on 11/12/2023.
//

#ifndef PARTICLE_H
#define PARTICLE_H
#include "LabyrinthFramework/Actor.h"

namespace labyrinth_engine
{
    class Particle : public Actor
    {
    public:
        /* Constructors and Destructors */
        Particle(World* a_owningWorld, const std::string& a_texturePath);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions
        void RandomiseVelocity(float a_minSpeed, float a_maxSpeed); // Randomises the velocity of the particle
        void RandomiseScale(float a_minScale, float a_maxScale); // Randomises the scale of the particle
        void RandomiseLifeTime(float a_minLifeTime, float a_maxLifeTime); // Randomises the life time of the particle

        // Boolean Functions

        // Virtual Functions
        void ActorBeginPlay() override;
        void ActorTick(float a_deltaTime) override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void MoveParticle(float a_deltaTime); // Moves the particle
        void FadeParticle(float a_deltaTime); // Fades the particle
        sf::Vector2f m_velocity; // The velocity of the particle
        float m_lifeTime; // The life time of the particle
        sf::Clock m_lifeTimer; // The timer for the life time of the particle
    };
}




#endif //PARTICLE_H
