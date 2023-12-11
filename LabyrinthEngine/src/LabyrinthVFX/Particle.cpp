//
// Created by Tomas Tzorta on 11/12/2023.
//

#include "LabyrinthVFX/Particle.h"

#include "LabyrinthFramework/MathUtility.h"

namespace labyrinth_engine
{
    Particle::Particle(World* a_owningWorld, const std::string& a_texturePath)
        : Actor(a_owningWorld, a_texturePath)
        , m_velocity{}
        , m_lifeTime{1.0f}
        , m_lifeTimer{}
    {

    }

    void Particle::RandomiseVelocity(float a_minSpeed, float a_maxSpeed)
    {
        m_velocity = RandomVector() * RandomFloat(a_minSpeed, a_maxSpeed);
    }

    void Particle::RandomiseScale(float a_minScale, float a_maxScale)
    {
        float randomScale = RandomFloat(a_minScale, a_maxScale);
        GetSprite().setScale(randomScale, randomScale);
    }


    void Particle::RandomiseLifeTime(float a_minLifeTime, float a_maxLifeTime)
    {
        m_lifeTime = RandomFloat(a_minLifeTime, a_maxLifeTime);
    }

    void Particle::ActorBeginPlay()
    {
        Actor::ActorBeginPlay();
        SetEnableActorPhysics(false);
    }

    void Particle::ActorTick(float a_deltaTime)
    {
        Actor::ActorTick(a_deltaTime);

        MoveParticle(a_deltaTime);
        FadeParticle(a_deltaTime);

        if (m_lifeTimer.getElapsedTime().asSeconds() >= m_lifeTime)
        {
            Destroy();
        }
    }

    void Particle::MoveParticle(float a_deltaTime)
    {
        AddActorLocationOffset(m_velocity * a_deltaTime);
    }

    void Particle::FadeParticle(float a_deltaTime)
    {
        const float timePassed = m_lifeTimer.getElapsedTime().asSeconds();
        GetSprite().setColor(InterpolateColour(GetSprite().getColor(), sf::Color::Transparent, timePassed / m_lifeTime)); //fade the particle
        GetSprite().setScale(InterpolateVector(GetSprite().getScale(), sf::Vector2f(0.0f, 0.0f), timePassed / m_lifeTime)); //scale the particle
    }
}
