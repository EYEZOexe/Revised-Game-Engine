//
// Created by Tomas Tzorta on 09/12/2023.
//

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "LabyrinthEngine/Actor.h"
#include "LabyrinthEngine/World.h"
#include "Gameplay/HealthComponent.h"

namespace labyrinth_engine
{
    class Spaceship : public Actor
    {
    public:
        Spaceship(World* a_owningWorld, const std::string& a_texturePath = "");
        void ActorTick(float a_deltaTime) override;

        void SetVelocity(const sf::Vector2f& a_velocity) { m_velocity = a_velocity; }
        sf::Vector2f GetVelocity() const { return m_velocity; }

        virtual void Fire();
        void ActorBeginPlay() override;
        void DoDamage(float a_damage) override;
    private:
        virtual void OnHealthChange(float a_amount, float a_currentHealth, float a_maxHealth);
        virtual void OnDamage(float a_damage, float a_currentHealth, float a_maxHealth);
        virtual void OnDeath();
        sf::Vector2f m_velocity;
        HealthComponent m_healthComponent;
    };

}

#endif //SPACESHIP_H
