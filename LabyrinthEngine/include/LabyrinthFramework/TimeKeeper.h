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
    struct TimeKeeper
    {
    public:
        TimeKeeper();
        unsigned int GetTimerKey() const {return m_timerKey;}
    private:
        unsigned int m_timerKey;
        static unsigned int m_timerKeyCounter;
        static unsigned int GetNextTimerKey() {return ++m_timerKeyCounter;}
    };

    struct TimerHandlerHash
    {
    public:
        std::size_t operator()(const TimeKeeper& a_timerHandler) const // hash function for the timer handler that will be used in the dictionary
        {
            return a_timerHandler.GetTimerKey();
        }
    };

    bool operator==(const TimeKeeper& a_timerHandler1, const TimeKeeper& a_timerHandler2); // operator overloading for the timer handler

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
        void RemoveTimer(TimeKeeper a_timerHandler);

        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        template <typename ClassName>
        TimeKeeper SetTimer(Weak<Object> a_weakObject, void (ClassName::*a_function)(), float a_time, bool a_repeat = false)
        {
            TimeKeeper m_currentIndex{}; // create a timer handler
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
        Dictionary<TimeKeeper, Timer, TimerHandlerHash> m_timers; // dictionary of timers
    };
}


#endif //TIMEMANAGER_H
