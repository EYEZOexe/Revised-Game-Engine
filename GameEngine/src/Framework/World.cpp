//
// Created by NAT20 on 07/12/2023.
//

#include "Framework/World.h"
#include "Framework/Core.h"
#include "Framework/Actor.h"

namespace Framework
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
        for (auto iteration = m_actors.begin(); iteration != m_actors.end();) // we use iterator cause we are deleting from the vector
        {
            if (iteration->get()->IsPendingKill())
            {
                iteration = m_actors.erase(iteration); //iterating differently based on if we are destroying the current actor
            }
            else
            {
                iteration->get()->ActorTickFramework(a_deltaTime);
                ++iteration;
            }
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

    void World::BeginPlay()
    {
        GE_LOG("Begin Play");
    }

    void World::WorldTick(float a_deltaTime)
    {
        GE_LOG("World Tick at frame rate %f", 1.0f / a_deltaTime);
    }
}
