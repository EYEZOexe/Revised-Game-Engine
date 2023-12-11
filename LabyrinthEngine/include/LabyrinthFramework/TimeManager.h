//
// Created by Tomas Tzorta on 11/12/2023.
//

#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "Core.h"
#include "Object.h"

namespace labyrinth_engine
{
    class TimeManager
    {
    public:
        /* Constructors and Destructors */
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        template <typename ClassName>
        void SetTimer(Wptr<Object> a_weakObject, void (ClassName::*a_function)(), float a_time, bool a_repeat)
        {

        }

        // Getters
        static TimeManager& GetInstance();

        /* End of Setters and getters */

    protected:
        TimeManager();

    private:
        static Uptr<TimeManager> m_timeManager;
    };
}


#endif //TIMEMANAGER_H
