//
// Created by Tomas Tzorta on 28/12/2023.
//

#include "Level/MainMenu.h"

#include "LabyrinthFramework/Application.h"
#include "Level/GameLevelOne.h"
#include "UI/MainMenuHUD.h"

namespace labyrinth_engine
{
    MainMenu::MainMenu(Application* a_application)
        : World{a_application}
    {
        m_mainMenuHUD = InstantiateHUD<MainMenuHUD>();
    }

    void MainMenu::BeginPlay()
    {
        m_mainMenuHUD.lock()->OnPlayButtonPressed.Bind(GetWeakReference(), &MainMenu::StartGame);
        m_mainMenuHUD.lock()->OnQuitButtonPressed.Bind(GetWeakReference(), &MainMenu::QuitGame);
    }

    void MainMenu::StartGame()
    {
        GetOwningApplication()->LoadWorld<GameLevelOne>();
    }

    void MainMenu::QuitGame()
    {
        GetOwningApplication()->QuitGame();
    }
}
