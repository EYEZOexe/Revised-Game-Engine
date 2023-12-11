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
        void ActorTick(float a_deltaTime) override; //tick event
        void ActorBeginPlay() override; //begin play event

        void SetVelocity(const sf::Vector2f& a_velocity) { m_velocity = a_velocity; }
        sf::Vector2f GetVelocity() const { return m_velocity; }

        virtual void Fire(); //fire the weapon
        void DoDamage(float a_damage) override; //damage the actor

    private:
        void HitEffect(); //hit effect
        void UpdateHitEffect(float a_deltaTime); //update the hit effect
        virtual void OnHealthChange(float a_amount, float a_currentHealth, float a_maxHealth); //health change event
        virtual void OnDamage(float a_damage, float a_currentHealth, float a_maxHealth); //damage event
        virtual void OnDeath(); //death event
        sf::Vector2f m_velocity;
        HealthComponent m_healthComponent; //health component

        float m_hitEffectTime; //timer for the hit effect
        float m_hitEffectDuration; //duration of the hit effect
        sf::Color m_hitEffectColor; //color of the hit effect
    };

}

#endif //SPACESHIP_H
