//
// Created by Tomas Tzorta on 10/12/2023.
//

#include "Gameplay/HealthComponent.h"

#include "LabyrinthFramework/Core.h"

namespace labyrinth_engine
{
    HealthComponent::HealthComponent(float a_health, float a_maxHealth)
        : m_health(a_health)
        , m_maxHealth(a_maxHealth)
    {

    }

    void HealthComponent::SetHealth(float a_health)
    {
        if (a_health == 0) return;
        if (m_health == 0) return;

        m_health += a_health;
        if (m_health < 0)
        {
            m_health = 0;
        }

        if (m_health > m_maxHealth)
        {
            m_health = m_maxHealth;
        }

        OnHealthChange.Broadcast(a_health, m_health, m_maxHealth);

        if (a_health < 0)
        {
            TakenDamage(-a_health);
            if (m_health <= 0)
            {
                Die();
            }
        }


    }

    void HealthComponent::TakenDamage(float a_damage)
    {
        OnDamage.Broadcast(a_damage, m_health, m_maxHealth);
    }

    void HealthComponent::Die()
    {
        OnDeath.Broadcast();
    }
}
