//
// Created by Tomas Tzorta on 10/12/2023.
//

#include "Weapon/Projectile.h"

namespace labyrinth_engine
{
    Projectile::Projectile(World* a_world, Actor* a_owner, const std::string& a_texturePath, float a_speed, float a_damage)
        : Actor(a_world, a_texturePath)
        , m_owner(a_owner)
        , m_speed(a_speed)
        , m_damage(a_damage)
    {

    }

    void Projectile::ActorTick(float a_deltaTime)
    {
        Actor::ActorTick(a_deltaTime); // Call the base class version of this function

        MoveProjectile(a_deltaTime);

        if (IsActorOutOfBounds())
        {
            ObjectDestroy();
        }
    }

    void Projectile::MoveProjectile(float a_deltaTime)
    {
        AddActorLocationOffset(GetActorForwardVector() * m_speed * a_deltaTime); // Move the projectile forward
    }
}
