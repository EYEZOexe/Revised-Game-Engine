//
// Created by Tomas Tzorta on 07/12/2023. By holding CTRL + K -> O you switch between .h and .cpp files.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Core.h"
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
        Weak<a_worldType> LoadWorld(); // Templates are defined in the header file

        sf::Vector2u GetWindowSize() const { return m_window.getSize(); } //Get the size of the window
        sf::RenderWindow& GetWindow() { return m_window; }  //Get the window
        const sf::RenderWindow& GetWindow() const { return m_window; }  //Get the window
        void QuitGame(); //Quit the game

    private:
        bool ExecuteEvent(const sf::Event& a_event); //Execute the event
        void TickFramework(float a_deltaTime); //Tick the framework
        void RenderFramework(); //Render the framework

        virtual void Render(); //Render the game
        virtual void Tick(float a_deltaTime); //Tick the game

        sf::RenderWindow m_window; //The window
        float m_targetFrameRate; //The target frame rate
        sf::Clock m_tick; //The tick

        // Shared Pointers are a type of smart pointer that automatically manages the lifetime of an object and its memory.
        Shared<World> m_currentWorld; //The current world
        Shared<World> m_nextWorld; //The next world

        sf::Clock m_ClearTimer; //The clear timer
        float m_ClearTimeInterval; //The clear time interval
    };

    // Template Implementations
    template<typename a_worldType>
    Weak<a_worldType> Application::LoadWorld()
    {
        Shared<a_worldType> newWorld{new a_worldType{this}}; //Create a new world
        m_nextWorld = newWorld; //Set the next world
        return newWorld; //Return the new world
    }

}

#endif //APPLICATION_H
