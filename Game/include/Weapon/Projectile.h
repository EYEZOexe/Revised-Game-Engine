//
// Created by Tomas Tzorta on 10/12/2023.
//

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Framework/Actor.h"

namespace labyrinth_engine
{
    class Projectile : public Actor
    {
    public:
        Projectile(World* a_world, Actor* a_owner, const std::string& a_texturePath, float a_speed = 600.0f, float a_damage = 10.0f);

        void ActorTick(float a_deltaTime) override;

        // Getters and Setters
        void SetProjectileSpeed(const float a_speed) { m_speed = a_speed; };
        void SetProjectileDamage(const float a_damage) { m_damage = a_damage; };

        float GetProjectileSpeed() const { return m_speed; };
        float GetProjectileDamage() const { return m_damage; };

    private:
        void MoveProjectile(float a_deltaTime);

        Actor* m_owner;
        float m_speed;
        float m_damage;
    };
}

#endif //PROJECTILE_H
