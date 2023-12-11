//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "GameName/GameApplication.h"
#include "Level/GameLevelOne.h"
#include "LabyrinthFramework/AssetManager.h"
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
        const Wptr<GameLevelOne> newWorld = LoadWorld<GameLevelOne>();
    }
}
