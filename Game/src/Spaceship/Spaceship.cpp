//
// Created by Tomas Tzorta on 09/12/2023.
//

#include "Spaceship/Spaceship.h"

namespace labyrinth_engine
{
    Spaceship::Spaceship(World* a_owningWorld, const std::string& a_texturePath)
        : Actor(a_owningWorld, a_texturePath)
        , m_velocity{}
        , m_healthComponent(100.0f, 100.0f)
    {

    }

    void Spaceship::ActorTick(const float a_deltaTime)
    {
        Actor::ActorTick(a_deltaTime);
        AddActorLocationOffset(GetVelocity() * a_deltaTime);
    }

    void Spaceship::Fire()
    {

    }

    void Spaceship::ActorBeginPlay()
    {
        Actor::ActorBeginPlay();
        SetEnableActorPhysics(true);
    }
}
