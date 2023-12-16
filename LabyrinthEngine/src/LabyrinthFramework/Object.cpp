//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "LabyrinthFramework/Object.h"
#include "LabyrinthFramework/Core.h"

namespace labyrinth_engine
{
    Object::Object()
        : m_bIsPendingKill(false)
    {
    }

    Object::~Object()
    {

    }

    void Object::Destroy()
    {
        OnDestroy.Broadcast(this);
        m_bIsPendingKill = true;
    }

    Weak<Object> Object::GetWeakReference()
    {
        return weak_from_this();
    }

    Weak<const Object> Object::GetWeakReference() const
    {
        return weak_from_this();
    }
}
