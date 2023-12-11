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
        Timer(Wptr<Object> a_weakObject, std::function<void()> a_function, float a_time, bool a_repeat);
        void Update(float a_deltaTime);
        bool IsFinished() const;
        void SetToFinish() {m_bIsFinished = true;}
    private:
        std::pair<Wptr<Object>, std::function<void()>> m_function;
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

        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        template <typename ClassName>
        void SetTimer(Wptr<Object> a_weakObject, void (ClassName::*a_function)(), float a_time, bool a_repeat = false)
        {
            m_timers.push_back(Timer(a_weakObject, [=] {(static_cast<ClassName*>(a_weakObject.lock().get())->*a_function)(); }, a_time, a_repeat));
        }

        // Getters
        static TimeManager& GetInstance();

        /* End of Setters and getters */

    protected:
        TimeManager();

    private:
        static Uptr<TimeManager> m_timeManager;
        Vec<Timer> m_timers;
    };
}


#endif //TIMEMANAGER_H
