//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "GameName/GameApplication.h"
#include "LabyrinthEngine/World.h"
#include "LabyrinthEngine/Actor.h"
#include "LabyrinthEngine/AssetManager.h"
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
        testPlayerSpaceship = newWorld.lock()->SpawnActor<PlayerSpaceship>();
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.0f, 490.0f));

        Wptr<Spaceship> testSpaceship = newWorld.lock()->SpawnActor<Spaceship>();
        testSpaceship.lock()->SetActorTexture("PNG/playerShip1_blue.png");
        testSpaceship.lock()->SetActorLocation(sf::Vector2f(100.0f, 50.0f));
        m_counter = 0;
    }

    void GameApplication::Tick(const float a_deltaTime)
    {
        m_counter += a_deltaTime;

        if (m_counter > 10.0f)
        {
            if (!testPlayerSpaceship.expired())
            {
                testPlayerSpaceship.lock()->Destroy();
            }
        }
    }
}
