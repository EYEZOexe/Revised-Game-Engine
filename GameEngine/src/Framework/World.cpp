//
// Created by NAT20 on 07/12/2023.
//

#include "Framework/World.h"
#include "Framework/Core.h"

namespace Framework
{
    World::World(Application* a_owningApplication)
        : m_owningApplication(a_owningApplication)
        , m_bIsPlaying(false)
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

    void World::WorldTickFramework(float a_deltaTime)
    {
        WorldTick(a_deltaTime);
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
        GE_LOG("Tick at frame rate %f", 1.0f / a_deltaTime);
    }
}
