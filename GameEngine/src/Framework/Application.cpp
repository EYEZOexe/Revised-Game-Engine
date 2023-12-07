//
// Created by NAT20 on 07/12/2023.
//

#include "Framework/Application.h"
#include "Framework/Core.h"
#include "Framework/World.h"
#include "Framework/AssetManager.h"


namespace Framework
{
    Application::Application(unsigned a_windowWidth, unsigned a_windowHeight, const std::string& a_windowTitle, sf::Uint32 a_windowStyle)
        : m_window(sf::VideoMode(a_windowWidth, a_windowHeight), a_windowTitle, a_windowStyle)
        , m_targetFrameRate(60)
        , m_tick{}
        , m_currentWorld(nullptr)
        , m_ClearTimer{}
        , m_ClearTimeInterval(2.0f)
    {

    }

    void Application::Run()
    {
        m_tick.restart();

        float timePassed = 0.0f;
        const float targetDeltaTime = 1.0f / m_targetFrameRate;

        while (m_window.isOpen())
        {
            sf::Event windowEvent{};
            while (m_window.pollEvent(windowEvent))
            {
                if (windowEvent.type == sf::Event::EventType::Closed)
                {
                    m_window.close();
                }
            }
            const float frameDeltaTime = m_tick.restart().asSeconds();
            timePassed += frameDeltaTime;
            while (timePassed > targetDeltaTime)
            {
                timePassed -= targetDeltaTime;
                TickFramework(targetDeltaTime);
                RenderFramework();
            }
        }
    }

    void Application::TickFramework(float a_deltaTime)
    {

        Tick(a_deltaTime);

        if (m_currentWorld != nullptr)
        {
            m_currentWorld->WorldTickFramework(a_deltaTime);
        }

        if (m_ClearTimer.getElapsedTime().asSeconds() >= m_ClearTimeInterval)
        {
            m_ClearTimer.restart();
            AssetManager::Get().Clear();
        }
    }

    void Application::RenderFramework()
    {
        m_window.clear();

        Render();

        m_window.display();
    }

    void Application::Render()
    {
        if (m_currentWorld != nullptr)
        {
            m_currentWorld->Render(m_window);
        }
    }

    void Application::Tick(float a_deltaTime)
    {

    }
}
