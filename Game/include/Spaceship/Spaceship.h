//
// Created by NAT20 on 09/12/2023.
//

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Framework/Actor.h"
#include "Framework/World.h"

namespace GameFramework
{
    class Spaceship : public Framework::Actor
    {
    public:
        Spaceship(Framework::World* a_owningWorld, const std::string& a_texturePath = "");
        void ActorTick(float a_deltaTime) override;

        void SetVelocity(const sf::Vector2f& a_velocity) { m_velocity = a_velocity; }
        sf::Vector2f GetVelocity() const { return m_velocity; }

        virtual void Fire();
    private:
        sf::Vector2f m_velocity;
    };

}

#endif //SPACESHIP_H
