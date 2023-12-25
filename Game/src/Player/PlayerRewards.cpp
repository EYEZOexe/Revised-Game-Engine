//
// Created by Tomas Tzorta on 18/12/2023.
//

#include "Player/PlayerRewards.h"
#include "Player/PlayerSpaceship.h"
#include "Weapon/ThreeProjectileLauncher.h"
#include "Weapon/WiperProjectileLauncher.h"
#include "LabyrinthFramework/World.h"
#include "Player/PlayerManager.h"

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
        if (!m_actor || m_actor->IsPendingKill()) return;

        if (!PlayerManager::GetInstance().GetPlayer()) return;

        Weak<PlayerSpaceship> playerSpaceship = PlayerManager::GetInstance().GetPlayer()->GetPlayerSpaceship();

        if (playerSpaceship.expired() || playerSpaceship.lock()->IsPendingKill()) return;

        if (playerSpaceship.lock()->GetObjectID() == m_actor->GetObjectID())
        {
            m_rewardFunction(playerSpaceship.lock().get());
            Destroy();
        }



    }

    Weak<PlayerRewards> CreateHealthReward(World* a_world)
    {
        return CreateReward(a_world, "PNG/power-ups/powerupRed_bolt.png", AddHealthReward);
    }

    Weak<PlayerRewards> CreateThreewayShooterReward(World* a_world)
    {
        return CreateReward(a_world, "PNG/power-ups/things_bronze.png", AddThreewayShooterReward);
    }

    Weak<PlayerRewards> CreateWiperShooterReward(World* a_world)
    {
        return CreateReward(a_world, "PNG/power-ups/powerupRed_shield.png", AddWiperShooterReward);
    }

    Weak<PlayerRewards> CreateLifeReward(World* a_world)
    {
        return CreateReward(a_world, "PNG/power-ups/pill_green.png", AddLifeReward);
    }


    Weak<PlayerRewards> CreateReward(World* a_world, const std::string& a_rewardTexturePath, RewardFunction a_rewardFunction)
    {
        Weak<PlayerRewards> reward = a_world->SpawnActor<PlayerRewards>(a_rewardTexturePath, a_rewardFunction);
        return reward;
    }

    void AddHealthReward(PlayerSpaceship* a_playerSpaceship)
    {
        static float healthReward = 10.0f; // static variables will only be initialized once
        if (a_playerSpaceship && !a_playerSpaceship->IsPendingKill())
        {
            a_playerSpaceship->GetHealthComponent().SetHealth(healthReward);
        }
    }

    void AddThreewayShooterReward(PlayerSpaceship* a_playerSpaceship)
    {
        if (a_playerSpaceship && !a_playerSpaceship->IsPendingKill())
        {
            a_playerSpaceship->SetProjectileLauncher(Unique<Launcher>{new ThreeProjectileLauncher{a_playerSpaceship, 0.4, {50.0f, 0.0f}}});
        }
    }

    void AddWiperShooterReward(PlayerSpaceship* a_playerSpaceship)
    {
        if (a_playerSpaceship && !a_playerSpaceship->IsPendingKill())
        {
            a_playerSpaceship->SetProjectileLauncher(Unique<Launcher>{new WiperProjectileLauncher{a_playerSpaceship, 0.4, {50.0f, 0.0f}}});
        }
    }

    void AddLifeReward(PlayerSpaceship* a_playerSpaceship)
    {
        if (!PlayerManager::GetInstance().GetPlayer()) return;

        PlayerManager::GetInstance().GetPlayer()->IncreasePlayerLives(1);
    }
}
