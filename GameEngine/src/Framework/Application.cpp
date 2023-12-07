//
// Created by NAT20 on 07/12/2023.
//

#include "Framework/Application.h"
#include "Framework/Core.h"
#include "Framework/World.h"


namespace Framework
{
    Application::Application()
        : m_window{sf::VideoMode(600,800), "My Game"}
        , m_targetFrameRate{60.0f}
        , m_currentWorld(nullptr)
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

            //GE_LOG("Ticking at framerate: %f", 1.0f / frameDeltaTime);
        }
    }

    void Application::TickFramework(float a_deltaTime)
    {

        Tick(a_deltaTime);

        if (m_currentWorld != nullptr)
        {
            m_currentWorld->WorldTickFramework(a_deltaTime);
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
