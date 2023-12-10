//
// Created by Tomas Tzorta on 07/12/2023.
//

#ifndef OBJECT_H
#define OBJECT_H

namespace labyrinth_engine
{
    class Object
    {
    public:
        Object();
        virtual ~Object();

        void ObjectDestroy();
        bool IsPendingKill() const {return m_bIsPendingKill;}

    private:
        bool m_bIsPendingKill;
    };
}



#endif //OBJECT_H
