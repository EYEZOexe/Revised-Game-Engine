//
// Created by Tomas Tzorta on 11/12/2023.
//

#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "Core.h"
#include "Object.h"
#include <functional>

namespace labyrinth_engine
{
    struct Timer
    {
    public:
        Timer(Weak<Object> a_weakObject, std::function<void()> a_function, float a_time, bool a_repeat);
        void Update(float a_deltaTime);
        bool IsFinished() const;
        void SetToFinish() {m_bIsFinished = true;}
    private:
        std::pair<Weak<Object>, std::function<void()>> m_function; // pair of weak object and function which is a lambda function
        float m_time;
        bool m_bRepeat;
        float m_currentTime;
        bool m_bIsFinished;
    };

    class TimeManager
    {
    public:
        /* Constructors and Destructors */
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions
        void UpdateTimerManager(float a_deltaTime);
        void RemoveTimer(unsigned int a_index);

        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        template <typename ClassName>
        unsigned int SetTimer(Weak<Object> a_weakObject, void (ClassName::*a_function)(), float a_time, bool a_repeat = false)
        {
            ++m_currentIndex; // set the index to the next one
            m_timers.insert({m_currentIndex, Timer(a_weakObject, [=] {(static_cast<ClassName*>(a_weakObject.lock().get())->*a_function)(); }, a_time, a_repeat) }); // insert the timer in the dictionary and set the index as the key calling the constructor of the timer
            return m_currentIndex; // return the index
        }

        // Getters
        static TimeManager& GetInstance();

        /* End of Setters and getters */

    protected:
        TimeManager();

    private:
        static Unique<TimeManager> m_timeManager; // unique pointer to the time manager
        static unsigned int m_currentIndex; // current index of the timer
        Dictionary<unsigned int, Timer> m_timers; // dictionary of timers
    };
}


#endif //TIMEMANAGER_H
