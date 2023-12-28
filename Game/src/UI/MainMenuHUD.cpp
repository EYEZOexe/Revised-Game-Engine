//
// Created by Tomas Tzorta on 28/12/2023.
//

#include "UI/MainMenuHUD.h"

namespace labyrinth_engine
{
    MainMenuHUD::MainMenuHUD()
        : m_mainMenuTitleText{"Arcade Shooter"} // initialize main menu text
        , m_mainMenuPlayButton{"Play"} // initialize main menu play button
        , m_mainMenuQuitButton{"Quit"} // initialize main menu quit button
    {
        m_mainMenuTitleText.SetWidgetTextSize(40); // set main menu text size
        m_mainMenuPlayButton.SetButtonTextSize(20); // set main menu play button text size
        m_mainMenuQuitButton.SetButtonTextSize(20); // set main menu quit button text size
    }

    void MainMenuHUD::HUDInit(const sf::RenderWindow& a_window)
    {
        sf::Vector2u windowSize = a_window.getSize(); // get window size
        m_mainMenuTitleText.SetWidgetPosition({windowSize.x / 2.0f - m_mainMenuTitleText.GetWidgetBounds().width /2, 100.0f}); // set main menu text position
        m_mainMenuPlayButton.SetWidgetPosition({windowSize.x / 2.0f - m_mainMenuPlayButton.GetWidgetBounds().width /2, windowSize.y / 2.0f}); // set main menu play button position
        m_mainMenuQuitButton.SetWidgetPosition(m_mainMenuPlayButton.GetWidgetPosition() + sf::Vector2f{0.0f, 50.0f}); // set main menu quit button position
        m_mainMenuPlayButton.OnButtonPressed.Bind(GetWeakReference(), &MainMenuHUD::PlayButtonPressed); // bind play button pressed event
        m_mainMenuQuitButton.OnButtonPressed.Bind(GetWeakReference(), &MainMenuHUD::QuitButtonPressed); // bind quit button pressed event
    }

    void MainMenuHUD::DrawHUD(sf::RenderWindow& a_window)
    {
        m_mainMenuTitleText.FrameworkWidgetDraw(a_window); // draw main menu text
        m_mainMenuPlayButton.FrameworkWidgetDraw(a_window); // draw main menu play button
        m_mainMenuQuitButton.FrameworkWidgetDraw(a_window); // draw main menu quit button
    }

    bool MainMenuHUD::IsHUDClicked(const sf::Event& a_event)
    {
        return m_mainMenuPlayButton.IsMouseOver(a_event) || m_mainMenuQuitButton.IsMouseOver(a_event) || HUD::IsHUDClicked(a_event); // check if HUD is clicked
    }

    void MainMenuHUD::PlayButtonPressed()
    {
        OnPlayButtonPressed.Broadcast(); // broadcast play button pressed event
    }

    void MainMenuHUD::QuitButtonPressed()
    {
        OnQuitButtonPressed.Broadcast(); // broadcast quit button pressed event
    }
}
