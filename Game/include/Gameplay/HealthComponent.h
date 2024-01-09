//
// Created by Tomas Tzorta on 10/12/2023.
//

#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "LabyrinthFramework/EventCallback.h"

namespace labyrinth_engine
{
    class HealthComponent
    {
    public:
        HealthComponent(float a_health, float a_maxHealth);

        void SetHealth(float a_health);
        void SetMaxHealth(float a_health, float a_maxHealth);

        // Getters
        float GetHealth() const {return m_health;}
        float GetMaxHealth() const {return m_maxHealth;}

        EventCallback<float, float, float> OnHealthChange;
        EventCallback<float, float, float> OnDamage;
        EventCallback<> OnDeath;

    private:
        void TakenDamage(float a_damage);
        void Die();
        float m_health;
        float m_maxHealth;
    };
}

#endif //HEALTHCOMPONENT_H
