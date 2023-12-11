//
// Created by Tomas Tzorta on 09/12/2023.
//

#include "Spaceship/Spaceship.h"

namespace labyrinth_engine
{
    Spaceship::Spaceship(World* a_owningWorld, const std::string& a_texturePath)
        : Actor(a_owningWorld, a_texturePath)
        , m_velocity{}
        , m_healthComponent(100.0f, 100.0f)
    {

    }

    void Spaceship::ActorTick(const float a_deltaTime)
    {
        Actor::ActorTick(a_deltaTime);
        AddActorLocationOffset(GetVelocity() * a_deltaTime);
    }

    void Spaceship::Fire()
    {

    }

    void Spaceship::ActorBeginPlay()
    {
        Actor::ActorBeginPlay();
        SetEnableActorPhysics(true);

        m_healthComponent.OnHealthChange.Bind(GetWeakReference(), &Spaceship::OnHealthChange);
        m_healthComponent.OnDamage.Bind(GetWeakReference(), &Spaceship::OnDamage);
        m_healthComponent.OnDeath.Bind(GetWeakReference(), &Spaceship::OnDeath);
    }

    void Spaceship::DoDamage(float a_damage)
    {
        m_healthComponent.SetHealth(-a_damage);
    }


    void Spaceship::OnHealthChange(float a_amount, float a_currentHealth, float a_maxHealth)
    {

    }

    void Spaceship::OnDamage(float a_damage, float a_currentHealth, float a_maxHealth)
    {
    }

    void Spaceship::OnDeath()
    {
        //destroy the actor
        Destroy();
    }
}
