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
        SetActorCollisionLayer(a_owner->GetCollisionLayer());
    }

    void Projectile::ActorBeginPlay()
    {
        Actor::ActorBeginPlay(); // Call the base class version of this function

        SetEnableActorPhysics(true); // Enable the physics of the projectile
    }

    void Projectile::ActorTick(float a_deltaTime)
    {
        Actor::ActorTick(a_deltaTime); // Call the base class version of this function

        MoveProjectile(a_deltaTime); // Move the projectile

        if (IsActorOutOfBounds()) // If the projectile is out of bounds
        {
            Destroy(); // Destroy the projectile
        }
    }

    void Projectile::OnActorBeginOverlap(Actor* a_otherActor)
    {
        if (IsHostileTo(a_otherActor)) // If the projectile is hostile to the other actor
        {
            a_otherActor->DoDamage(GetProjectileDamage()); // Do damage to the other actor
            Destroy(); // Destroy the projectile
        }
    }

    void Projectile::MoveProjectile(float a_deltaTime)
    {
        AddActorLocationOffset(GetActorForwardVector() * m_speed * a_deltaTime); // Move the projectile forward
    }
}
