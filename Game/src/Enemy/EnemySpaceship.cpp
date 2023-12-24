//
// Created by s5216712 on 11/12/2023.
//

#include "Enemy/EnemySpaceship.h"
#include "LabyrinthFramework/MathUtility.h"

namespace labyrinth_engine
{
    EnemySpaceship::EnemySpaceship(World* a_owningWorld, const std::string& a_texturePath, float a_spaceshipCollisionDamage, const List<RewardInternalFunction> a_rewards)
        : Spaceship{a_owningWorld, a_texturePath}
        , m_spaceshipCollisionDamage{a_spaceshipCollisionDamage}
        , m_rewardFunctions{a_rewards}
    {
        SetActorCollisionLayer(GetEnemyCollisionLayer());
        SetActorRotation(180.0f);
    }

    void EnemySpaceship::ActorTick(const float a_deltaTime)
    {
        Spaceship::ActorTick(a_deltaTime);
        if (IsActorOutOfBounds(GetActorBounds().width * 2.0f)) // If the actor is out of bounds, destroy it
        {
            Destroy();
        }
    }

    void EnemySpaceship::InstantiateReward()
    {
        if (m_rewardFunctions.empty()) return;

        int randomReward = (int)RandomFloat(0, m_rewardFunctions.size());

        if (randomReward >= 0 && randomReward < m_rewardFunctions.size())
        {
           Weak<PlayerRewards> playerReward = m_rewardFunctions[randomReward](GetWorld());
           playerReward.lock()->SetActorLocation(GetActorLocation());
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

    void EnemySpaceship::OnDeath()
    {
        InstantiateReward();
    }
}
