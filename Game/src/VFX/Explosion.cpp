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
        const Vec<std::string>& a_particleTextures)
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

    void Explosion::SpawnExplosion(World* a_world, const sf::Vector2f& a_location)
    {
        if (!a_world) return;

        for (int i = 0; i < m_particleAmount; i++)
        {
            std::string particleTexture = m_particleTextures[(int)RandomFloat(0, m_particleTextures.size())];
            Wptr<Particle> newParticle = a_world->SpawnActor<Particle>(particleTexture);

            newParticle.lock()->RandomiseLifeTime(m_particleLifeTimeMin, m_particleLifeTimeMax);
            newParticle.lock()->SetActorLocation(a_location);
            newParticle.lock()->RandomiseScale(m_particleSizeMin, m_particleSizeMax);
            newParticle.lock()->RandomiseVelocity(m_particleSpeedMin, m_particleSpeedMax);
            newParticle.lock()->GetSprite().setColor(m_particleColour);
        }
    }
}
