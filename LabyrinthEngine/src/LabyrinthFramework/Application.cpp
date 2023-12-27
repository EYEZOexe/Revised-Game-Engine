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
    Application::Application(unsigned a_windowWidth, unsigned a_windowHeight, const std::string& a_windowTitle)
        : m_targetFrameRate(60)
        , m_tick{}
        , m_currentWorld(nullptr)
        , m_ClearTimer{}
        , m_ClearTimeInterval(2.0f)
        , m_isApplicationRunning{true}
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            throw std::runtime_error("Failed to initialize SDL2");
        }

        m_SDLWindow = SDL_CreateWindow(a_windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, a_windowWidth, a_windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_REND);

        if (!m_SDLWindow)
        {
            throw std::runtime_error("Failed to create SDL2 window");
        }

        m_SDLContext = SDL_Rend_CreateContext(m_SDLWindow);

        if (!m_SDLContext)
        {
            throw std::runtime_error("Failed to create Rend OpenGL context");
        }
    }

    void Application::Run()
    {
        m_tick.restart();

        float timePassed = 0.0f;
        const float targetDeltaTime = 1.0f / m_targetFrameRate;

        SDL_Event m_SDLWindowEvent{};

        while (m_isApplicationRunning)
        {
            while (SDL_PollEvent(&m_SDLWindowEvent))
            {
                if (m_SDLWindowEvent.type == SDL_QUIT)
                {
                    m_isApplicationRunning = false;
                }
                else
                {
                    ExecuteEvent(m_SDLWindowEvent);
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

    bool Application::ExecuteEvent(const SDL_Event& a_event)
    {
        if (m_currentWorld)
        {
            return m_currentWorld->ExecuteEvent(a_event);
        }
        return false;
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
        SDL_Rend_ClearWindow(m_SDLWindow);

        Render();

        SDL_GL_SwapWindow(m_SDLWindow);
    }

    void Application::Render()
    {
        if (m_currentWorld != nullptr)
        {
            //m_currentWorld->Render(m_window);
        }
    }

    void Application::Tick(float a_deltaTime)
    {

    }
}
