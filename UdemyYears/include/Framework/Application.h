//
// Created by NAT20 on 07/12/2023. By holding CTRL + K -> O you switch between .h and .cpp files.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

namespace Framework
{
    class Application
    {
    public:
        Application();
        void Run();

    private:
        sf::RenderWindow m_window;
    };
}

#endif //APPLICATION_H
