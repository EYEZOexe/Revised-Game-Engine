//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "LabyrinthFramework/Application.h"
#include "LabyrinthFramework/Core.h"
#include "LabyrinthFramework/World.h"
#include "LabyrinthFramework/AssetManager.h"
#include "LabyrinthFramework/PhysicsSystem.h"
#include "LabyrinthFramework/TimeManager.h"


namespace labyrinth_engine
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
                else
                {
                    ExecuteEvent(windowEvent);
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

    bool Application::ExecuteEvent(const sf::Event& a_event)
    {
        if (m_currentWorld != nullptr)
        {
            return m_currentWorld->ExecuteEvent(a_event);
        }
    }

    void Application::TickFramework(float a_deltaTime)
    {

        Tick(a_deltaTime);

        if (m_currentWorld != nullptr)
        {
            m_currentWorld->WorldTickFramework(a_deltaTime);
        }

        TimeManager::GetInstance().UpdateTimerManager(a_deltaTime); //Timer Update

        PhysicsSystem::GetInstance().Update(a_deltaTime); //Physics Update

        if (m_ClearTimer.getElapsedTime().asSeconds() >= m_ClearTimeInterval)
        {
            m_ClearTimer.restart();
            AssetManager::GetInstance().Clear();
            if (m_currentWorld)
            {
                m_currentWorld->Clear();
            }
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
