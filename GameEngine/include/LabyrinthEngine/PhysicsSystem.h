//
// Created by Tomas Tzorta on 10/12/2023.
//

#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "Core.h"
#include <box2d/b2_world.h>

//Physics System is a singleton

namespace labyrinth_engine
{
    class PhysicsSystem
    {
    public:
        static PhysicsSystem& GetInstance();

    protected:
        PhysicsSystem();
    private:
        static Uptr<PhysicsSystem> physicsSystem;
        b2World m_physicsWorld;
        float m_physicsScale;
    };
}



#endif //PHYSICSSYSTEM_H
