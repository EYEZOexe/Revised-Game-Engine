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

        m_healthComponent.OnDamage.Bind(GetWeakReference(), &Spaceship::OnHealthChange);

        m_healthComponent.OnDamage.Broadcast(10, 89, 100);
    }

    void Spaceship::OnHealthChange(float a_amount, float a_currentHealth, float a_maxHealth)
    {
        LE_LOG("health changed by: %f, and is now: %f/%f", a_amount, a_currentHealth, a_maxHealth);
    }
}
