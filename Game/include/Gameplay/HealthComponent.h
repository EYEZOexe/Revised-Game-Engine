//
// Created by Tomas Tzorta on 10/12/2023.
//

#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "LabyrinthEngine/EventCallback.h"

namespace labyrinth_engine
{
    class HealthComponent
    {
    public:
        HealthComponent(float a_health, float a_maxHealth);

        void Damage(float a_damage);

        void Die();

        void RegenerateHealth(float a_health);

        void SetHealth(float a_health);

        // Getters
        float GetHealth() const {return m_health;}
        float GetMaxHealth() const {return m_maxHealth;}

        EventCallback<float, float, float> OnDamage;

    private:
        float m_health;
        float m_maxHealth;
    };
}

#endif //HEALTHCOMPONENT_H
