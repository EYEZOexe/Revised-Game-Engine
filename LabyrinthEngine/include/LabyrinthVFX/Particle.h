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
        void RandomiseVelocity(float a_minSpeed, float a_maxSpeed);
        void RandomiseScale(float a_minScale, float a_maxScale);
        void RandomiseLifeTime(float a_minLifeTime, float a_maxLifeTime);

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
        void MoveParticle(float a_deltaTime);
        void FadeParticle(float a_deltaTime);
        sf::Vector2f m_velocity;
        float m_lifeTime;
        sf::Clock m_lifeTimer;
    };
}




#endif //PARTICLE_H
