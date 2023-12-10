//
// Created by NAT20 on 07/12/2023. By holding CTRL + K -> O you switch between .h and .cpp files.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <Framework/Core.h>

#include "World.h"

namespace labyrinth_engine
{
    class World;

    class Application
    {
    public:
        Application(unsigned int a_windowWidth, unsigned int a_windowHeight, const std::string& a_windowTitle, sf::Uint32 a_windowStyle);
        void Run();

        // Weak Pointers are a type of smart pointer that provides a non-owning "weak" reference to an object that's managed by another shared pointer.
        template<typename a_worldType>
        Wptr<a_worldType> LoadWorld(); // Templates are defined in the header file

        sf::Vector2u GetWindowSize() const { return m_window.getSize(); }


    private:
        void TickFramework(float a_deltaTime);
        void RenderFramework();

        virtual void Render();
        virtual void Tick(float a_deltaTime);

        sf::RenderWindow m_window;
        float m_targetFrameRate;
        sf::Clock m_tick;

        // Shared Pointers are a type of smart pointer that automatically manages the lifetime of an object and its memory.
        Sptr<World> m_currentWorld;
        sf::Clock m_ClearTimer;
        float m_ClearTimeInterval;
    };

    // Template Implementations
    template<typename a_worldType>
    Wptr<a_worldType> Application::LoadWorld()
    {
        Sptr<a_worldType> newWorld{new a_worldType(this)};
        m_currentWorld = newWorld;
        m_currentWorld->BeginPlayFramework();
        return newWorld;
    }

}

#endif //APPLICATION_H
