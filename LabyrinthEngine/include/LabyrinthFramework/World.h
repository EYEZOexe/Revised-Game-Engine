//
// Created by Tomas Tzorta on 07/12/2023.
//

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <SDL2/SDL.h>
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
        void Render(SDL_Window& a_window);

        virtual ~World(); //whenever you need something to be inherited you have a virtual destructor to make sure that the destructor of the child class is called first and then the destructor of the parent class is called

        template<typename a_ActorType, typename... arguments>
        Weak<a_ActorType> SpawnActor(arguments... a_args);

        template<typename HUDType, typename... arguments>
        Weak<HUDType> SpawnHUD(arguments... a_args);

        sf::Vector2u GetWindowSize() const;

        void Clear();
        void AddGameStage(const Shared<GameStage>& a_gameStage);

        bool ExecuteEvent(const SDL_Event& a_event);

    private:
        virtual void BeginPlay();
        virtual void WorldTick(float a_deltaTime);
        void RenderHUD(sf::RenderWindow& a_window);
        Application* m_owningApplication;
        bool m_bIsPlaying;

        List<Shared<Actor>> m_actors;
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
    Weak<a_ActorType> World::SpawnActor(arguments... a_args)
    {
        Shared<a_ActorType> newActor{new a_ActorType(this, a_args...)};
        m_actorsToAdd.push_back(newActor);
        return newActor;
    }

    template<typename HUDType, typename ... arguments>
    Weak<HUDType> World::SpawnHUD(arguments... a_args)
    {
        Shared<HUDType> newHUD{new HUDType(a_args...)};
        m_HUD = newHUD;
        return newHUD;
    }
}



#endif //WORLD_H
