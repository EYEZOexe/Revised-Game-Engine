//
// Created by Tomas Tzorta on 11/12/2023.
//

#include "VFX/Explosion.h"
#include "LabyrinthFramework/MathUtility.h"
#include "LabyrinthFramework/World.h"
#include "LabyrinthVFX/Particle.h"

namespace labyrinth_engine
{
    Explosion::Explosion(int a_particleAmount, float a_particleLifeTimeMin, float a_particleLifeTimeMax,
        float a_particleSpeedMin, float a_particleSpeedMax, float a_particleSizeMin, float a_particleSizeMax, const sf::Color& a_particleColour,
        const List<std::string>& a_particleTextures)
        : m_particleAmount(a_particleAmount)
        , m_particleLifeTimeMin(a_particleLifeTimeMin)
        , m_particleLifeTimeMax(a_particleLifeTimeMax)
        , m_particleSpeedMin(a_particleSpeedMin)
        , m_particleSpeedMax(a_particleSpeedMax)
        , m_particleSizeMin(a_particleSizeMin)
        , m_particleSizeMax(a_particleSizeMax)
        , m_particleColour(a_particleColour)
        , m_particleTextures(a_particleTextures)
    {
    }

    void Explosion::SpawnExplosion(World* a_world, const sf::Vector2f& a_location) // spawns the explosion
    {
        if (!a_world) return; // if the world is null then return

        for (int i = 0; i < m_particleAmount; i++) // for loop that spawns the particles
        {
            std::string particleTexture = m_particleTextures[(int)RandomFloat(0, m_particleTextures.size())]; // gets a random texture from the list of textures
            Weak<Particle> newParticle = a_world->SpawnActor<Particle>(particleTexture); // spawns a new particle

            newParticle.lock()->RandomiseLifeTime(m_particleLifeTimeMin, m_particleLifeTimeMax); // randomises the lifetime of the particle
            newParticle.lock()->SetActorLocation(a_location); // sets the location of the particle
            newParticle.lock()->RandomiseScale(m_particleSizeMin, m_particleSizeMax); // randomises the scale of the particle
            newParticle.lock()->RandomiseVelocity(m_particleSpeedMin, m_particleSpeedMax); // randomises the velocity of the particle
            newParticle.lock()->GetSprite().setColor(m_particleColour); // sets the colour of the particle
        }
    }
}
