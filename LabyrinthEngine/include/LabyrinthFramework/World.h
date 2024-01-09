//
// Created by Tomas Tzorta on 07/12/2023.
//

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "Core.h"
#include "Object.h"

namespace labyrinth_engine
{
    class Actor;
    class HUD;
    class Application;
    class GameStage;

    class World : public Object
    {
    public:
        explicit World(Application* a_owningApplication);

        void BeginPlayFramework();
        void WorldTickFramework(float a_deltaTime);
        void Render(sf::RenderWindow& a_window);

        virtual ~World(); //whenever you need something to be inherited you have a virtual destructor to make sure that the destructor of the child class is called first and then the destructor of the parent class is called

        template<typename a_ActorType, typename... arguments>
        Weak<a_ActorType> SpawnActor(arguments... a_args); //spawn an actor

        template<typename HUDType, typename... arguments>
        Weak<HUDType> InstantiateHUD(arguments... a_args); //instantiate a HUD

        sf::Vector2u GetWindowSize() const; //get the window size

        void Clear();
        void AddGameStage(const Shared<GameStage>& a_gameStage); //add a game stage

        bool ExecuteEvent(const sf::Event& a_event); //execute an event
        Application* GetOwningApplication() {return m_owningApplication;} //get the owning application
        Application* GetOwningApplication() const {return m_owningApplication;} //get the owning application

    private:
        virtual void BeginPlay(); //begin play
        virtual void WorldTick(float a_deltaTime); //world tick
        void RenderHUD(sf::RenderWindow& a_window); //render the HUD
        Application* m_owningApplication; //the owning application
        bool m_bIsPlaying;

        List<Shared<Actor>> m_actors; //list of actors
        List<Shared<Actor>> m_actorsToAdd; //reason for this is cause we can't add actors to the vector while we are iterating through it
        List<Shared<GameStage>> m_gameStages; //list of game stages
        List<Shared<GameStage>>::iterator m_currentGameStage; //iterator of the current game stage

        Shared<HUD> m_HUD;

        virtual void InitialiseGameStages(); //initialise the game stages
        virtual void GameStagesFinished(); //when all game stages are finished
        void NextGameStage(); //go to the next game stage
        void StartGameStages(); //start the game stages
    };

    //Template Functions
    template<typename a_ActorType, typename... arguments>
    Weak<a_ActorType> World::SpawnActor(arguments... a_args) //spawn an actor
    {
        Shared<a_ActorType> newActor{new a_ActorType(this, a_args...)}; //create a new actor
        m_actorsToAdd.push_back(newActor); //add the actor to the list of actors to add
        return newActor; //return the new actor
    }

    template<typename HUDType, typename ... arguments>
    Weak<HUDType> World::InstantiateHUD(arguments... a_args) //instantiate a HUD
    {
        Shared<HUDType> newHUD{new HUDType(a_args...)}; //create a new HUD
        m_HUD = newHUD; //set the HUD
        return newHUD; //return the new HUD
    }
}



#endif //WORLD_H
