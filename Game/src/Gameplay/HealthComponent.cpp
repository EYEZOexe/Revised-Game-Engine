//
// Created by Tomas Tzorta on 10/12/2023.
//

#include "Gameplay/HealthComponent.h"

#include "LabyrinthEngine/Core.h"

namespace labyrinth_engine
{
    HealthComponent::HealthComponent(float a_health, float a_maxHealth)
        : m_health(a_health)
        , m_maxHealth(a_maxHealth)
    {

    }

    void HealthComponent::Damage(float a_damage)
    {
        LE_LOG("Taken damage: %f, remaining HP: %f/%f", a_damage, m_health, m_maxHealth);
    }

    void HealthComponent::Die()
    {
        LE_LOG("Dead");
    }

    void HealthComponent::RegenerateHealth(float a_health)
    {
        LE_LOG("Health Regen: %f, remaining HP: %f/%f", a_health, m_health, m_maxHealth);
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

        if (a_health < 0)
        {
            Damage(-a_health);
            if (m_health <= 0)
            {
                Die();
            }
            else
            {
                RegenerateHealth(a_health);
            }
        }
    }
}
