//
// Created by Tomas Tzorta on 09/12/2023.
//

#include "Spaceship/Spaceship.h"
#include "LabyrinthFramework/MathUtility.h"
#include "VFX/Explosion.h"

namespace labyrinth_engine
{
    Spaceship::Spaceship(World* a_owningWorld, const std::string& a_texturePath)
        : Actor(a_owningWorld, a_texturePath)
        , m_velocity{}
        , m_healthComponent(100.0f, 100.0f)
        , m_hitEffectTime(0.0f)
        , m_hitEffectDuration(0.2f)
        , m_hitEffectColor(sf::Color::Red)
    {

    }

    void Spaceship::ActorTick(const float a_deltaTime)
    {
        Actor::ActorTick(a_deltaTime);
        AddActorLocationOffset(GetSpaceshipVelocity() * a_deltaTime); //move the actor
        UpdateHitEffect(a_deltaTime); //update the hit effect
    }

    void Spaceship::Fire()
    {

    }

    void Spaceship::ActorBeginPlay()
    {
        Actor::ActorBeginPlay();
        SetEnableActorPhysics(true);

        m_healthComponent.OnHealthChange.Bind(GetWeakReference(), &Spaceship::OnHealthChange); //bind the function to the event
        m_healthComponent.OnDamage.Bind(GetWeakReference(), &Spaceship::OnDamage);
        m_healthComponent.OnDeath.Bind(GetWeakReference(), &Spaceship::OnBaseDeath);
    }

    void Spaceship::DoDamage(float a_damage)
    {
        m_healthComponent.SetHealth(-a_damage);
    }

    void Spaceship::HitEffect()
    {
        if (m_hitEffectTime == 0)
        {
            m_hitEffectTime = m_hitEffectDuration; //start the hit timer
        }
    }

    void Spaceship::UpdateHitEffect(float a_deltaTime)
    {
        if (m_hitEffectTime > 0)
        {
            m_hitEffectTime -= a_deltaTime; //update the hit timer
            m_hitEffectTime = m_hitEffectTime > 0 ? m_hitEffectTime : 0; //clamp the hit timer

            GetSprite().setColor(InterpolateColour(sf::Color::White, m_hitEffectColor, m_hitEffectTime));
        }
    }


    void Spaceship::OnHealthChange(float a_amount, float a_currentHealth, float a_maxHealth)
    {

    }

    void Spaceship::OnDamage(float a_damage, float a_currentHealth, float a_maxHealth)
    {
        HitEffect();
    }

    void Spaceship::OnBaseDeath()
    {
        Explosion* explosion = new Explosion();
        explosion->SpawnExplosion(GetWorld(), GetActorLocation()); //spawn the explosion
        OnDeath(); //call the death event
        //destroy the actor
        Destroy();
        delete explosion;
        AudioManager::GetInstance().PlaySFX("Explosion");
    }

    void Spaceship::OnDeath()
    {

    }
}
