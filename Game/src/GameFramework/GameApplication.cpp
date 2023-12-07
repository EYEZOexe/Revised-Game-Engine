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
    {
        const Framework::Wptr<Framework::World> newWorld = LoadWorld<Framework::World>();
        newWorld.lock()->SpawnActor<Framework::Actor>();
    }
}
