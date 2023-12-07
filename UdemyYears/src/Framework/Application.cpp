//
// Created by NAT20 on 07/12/2023.
//

#include "Framework/Application.h"
#include <iostream>


namespace Framework
{
    Application::Application()
        : m_window{sf::VideoMode(600,800), "My Game"},
        m_targetFrameRate{60.0f}
    {

    }

    void Application::Run()
    {
        m_tick.restart();

        float timePassed = 0.0f;
        float targetDeltaTime = 1.0f / m_targetFrameRate;

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

            timePassed += m_tick.restart().asSeconds();
            while (timePassed > targetDeltaTime)
            {
                timePassed -= targetDeltaTime;
                Tick(targetDeltaTime);
            }
        }
    }

    void Application::Tick(float a_deltaTime)
    {
        std::cout << "Ticking at framerate: " << 1.0f/a_deltaTime << std::endl;
    }

    void Application::Render()
    {
        
    }
}
