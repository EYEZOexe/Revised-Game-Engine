//
// Created by NAT20 on 07/12/2023.
//

#include "Framework/Application.h"
#include <stdio.h>


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
                TickFramework(targetDeltaTime);
                RenderFramework();
            }
            printf("ticking at framerate: %f\n" , 1.0f / targetDeltaTime);
        }
    }

    void Application::TickFramework(float a_deltaTime)
    {
        Tick(a_deltaTime);
    }

    void Application::RenderFramework()
    {
        m_window.clear();

        Render();

        m_window.display();
    }

    void Application::Render()
    {
        sf::RectangleShape rect{sf::Vector2f{100, 100}};
        rect.setFillColor(sf::Color::Green);
        rect.setOrigin(50,50);
        rect.setPosition(m_window.getSize().x/2.0f, m_window.getSize().y/2.0f);

        m_window.draw(rect);
    }

    void Application::Tick(float a_deltaTime)
    {

    }
}
