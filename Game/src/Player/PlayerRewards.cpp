//
// Created by Tomas Tzorta on 18/12/2023.
//

#include "Player/PlayerRewards.h"
#include "Player/PlayerSpaceship.h"
#include "Weapon/TripleTroubleProjectileLauncher.h"
#include "Weapon/MoonProjectileLauncher.h"
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
            AudioManager::GetInstance().PlaySFX("PowerUp");
            m_rewardFunction(playerSpaceship.lock().get());
            Destroy();
        }


    }

    Weak<PlayerRewards> CreateHealthReward(World* a_world)
    {
        return CreateReward(a_world, "ss/Item/PowerUp5.png", AddHealthReward);
    }

    Weak<PlayerRewards> CreateTripleTroubleShooterReward(World* a_world)
    {
        return CreateReward(a_world, "ss/Item/1.png", AddTripleTroubleShooterReward);
    }

    Weak<PlayerRewards> CreateMoonShooterReward(World* a_world)
    {
        return CreateReward(a_world, "ss/Shoot/9.png", AddMoonShooterReward);
    }

    Weak<PlayerRewards> CreateLifeReward(World* a_world)
    {
        return CreateReward(a_world, "ss/HUD/LifeIcon.png", AddLifeReward);
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

    void AddTripleTroubleShooterReward(PlayerSpaceship* a_playerSpaceship)
    {
        if (a_playerSpaceship && !a_playerSpaceship->IsPendingKill())
        {
            a_playerSpaceship->SetProjectileLauncher(Unique<ProjectileLauncher>{new TripleTroubleProjectileLauncher{a_playerSpaceship, 0.4, {50.0f, 0.0f}}});
        }
    }

    void AddMoonShooterReward(PlayerSpaceship* a_playerSpaceship)
    {
        if (a_playerSpaceship && !a_playerSpaceship->IsPendingKill())
        {
            a_playerSpaceship->SetProjectileLauncher(Unique<ProjectileLauncher>{new MoonProjectileLauncher{a_playerSpaceship, 0.4, {50.0f, 0.0f}}});
        }
    }

    void AddLifeReward(PlayerSpaceship* a_playerSpaceship)
    {
        if (!PlayerManager::GetInstance().GetPlayer()) return;

        PlayerManager::GetInstance().GetPlayer()->IncreasePlayerLives(1);
    }
}
