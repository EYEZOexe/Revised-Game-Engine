//
// Created by s5216712 on 11/12/2023.
//

#include "Enemy/EnemySpaceship.h"

namespace labyrinth_engine
{
    EnemySpaceship::EnemySpaceship(World* a_owningWorld, const std::string& a_texturePath, float a_spaceshipCollisionDamage)
        : Spaceship(a_owningWorld, a_texturePath)
        , m_spaceshipCollisionDamage(a_spaceshipCollisionDamage)
    {
        SetActorCollisionLayer(GetEnemyCollisionLayer());
        SetActorRotation(180.0f);
    }

    void EnemySpaceship::ActorTick(const float a_deltaTime)
    {
        Spaceship::ActorTick(a_deltaTime);
        if (IsActorOutOfBounds(GetActorBounds().width)) // If the actor is out of bounds, destroy it
        {
            Destroy();
        }
    }

    void EnemySpaceship::OnActorBeginOverlap(Actor* m_actor)
    {
        Spaceship::OnActorBeginOverlap(m_actor); // Call the base class implementation of this function

        if (IsHostileTo(m_actor))
        {
            m_actor->DoDamage(m_spaceshipCollisionDamage);
        }
    }
}
