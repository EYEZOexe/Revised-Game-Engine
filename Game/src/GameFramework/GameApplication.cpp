//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "GameFramework/GameApplication.h"
#include "Framework/World.h"
#include "Framework/Actor.h"
#include "Framework/AssetManager.h"
#include "Player/PlayerSpaceship.h"
#include "config.h"

labyrinth_engine::Application* GetApplication()
{
    return new labyrinth_engine::GameApplication();
}


namespace labyrinth_engine
{
    GameApplication::GameApplication()
        : Application{600, 900, "Game", sf::Style::Titlebar | sf::Style::Close}
    {
        AssetManager::Get().SetAssetDirectory(GetAssetDirectory());
        const Wptr<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
        testPlayerSpaceship = newWorld.lock()->SpawnActor<PlayerSpaceship>();
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.0f, 490.0f));
    }

    void GameApplication::Tick(const float a_deltaTime)
    {

    }
}
