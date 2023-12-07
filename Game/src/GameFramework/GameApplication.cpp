//
// Created by NAT20 on 07/12/2023.
//

#include "GameFramework/GameApplication.h"
#include "Framework/World.h"
#include "Framework/Actor.h"

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
        m_actorToDestroy = newWorld.lock()->SpawnActor<Framework::Actor>();
        m_actorToDestroy.lock()->SetActorTexture("E:/Coding Projects/UdemyYears/Game/assets/PNG/playerShip1_blue.png");
        m_counter = 0.0f;
    }

    void GameApplication::Tick(float a_deltaTime)
    {
        m_counter += a_deltaTime;
        if (m_counter > 2.0f)
        {
            if (!m_actorToDestroy.expired())
            {
                m_actorToDestroy.lock()->ObjectDestroy();
            }
        }
    }
}
