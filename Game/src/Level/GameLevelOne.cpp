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
#include "Player/PlayerSpaceship.h"


namespace labyrinth_engine
{
    GameLevelOne::GameLevelOne(Application* a_application)
        : World{a_application}
    {
        testPlayerSpaceship = SpawnActor<PlayerSpaceship>();
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.0f, 490.0f));
    }

    void GameLevelOne::BeginPlay()
    {

    }

    void GameLevelOne::InitialiseGameStages()
    {
        AddGameStage(Shared<WaitStage>{new WaitStage{this, 5.0f}});
        AddGameStage(Shared<VanguardGameStage>{new VanguardGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 15.0f}});
        AddGameStage(Shared<TwinBladeGameStage>{new TwinBladeGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 15.0f}});
        AddGameStage(Shared<HexagonGameStage>{new HexagonGameStage{this}});

        AddGameStage(Shared<WaitStage>{new WaitStage{this, 15.0f}});
        AddGameStage(Shared<UFOGameStage>{new UFOGameStage{this}});
    }
}
