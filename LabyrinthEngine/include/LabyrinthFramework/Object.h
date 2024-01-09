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

        virtual void Destroy(); // destroy the object
        bool IsPendingKill() const {return m_bIsPendingKill;} // check if the object is pending kill

        Weak<Object> GetWeakReference(); // get a weak reference to the object
        Weak<const Object> GetWeakReference() const; // get a weak reference to the object
        EventCallback<Object*> OnDestroy; // event callback for when the object is destroyed
        unsigned int GetObjectID() const {return m_objectID;} // get the object ID

    private:
        bool m_bIsPendingKill; // is the object pending kill
        unsigned int m_objectID; // object ID
        static unsigned int s_objectIDCount; // object ID count
        static unsigned int GetAvailableObjectID(); // get an available object ID
    };
}



#endif //OBJECT_H
