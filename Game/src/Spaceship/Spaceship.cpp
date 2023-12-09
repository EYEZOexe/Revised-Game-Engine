//
// Created by NAT20 on 09/12/2023.
//

#include "Spaceship/Spaceship.h"

namespace GameFramework
{
    Spaceship::Spaceship(Framework::World* a_owningWorld, const std::string& a_texturePath)
        : Actor(a_owningWorld, a_texturePath)
        , m_velocity{}
    {

    }

    void Spaceship::ActorTick(float a_deltaTime)
    {
        Actor::ActorTick(a_deltaTime);
        AddActorLocationOffset(GetVelocity() * a_deltaTime);
    }
}