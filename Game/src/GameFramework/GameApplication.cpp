//
// Created by NAT20 on 07/12/2023.
//

#include "GameFramework/GameApplication.h"
#include "Framework/World.h"

Framework::Application* GetApplication()
{
    return new GameFramework::GameApplication();
}

namespace GameFramework
{
    GameApplication::GameApplication()
    {
        LoadWorld<Framework::World>();
    }
}
