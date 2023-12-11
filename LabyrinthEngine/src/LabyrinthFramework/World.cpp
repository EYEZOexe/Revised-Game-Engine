//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "LabyrinthFramework/World.h"
#include "LabyrinthFramework/Core.h"
#include "LabyrinthFramework/Actor.h"
#include "LabyrinthFramework/Application.h"

namespace labyrinth_engine
{
    World::World(Application* a_owningApplication)
        : m_owningApplication(a_owningApplication)
        , m_bIsPlaying(false)
        , m_actors{}
        , m_actorsToAdd{}
    {

    }

    void World::BeginPlayFramework()
    {
        if (!m_bIsPlaying)
        {
            m_bIsPlaying = true;
            BeginPlay();
        }
    }

    void World::WorldTickFramework(const float a_deltaTime)
    {
        for (const Sptr<Actor>& a_actor : m_actorsToAdd)
        {
            m_actors.push_back(a_actor);
            a_actor->ActorBeginPlayFramework();
        }

        m_actorsToAdd.clear();

        //this ensures that we can remove actors without breaking the loop
        for (auto i = m_actors.begin(); i != m_actors.end();) // we use iterator cause we are deleting from the vector
        {
            i->get()->ActorTickFramework(a_deltaTime);
            ++i;
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

    void World::BeginPlay()
    {

    }

    void World::WorldTick(float a_deltaTime)
    {

    }
}
