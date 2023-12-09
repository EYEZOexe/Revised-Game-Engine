//
// Created by NAT20 on 07/12/2023.
//

#include "GameFramework/GameApplication.h"
#include "Framework/World.h"
#include "Framework/Actor.h"
#include "Spaceship/Spaceship.h"
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
        const Framework::Wptr<Framework::World> newWorld = LoadWorld<Framework::World>();
        newWorld.lock()->SpawnActor<Framework::Actor>();
        testPlayerSpaceship = newWorld.lock()->SpawnActor<Spaceship>();
        testPlayerSpaceship.lock()->SetActorTexture(GetAssetDirectory() + "PNG/playerShip1_blue.png");
        testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.0f, 490.0f));
        testPlayerSpaceship.lock()->SetVelocity(sf::Vector2f(0.0f, -200.0f));
        m_counter = 0.0f;
    }

    void GameApplication::Tick(const float a_deltaTime)
    {
        m_counter += a_deltaTime;
        if (m_counter > 2.0f)
        {
            if (!testPlayerSpaceship.expired())
            {
                testPlayerSpaceship.lock()->ObjectDestroy();
            }
        }
    }
}
