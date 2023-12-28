//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "LabyrinthFramework/World.h"
#include "LabyrinthFramework/Core.h"
#include "LabyrinthFramework/Actor.h"
#include "LabyrinthFramework/Application.h"
#include "Gameplay/GameStage.h"
#include "UI/HUD.h"

namespace labyrinth_engine
{
    World::World(Application* a_owningApplication)
        : m_owningApplication(a_owningApplication)
        , m_bIsPlaying(false)
        , m_actors{}
        , m_actorsToAdd{}
        , m_gameStages{}
        , m_currentGameStage{m_gameStages.end()}
    {

    }

    void World::BeginPlayFramework()
    {
        if (!m_bIsPlaying)
        {
            m_bIsPlaying = true;
            BeginPlay();
            InitialiseGameStages();
            StartGameStages();
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

        if (m_currentGameStage != m_gameStages.end())
        {
            m_currentGameStage->get()->UpdateStage(a_deltaTime);
        }

        WorldTick(a_deltaTime);

        if (m_HUD)
        {
            if (!m_HUD->IsHUDInitialized())
            {
                m_HUD->HUDInitFramework(m_owningApplication->GetWindow());
            }
           m_HUD->UpdateHUD(a_deltaTime);
        }
    }

    void World::Render(sf::RenderWindow& a_window)
    {
        for (const auto& actor : m_actors)
        {
            actor->Render(a_window);
        }

        RenderHUD(a_window);
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
    }

    void World::AddGameStage(const Shared<GameStage>& a_gameStage)
    {
        m_gameStages.push_back(a_gameStage);
    }

    bool World::ExecuteEvent(const sf::Event& a_event)
    {
        if (m_HUD)
        {
            return m_HUD->IsHUDClicked(a_event);
        }
        return false;
    }

    void World::BeginPlay()
    {

    }

    void World::WorldTick(float a_deltaTime)
    {

    }

    void World::RenderHUD(sf::RenderWindow& a_window)
    {
        if (m_HUD)
        {
            m_HUD->DrawHUD(a_window);
        }
    }

    void World::InitialiseGameStages()
    {

    }

    void World::GameStagesFinished()
    {
        LE_LOG("All game stages finished");
    }

    void World::NextGameStage()
    {

        m_currentGameStage = m_gameStages.erase(m_currentGameStage);
        if (m_currentGameStage != m_gameStages.end())
        {
            m_currentGameStage->get()->StartStage();
            m_currentGameStage->get()->onEndStageEvent.Bind(GetWeakReference(), &World::NextGameStage);
        }
        else
        {
            GameStagesFinished();
        }
    }

    void World::StartGameStages()
    {

        m_currentGameStage = m_gameStages.begin();
        if (m_currentGameStage != m_gameStages.end())
        {
            m_currentGameStage->get()->StartStage();
            m_currentGameStage->get()->onEndStageEvent.Bind(GetWeakReference(), &World::NextGameStage);
        }
    }
}
