//
// Created by Tomas Tzorta on 18/12/2023.
//

#include "Player/PlayerRewards.h"
#include "Player/PlayerSpaceship.h"

namespace labyrinth_engine
{
    PlayerRewards::PlayerRewards(World* a_world, const std::string& a_rewardTexturePath, RewardFunction a_rewardFunction, float a_rewardSpeed)
        : Actor{a_world, a_rewardTexturePath}
        , m_rewardFunction{a_rewardFunction}
        , m_rewardSpeed{a_rewardSpeed}
    {
    }

    void PlayerRewards::ActorBeginPlay()
    {
        Actor::ActorBeginPlay();
        SetEnableActorPhysics(true);
    }

    void PlayerRewards::ActorTick(float a_deltaTime)
    {
        Actor::ActorTick(a_deltaTime);
        AddActorLocationOffset({0.0f, m_rewardSpeed * a_deltaTime});
    }

    void PlayerRewards::OnActorBeginOverlap(Actor* m_actor)
    {
        PlayerSpaceship* playerSpaceship = static_cast<PlayerSpaceship*>(m_actor);

        if (playerSpaceship != nullptr && !playerSpaceship->IsPendingKill())
        {
            m_rewardFunction(playerSpaceship);
        }
    }
}
