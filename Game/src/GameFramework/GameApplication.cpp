//
// Created by NAT20 on 07/12/2023.
//

#include "GameFramework/GameApplication.h"
#include "Framework/World.h"
#include "Framework/Actor.h"
#include "Framework/AssetManager.h"
#include "Player/PlayerSpaceship.h"
#include "config.h"


Framework::Application* GetApplication()
{
    return new GameFramework::GameApplication();
}

namespace GameFramework
{
    GameApplication::GameApplication()
        : Application{600, 900, "Game", sf::Style::Titlebar | sf::Style::Close}
    {
        Framework::AssetManager::Get().SetAssetDirectory(GetAssetDirectory());
        const Framework::Wptr<Framework::World> newWorld = LoadWorld<Framework::World>();
        newWorld.lock()->SpawnActor<Framework::Actor>();
        testPlayerSpaceship = newWorld.lock()->SpawnActor<PlayerSpaceship>();
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.0f, 490.0f));
    }

    void GameApplication::Tick(const float a_deltaTime)
    {

    }
}
