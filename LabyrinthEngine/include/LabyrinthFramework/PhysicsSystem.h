//
// Created by Tomas Tzorta on 10/12/2023.
//

#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <box2d/b2_world.h>

#include "Core.h"


//Physics System is a singleton

namespace labyrinth_engine
{
    class Actor;
}

namespace labyrinth_engine
{
    class PhysicsContactListner : public b2ContactListener
    {
        void BeginContact(b2Contact* contact) override; //begin contact
        void EndContact(b2Contact* contact) override; //end contact
    };

    class PhysicsSystem
    {
    public:
        static PhysicsSystem& GetInstance(); //get instance of physics system
        void Update(float a_deltaTime); //update physics system
        b2Body* AddListener(Actor* a_actor); //add actor to physics world
        void RemoveListener(b2Body* a_body); //remove actor from physics world

        //getters
        float GetPhysicsScale() const { return m_physicsScale; } //get physics scale

        static void Clear();



    protected:
        PhysicsSystem();
    private:
        void CalculateListenersToRemove(); //calculate listeners to remove
        static Unique<PhysicsSystem> physicsSystem; //unique pointer to physics system
        b2World m_physicsWorld;
        float m_physicsScale;
        int m_velocityIterations;
        int m_positionIterations;

        PhysicsContactListner m_contactListner;

        Set<b2Body*> m_listenersToRemove;

    };
}



#endif //PHYSICSSYSTEM_H
