//
// Created by s5216712 on 11/12/2023.
//

#include "Level/GameLevelOne.h"

#include "Enemy/TwinBladeGameStage.h"
#include "LabyrinthFramework/Actor.h"
#include "LabyrinthFramework/TimeManager.h"
#include "GameName/GameApplication.h"
#include "Enemy/Vanguard.h"
#include "Enemy/VanguardGameStage.h"
#include "Enemy/TwinBladeGameStage.h"
#include "Player/PlayerSpaceship.h"
#include "Gameplay/GameStage.h"

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
        AddGameStage(Shared<VanguardGameStage>{new VanguardGameStage{this}});
        AddGameStage(Shared<TwinBladeGameStage>{new TwinBladeGameStage{this}});
    }
}
