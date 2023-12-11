//
// Created by s5216712 on 11/12/2023.
//

#include "Level/GameLevelOne.h"
#include "LabyrinthFramework/Actor.h"
#include "LabyrinthFramework/TimeManager.h"
#include "GameName/GameApplication.h"
#include "Enemy/Vanguard.h"
#include "Player/PlayerSpaceship.h"

namespace labyrinth_engine
{
    GameLevelOne::GameLevelOne(Application* a_application)
        : World{a_application}
    {
        testPlayerSpaceship = SpawnActor<PlayerSpaceship>();
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.0f, 490.0f));

        Wptr<Vanguard> testSpaceship = SpawnActor<Vanguard>();
        testSpaceship.lock()->SetActorLocation(sf::Vector2f(100.0f, 50.0f));
    }

    void GameLevelOne::BeginPlay()
    {
        TimeManager::GetInstance().SetTimer(GetWeakReference(), &GameLevelOne::TestCallback, 1.0f, true);
    }

    void GameLevelOne::TestCallback()
    {
        LE_LOG("Test Timer Callback");
    }
}
