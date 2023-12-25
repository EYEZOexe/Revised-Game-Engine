//
// Created by Tomas Tzorta on 07/12/2023.
//

#ifndef OBJECT_H
#define OBJECT_H

#include <memory>

#include "Core.h"
#include "LabyrinthFramework/EventCallback.h"

namespace labyrinth_engine
{
    class Object : public std::enable_shared_from_this<Object> //weak from this
    {
    public:
        Object();
        virtual ~Object();

        virtual void Destroy();
        bool IsPendingKill() const {return m_bIsPendingKill;}

        Weak<Object> GetWeakReference();
        Weak<const Object> GetWeakReference() const;
        EventCallback<Object*> OnDestroy;
        unsigned int GetObjectID() const {return m_objectID;}

    private:
        bool m_bIsPendingKill;
        unsigned int m_objectID;

        static unsigned int s_objectIDCount;
        static unsigned int GetAvailableObjectID();
    };
}



#endif //OBJECT_H
