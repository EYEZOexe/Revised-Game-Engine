//
// Created by s5216712 on 11/12/2023.
//

#include "Level/GameLevelOne.h"

#include "Enemy/VanguardGameStage.h"
#include "Enemy/TwinBladeGameStage.h"
#include "Enemy/HexagonGameStage.h"
#include "Enemy/UFOGameStage.h"
#include "Gameplay/WaitStage.h"

#include "LabyrinthFramework/Actor.h"
#include "LabyrinthFramework/TimeManager.h"
#include "GameName/GameApplication.h"
#include "Player/PlayerManager.h"
#include "Player/PlayerSpaceship.h"
#include "UI/GameHUD.h"


namespace labyrinth_engine
{
    GameLevelOne::GameLevelOne(Application* a_application)
        : World{a_application}
    {

    }

    void GameLevelOne::BeginPlay()
    {
        Player& player = PlayerManager::GetInstance().AddPlayer();
        m_playerSpaceship = player.SpawnPlayerSpaceship(this);
        m_playerSpaceship.lock()->OnActorDestroy.Bind(GetWeakReference(), &GameLevelOne::PlayerSpaceshipDestroyed);
        m_GameHUD = SpawnHUD<GameHUD>();
    }

    void GameLevelOne::InitialiseGameStages()
    {
        AddGameStage(Shared<UFOGameStage>{new UFOGameStage{this}});
        AddGameStage(Shared<VanguardGameStage>{new VanguardGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 15.0f}});
        AddGameStage(Shared<TwinBladeGameStage>{new TwinBladeGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 15.0f}});
        AddGameStage(Shared<HexagonGameStage>{new HexagonGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 15.0f}});
        AddGameStage(Shared<UFOGameStage>{new UFOGameStage{this}});
    }

    void GameLevelOne::PlayerSpaceshipDestroyed(Actor* a_actor)
    {
        m_playerSpaceship = PlayerManager::GetInstance().GetPlayer()->SpawnPlayerSpaceship(this);

        if (!m_playerSpaceship.expired())
        {
            m_playerSpaceship.lock()->OnActorDestroy.Bind(GetWeakReference(), &GameLevelOne::PlayerSpaceshipDestroyed);
        }
        else
        {
            GameOver();
        }

    }

    void GameLevelOne::GameOver()
    {
        LE_LOG("GAME OVER! YOU LOSE!");
    }
}
