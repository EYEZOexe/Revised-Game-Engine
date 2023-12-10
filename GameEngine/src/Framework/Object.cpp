//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "Framework/Object.h"
#include "Framework/Core.h"

namespace labyrinth_engine
{
    Object::Object()
        : m_bIsPendingKill(false)
    {
    }

    Object::~Object()
    {
        GE_LOG("Object Destroyed");
    }

    void Object::ObjectDestroy()
    {
        m_bIsPendingKill = true;
    }
}
