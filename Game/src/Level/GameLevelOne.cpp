//
// Created by s5216712 on 11/12/2023.
//

#include "Level/GameLevelOne.h"

#include "Enemy/RookieGameStage.h"
#include "Enemy/CopyCatGameStage.h"
#include "Enemy/EnforcerGameStage.h"
#include "Enemy/DancerGameStage.h"
#include "Gameplay/WaitStage.h"
#include "Enemy/MadMaxGameStage.h"

#include "LabyrinthFramework/Actor.h"
#include "..\..\..\LabyrinthEngine\include\LabyrinthFramework\TimeKeeper.h"
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
        m_GameHUD = InstantiateHUD<GameHUD>();
        AudioManager& audioManager = AudioManager::GetInstance();
        audioManager.LoadSFX("Shoot", "Bonus/blaster.mp3");
    }

    void GameLevelOne::InitialiseGameStages()
    {
        AddGameStage(Shared<DancerGameStage>{new DancerGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 2.0f}});
        AddGameStage(Shared<RookieGameStage>{new RookieGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 5.0f}});
        AddGameStage(Shared<CopyCatGameStage>{new CopyCatGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 8.0f}});
        AddGameStage(Shared<EnforcerGameStage>{new EnforcerGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 11.0f}});
        AddGameStage(Shared<DancerGameStage>{new DancerGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 15.0f}});
        AddGameStage(Shared<MadMaxGameStage>{new MadMaxGameStage{this}});
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
