//
// Created by Tomas Tzorta on 10/12/2023.
//

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "LabyrinthFramework/Actor.h"

namespace labyrinth_engine
{
    class Projectile : public Actor
    {
    public:
        Projectile(World* a_world, Actor* a_owner, const std::string& a_texturePath, float a_speed = 600.0f, float a_damage = 10.0f);

        void ActorTick(float a_deltaTime) override; // Override the base class version of this function
        void ActorBeginPlay() override; // Override the base class version of this function

        // Getters and Setters
        void SetProjectileSpeed(const float a_speed) { m_speed = a_speed; }; // Set the speed of the projectile
        void SetProjectileDamage(const float a_damage) { m_damage = a_damage; }; // Set the damage of the projectile

        float GetProjectileSpeed() const { return m_speed; }; // Get the speed of the projectile
        float GetProjectileDamage() const { return m_damage; }; // Get the damage of the projectile

    private:
        void OnActorBeginOverlap(Actor* a_otherActor) override; // Override the base class version of this function
        void MoveProjectile(float a_deltaTime); // Move the projectile forward

        float m_speed; // The speed of the projectile
        float m_damage; // The damage of the projectile

        Actor* m_owner; // The owner of the projectile
    };
}

#endif //PROJECTILE_H
