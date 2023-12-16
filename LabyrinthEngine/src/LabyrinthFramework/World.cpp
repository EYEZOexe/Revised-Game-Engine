//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "LabyrinthFramework/World.h"
#include "LabyrinthFramework/Core.h"
#include "LabyrinthFramework/Actor.h"
#include "LabyrinthFramework/Application.h"
#include "Gameplay/GameStage.h"

namespace labyrinth_engine
{
    World::World(Application* a_owningApplication)
        : m_owningApplication(a_owningApplication)
        , m_bIsPlaying(false)
        , m_actors{}
        , m_actorsToAdd{}
        , m_currentGameStageIndex{-1} //set the current game stage index to -1
        , m_gameStages{}
    {

    }

    void World::BeginPlayFramework()
    {
        if (!m_bIsPlaying)
        {
            m_bIsPlaying = true;
            BeginPlay();
            InitialiseGameStages();
            NextGameStage();
        }
    }

    void World::WorldTickFramework(const float a_deltaTime)
    {
        for (const Shared<Actor>& a_actor : m_actorsToAdd)
        {
            m_actors.push_back(a_actor);
            a_actor->ActorBeginPlayFramework();
        }

        m_actorsToAdd.clear();

        for (auto i = m_actors.begin(); i != m_actors.end();) // we use iterator cause we are deleting from the vector
        {
            i->get()->ActorTickFramework(a_deltaTime);
            ++i;
        }

        if (m_currentGameStageIndex >= 0 && m_currentGameStageIndex < m_gameStages.size())
        {
            m_gameStages[m_currentGameStageIndex]->UpdateStage(a_deltaTime);
        }

        WorldTick(a_deltaTime);
    }

    void World::Render(sf::RenderWindow& a_window)
    {
        for (const auto& actor : m_actors)
        {
            actor->Render(a_window);
        }
    }

    World::~World()
    {

    }

    sf::Vector2u World::GetWindowSize() const
    {
        return m_owningApplication->GetWindowSize();
    }

    void World::Clear()
    {
        //this ensures that we can remove actors without breaking the loop
        for (auto i = m_actors.begin(); i != m_actors.end();)
        {
            if (i->get()->IsPendingKill())
            {
                i = m_actors.erase(i);
            }
            else
            {
                ++i;
            }
        }

        //this ensures that we can remove game stages without breaking the loop
        for (auto i = m_gameStages.begin(); i != m_gameStages.end();)
        {
            if (i->get()->IsStageFinished())
            {
                i = m_gameStages.erase(i);
            }
            else
            {
                ++i;
            }
        }
    }

    void World::AddGameStage(const Shared<GameStage>& a_gameStage)
    {
        m_gameStages.push_back(a_gameStage);
    }

    void World::BeginPlay()
    {

    }

    void World::WorldTick(float a_deltaTime)
    {

    }

    void World::InitialiseGameStages()
    {

    }

    void World::GameStagesFinished()
    {

    }

    void World::NextGameStage()
    {
        ++m_currentGameStageIndex;

        if (m_currentGameStageIndex >= 0 && m_currentGameStageIndex < m_gameStages.size())
        {
            m_gameStages[m_currentGameStageIndex]->onEndStageEvent.Bind(GetWeakReference(), &World::NextGameStage); //bind the next game stage to the end of the current game stage
            m_gameStages[m_currentGameStageIndex]->StartStage();
        }
        else
        {
            GameStagesFinished();
        }
    }
}
