//
// Created by Tomas Tzorta on 10/12/2023.
//


#include <box2d/b2_body.h>
#include <box2d/b2_contact.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>

#include "LabyrinthEngine/Actor.h"
#include "LabyrinthEngine/PhysicsSystem.h"
#include "LabyrinthEngine/MathUtility.h"

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

    void PhysicsSystem::Update(float a_deltaTime)
    {
        CalculateListenersToRemove(); //calculate listeners to remove
        m_physicsWorld.Step(a_deltaTime, m_velocityIterations, m_positionIterations); //update physics world
    }

    b2Body* PhysicsSystem::AddListener(Actor* a_actor)
    {
        if (a_actor->IsPendingKill()) return nullptr;

        b2BodyDef bodyDefinition; //body definition
        bodyDefinition.type = b2_dynamicBody; //dynamic body
        bodyDefinition.userData.pointer = reinterpret_cast<uintptr_t>(a_actor); //pointer to actor

        bodyDefinition.position.Set(a_actor->GetActorLocation().x * GetPhysicsScale(), a_actor->GetActorLocation().y * GetPhysicsScale()); //set position
        bodyDefinition.angle = DegreesToradians(a_actor->GetActorRotation()); //set rotation

        b2Body* body = m_physicsWorld.CreateBody(&bodyDefinition); //create body

        b2PolygonShape shape; //shape definition
        const auto bounds = a_actor->GetActorBounds(); //get bounds
        shape.SetAsBox(bounds.width * GetPhysicsScale() / 2.0f, bounds.height * GetPhysicsScale() / 2.0f); //set shape

        b2FixtureDef fixtureDefinition; //fixture definition
        fixtureDefinition.shape = &shape; //set shape
        fixtureDefinition.density = 1.0f; //set density
        fixtureDefinition.friction = 0.3f; //set friction
        fixtureDefinition.isSensor = true; //set sensor

        body->CreateFixture(&fixtureDefinition); //create fixture

        return body;
    }

    void PhysicsSystem::RemoveListener(b2Body* a_body)
    {
        m_listenersToRemove.insert(a_body);
    }

    void PhysicsSystem::Clear()
    {
        physicsSystem = std::move(Uptr<PhysicsSystem>{new PhysicsSystem});
    }

    PhysicsSystem::PhysicsSystem()
        : m_physicsWorld{b2Vec2{0.0f, 0.0f}} //gravity
        , m_physicsScale{0.01f} //1 meter = 100 pixels
        , m_velocityIterations{8}
        , m_positionIterations{3}
        , m_contactListner{}
        , m_listenersToRemove{}
    {
        m_physicsWorld.SetContactListener(&m_contactListner);
        m_physicsWorld.SetAllowSleeping(false);
    }

    void PhysicsSystem::CalculateListenersToRemove()
    {
        for (auto listener : m_listenersToRemove)
        {
            m_physicsWorld.DestroyBody(listener);
        }

        m_listenersToRemove.clear();
    }

    void PhysicsContactListner::BeginContact(b2Contact* contact)
    {
        auto actorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
        auto actorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

        if (actorA && !actorA->IsPendingKill())
        {
            actorA->OnActorBeginOverlap(actorB);
        }

        if (actorB && !actorB->IsPendingKill())
        {
            actorB->OnActorBeginOverlap(actorA);
        }
    }

    void PhysicsContactListner::EndContact(b2Contact* contact)
    {
        Actor* actorA = nullptr;
        Actor* actorB = nullptr;

        if (contact->GetFixtureA() && contact->GetFixtureA()->GetBody())
        {
            actorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
        }

        if (contact->GetFixtureB() && contact->GetFixtureB()->GetBody())
        {
            actorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
        }

        if (actorA && !actorA->IsPendingKill())
        {
            actorA->OnActorEndOverlap(actorB);
        }

        if (actorB && !actorB->IsPendingKill())
        {
            actorB->OnActorEndOverlap(actorA);
        }
    }
}
