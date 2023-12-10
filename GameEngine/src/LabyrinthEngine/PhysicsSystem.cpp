//
// Created by Tomas Tzorta on 10/12/2023.
//

#include "LabyrinthEngine/PhysicsSystem.h"

namespace labyrinth_engine
{
    Uptr<PhysicsSystem> PhysicsSystem::physicsSystem{nullptr};

    PhysicsSystem& PhysicsSystem::GetInstance()
    {
        if (!physicsSystem)
        {
            physicsSystem = std::move(Uptr<PhysicsSystem>{new PhysicsSystem});

        }

        return *physicsSystem;
    }

    PhysicsSystem::PhysicsSystem()
        : m_physicsWorld{b2Vec2{0.0f, 0.0f}} //gravity
        , m_physicsScale{0.01f} //1 meter = 100 pixels
    {

    }
}
