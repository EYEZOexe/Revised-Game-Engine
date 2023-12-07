//
// Created by NAT20 on 07/12/2023.
//

#include "Framework/Application.h"


namespace Framework
{
    Application::Application() : m_window{sf::VideoMode(600,800), "My Game"}
    {

    }

    void Application::Run()
    {
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
        }
    }
}
