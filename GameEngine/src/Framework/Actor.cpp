//
// Created by NAT20 on 07/12/2023.
//

#include "Framework/Actor.h"
#include "Framework/Core.h"

namespace Framework
{
    Actor::Actor(World* a_owningWorld)
        : m_owningWorld(a_owningWorld)
        , m_bIsPlaying(false)
    {
    }

    Actor::~Actor()
    {

    }

    void Actor::ActorBeginPlayFramework()
    {
        if (!m_bIsPlaying)
        {
            m_bIsPlaying = true;
            ActorBeginPlay();
        }
    }

    void Actor::ActorBeginPlay()
    {
        GE_LOG("Actor Begin Play");
    }

    void Actor::ActorTick(float a_deltaTime)
    {
        GE_LOG("Actor Tick");
    }
}
