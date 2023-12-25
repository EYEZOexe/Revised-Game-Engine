//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "LabyrinthFramework/Object.h"
#include "LabyrinthFramework/Core.h"

namespace labyrinth_engine
{
    unsigned int Object::s_objectIDCount = 0;

    Object::Object()
        : m_bIsPendingKill{false}
        , m_objectID{GetAvailableObjectID()}
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

    unsigned int Object::GetAvailableObjectID()
    {
        return s_objectIDCount++;
    }
}
