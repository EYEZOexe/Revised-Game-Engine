//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "LabyrinthEngine/Object.h"
#include "LabyrinthEngine/Core.h"

namespace labyrinth_engine
{
    Object::Object()
        : m_bIsPendingKill(false)
    {
    }

    Object::~Object()
    {
        LE_LOG("Object Destroyed");
    }

    void Object::Destroy()
    {
        m_bIsPendingKill = true;
    }
}
